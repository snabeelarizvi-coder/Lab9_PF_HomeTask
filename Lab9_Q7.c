#include <stdio.h>

#define VEHICLES 5
#define DAYS 7

void calculateAverage(float (*mileage)[DAYS], float *avg, int size);
void compactReport(float *avg, int size);
void detailedReport(float *avg, int size);
const char* getCategory(float avg);

int main() {
    float mileage[VEHICLES][DAYS];
    float avgMileage[VEHICLES];
    int choice;

    printf("Enter mileage (km/l) for %d vehicles over %d days:\n", VEHICLES, DAYS);
    for (int i = 0; i < VEHICLES; i++) {
        printf("\nVehicle %d:\n", i + 1);
        for (int j = 0; j < DAYS; j++) {
            printf("  Day %d mileage: ", j + 1);
            scanf("%f", (*(mileage + i) + j));
        }
    }

    calculateAverage(mileage, avgMileage, VEHICLES);

    void (*reportPtr)(float *, int);

    printf("\nSelect report format:\n");
    printf("1. Compact Report\n");
    printf("2. Detailed Report\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        reportPtr = compactReport;
    else
        reportPtr = detailedReport;

    printf("\n========== Vehicle Mileage Report ==========\n");
    reportPtr(avgMileage, VEHICLES);

    return 0;
}

void calculateAverage(float (*mileage)[DAYS], float *avg, int size) {
    for (int i = 0; i < size; i++) {
        float sum = 0;
        for (int j = 0; j < DAYS; j++) {
            sum += *(*(mileage + i) + j); 
        }
        *(avg + i) = sum / DAYS;
    }
}

const char* getCategory(float avg) {
    if (avg >= 18)
        return "Efficient";
    else if (avg >= 12)
        return "Moderate";
    else
        return "Poor";
}


void compactReport(float *avg, int size) {
    for (int i = 0; i < size; i++) {
        printf("Vehicle %d: %s\n", i + 1, getCategory(*(avg + i)));
    }
}


void detailedReport(float *avg, int size) {
    for (int i = 0; i < size; i++) {
        printf("Vehicle %d:\n", i + 1);
        printf("  Average Mileage: %.2f km/l\n", *(avg + i));
        printf("  Category: %s\n", getCategory(*(avg + i)));
        printf("--------------------------------------\n");
    }
}


