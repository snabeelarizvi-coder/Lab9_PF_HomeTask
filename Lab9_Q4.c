#include <stdio.h>

void analyzeRainfall(float *rain, int size, float *avg, int *maxDay, float *maxRain);

int main() {
    float rainfall[7];
    float average, maxRain;
    int maxDay;
    int countAboveAvg = 0;

    char *days[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    printf("Enter rainfall data (in mm) for 7 days:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s: ", days[i]);
        scanf("%f", &rainfall[i]);
    }

    analyzeRainfall(rainfall, 7, &average, &maxDay, &maxRain);

    printf("\nAverage Rainfall: %.2f mm\n", average);
    printf("Maximum Rainfall: %.2f mm on %s\n", maxRain, days[maxDay]);

    for (int i = 0; i < 7; i++) {
        if (*(rainfall + i) > average)
            countAboveAvg++;
    }

    if (countAboveAvg > 3)
        printf("\nIt's a Rainy Week \n");
    else
        printf("\nIt's a Normal Week \n");

    return 0;
}

void analyzeRainfall(float *rain, int size, float *avg, int *maxDay, float *maxRain) {
    float sum = 0;
    *maxRain = *rain;  
    *maxDay = 0;

    for (int i = 0; i < size; i++) {
        sum += *(rain + i);  
        if (*(rain + i) > *maxRain) {
            *maxRain = *(rain + i);
            *maxDay = i;  
        }
    }

    *avg = sum / size;
}


