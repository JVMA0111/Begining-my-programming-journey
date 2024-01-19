// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    char lowercaseWord[LENGTH + 1];
    for (int i = 0; word[i] !='\0'; i++)
    {
        lowercaseWord[i] = tolower(word[i]);
    }
    lowercaseWord[strlen(word)] = '\0';

    unsigned int index = hash(lowercaseWord);
    node *current = table[index];
    while(current != NULL)
    {
        if (strcasecmp(current -> word, lowercaseWord) == 0)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int sum = 0;
    for(int i = 0; word[i] !='\0'; i++)
    {
        sum += (unsigned int)word[i];
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false


bool load(const char *dictionary)
{
    // TODO
    char buffer[LENGTH + 1];

    for (int i = 0; i < N; i++)
    {
    table[i] = NULL;
    }

    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
      if (source == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    // Read each word in the file
    while (fscanf(source,"%s", buffer) != EOF) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL)
    {
        fclose(source);
        return false;
    }

    strcpy(newNode->word, buffer);

    unsigned int index = hash(buffer);

    newNode-> next = table[index];
    table[index] = newNode;
    }

    // Close the dictionary file

    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int wordCount = 0;

    // TODO: Iterate through the hash table and count the words
    for (int i = 0; i < N; i++)
    {
        // TODO: Iterate through the linked list in each bucket and count the words
        node *current = table[i];

        while (current != NULL)
        {
            current = current -> next;
            wordCount++;
        }
    }

    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *current = table[i];

        while (current != NULL)
        {
            node* temp = current;
            current = current -> next;

            free(temp);
        }
    }

return true;

}
