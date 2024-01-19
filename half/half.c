#include <stdio.h>
#include <cs50.h>

// Function to calculate the total amount including tax and tip
float calculateTotal(float billAmount, float taxPercent, int tipPercent) {
    // Convert tax and tip percentages to decimal values
    float tax = billAmount * (taxPercent / 100);
    float tip = billAmount * (tipPercent / 100);

    // Calculate the total amount
    float totalAmount = billAmount + tax + tip;

    return totalAmount;
}

// Function to split the total amount between two people
float splitBill(float totalAmount, int numberOfPeople) {
    // Ensure the number of people is at least 1 to avoid division by zero
    if (numberOfPeople <= 0) {
        printf("Invalid number of people\n");
        return 0.0;
    }

    // Calculate the amount each person owes
    float amountPerPerson = totalAmount / numberOfPeople;

    return amountPerPerson;
}

int main(void) {
    // Example usage with CS50 library for input
    float billAmount = get_float("Enter the bill amount: $");
    float taxPercent = get_float("Enter the tax percentage: ");
    int tipPercent = get_int("Enter the tip percentage: ");
    int numberOfPeople = get_int("Enter the number of people: ");

    // Calculate the total amount
    float totalAmount = calculateTotal(billAmount, taxPercent, tipPercent);

    // Split the bill between two people
    float amountPerPerson = splitBill(totalAmount, numberOfPeople);

    // Display the result
    printf("Total amount: $%.2f\n", totalAmount);
    printf("Each person owes: $%.2f\n", amountPerPerson);

    return 0;
}
