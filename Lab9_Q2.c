#include <stdio.h>

void applyDiscount(float *prices, int size, float *total) {
    for (int i = 0; i < size; i++) {
        if (*(prices + i) < 1000)
            *(prices + i) -= *(prices + i) * 0.10; 
        else if (*(prices + i) <= 5000)
            *(prices + i) -= *(prices + i) * 0.15; 
        else
            *(prices + i) -= *(prices + i) * 0.25; 

        *total += *(prices + i); 
    }
}

int main() {
    float prices[5];
    float total = 0.0;
    int size = 5;

    printf("Enter prices of 5 products:\n");
    for (int i = 0; i < size; i++) {
        printf("Product %d price: ", i + 1);
        scanf("%f", &prices[i]);
    }

    applyDiscount(prices, size, &total);

    printf("\nPrices after discount:\n");
    for (int i = 0; i < size; i++) {
        printf("Product %d: Rs. %.2f\n", i + 1, *(prices + i));
    }

    printf("\nTotal amount after discounts: Rs. %.2f\n", total);

    return 0;
}

