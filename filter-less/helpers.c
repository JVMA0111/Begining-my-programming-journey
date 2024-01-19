#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int grayscale = round((float) (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);

            // Update pixel values
            image[i][j].rgbtRed = grayscale;
            image[i][j].rgbtGreen = grayscale;
            image[i][j].rgbtBlue = grayscale;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap pixels
            int tmp_red = image[i][j].rgbtRed;
            int tmp_green = image[i][j].rgbtGreen;
            int tmp_blue = image[i][j].rgbtBlue;

            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][width - 1 - j].rgbtRed = tmp_red;
            image[i][width - 1 - j].rgbtBlue = tmp_blue;
            image[i][width - 1 - j].rgbtGreen = tmp_green;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int min_i = fmax(0, i - 1);
            int max_i = fmin(height - 1, i + 1);
            int min_j = fmax(0, j - 1);
            int max_j = fmin(width - 1, j + 1);

            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;

            for (int x = min_i; x <= max_i; x++)
            {
                for (int y = min_j; y <= max_j; y++)
                {
                    sumRed += copy[x][y].rgbtRed;
                    sumGreen += copy[x][y].rgbtGreen;
                    sumBlue += copy[x][y].rgbtBlue;
                }
            }

            int count = (max_i - min_i + 1) * (max_j - min_j + 1);

            image[i][j].rgbtRed = round((float) sumRed / count);
            image[i][j].rgbtGreen = round((float) sumGreen / count);
            image[i][j].rgbtBlue = round((float) sumBlue / count);
        }
    }
}
