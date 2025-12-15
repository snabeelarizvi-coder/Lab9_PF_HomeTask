#include <stdio.h>

void calculateDenominations(int amount, int *denominations, int *count, int size) {
    for (int i = 0; i < size; i++) {
        *(count + i) = amount / *(denominations + i); 
        amount %= *(denominations + i);                
    }
}

int main() {
    int amount;
    int denominations[] = {5000, 1000, 500};
    int count[3] = {0};
    int size = sizeof(denominations) / sizeof(denominations[0]);

    printf("Enter withdrawal amount (in Rs): ");
    scanf("%d", &amount);


    if (amount % 50 != 0) {
        printf("Invalid amount! Amount must be a multiple of 50.\n");
        return 0;
    }


    if (amount < 500) {
        printf("Minimum withdrawal amount is Rs. 500.\n");
        return 0;
    }

    
    calculateDenominations(amount, denominations, count, size);

    
    printf("\nDenominations dispensed:\n");
    for (int i = 0; i < size; i++) {
        printf("Rs. %d notes: %d\n", denominations[i], count[i]);
    }

    return 0;
}
