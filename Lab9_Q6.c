#include <stdio.h>

struct Book {
    float price;
    int stock;
    float totalValue;
};

void calculateTotalValue(struct Book *b, int size);
float applyDiscount(struct Book *b);
void displayBooks(struct Book *b, int size);

int main() {
    struct Book books[5];
    int size = 5;

    printf("Enter details of 5 books:\n");
    for (int i = 0; i < size; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Enter price: ");
        scanf("%f", &books[i].price);
        printf("Enter number of copies in stock: ");
        scanf("%d", &books[i].stock);
    }

    calculateTotalValue(books, size);

    float (*discountPtr)(struct Book *);
    discountPtr = applyDiscount;

    printf("\n========== Library Book Summary ==========\n");
    for (int i = 0; i < size; i++) {
        float discountedValue = discountPtr(&books[i]);
        printf("Book %d:\n", i + 1);
        printf(" Price: Rs. %.2f\n", books[i].price);
        printf(" Stock: %d\n", books[i].stock);
        printf(" Total Value (before discount): Rs. %.2f\n", books[i].totalValue);
        printf(" Total Value (after discount):  Rs. %.2f\n", discountedValue);
        printf("------------------------------------------\n");
    }

    return 0;
}

void calculateTotalValue(struct Book *b, int size) {
    for (int i = 0; i < size; i++) {
        (b + i)->totalValue = (b + i)->price * (b + i)->stock;
    }
}

float applyDiscount(struct Book *b) {
    float discountedValue;

    if (b->stock < 3) {
        discountedValue = b->totalValue;  
    } 
    else if (b->stock <= 5) {
        discountedValue = b->totalValue * 0.90;  
    } 
    else {
        discountedValue = b->totalValue * 0.80; 
    }

    return discountedValue;
}


