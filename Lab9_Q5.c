#include <stdio.h>

#define STUDENTS 30
#define DAYS 5

void analyzeAttendance(int (*attendance)[DAYS], int students);

int main() {
    int attendance[STUDENTS][DAYS];

    printf("Enter attendance data (1 = Present, 0 = Absent)\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("\nStudent %d:\n", i + 1);
        for (int j = 0; j < DAYS; j++) {
            printf(" Day %d: ", j + 1);
            scanf("%d", (*(attendance + i) + j));
        }
    }

    analyzeAttendance(attendance, STUDENTS);

    return 0;
}

void analyzeAttendance(int (*attendance)[DAYS], int students) {
    int defaulters = 0;
    float percentage;

    printf("\n===== Attendance Report =====\n");

    for (int i = 0; i < students; i++) {
        int totalPresent = 0;

        for (int j = 0; j < DAYS; j++) {
            totalPresent += *(*(attendance + i) + j);
        }

        percentage = (totalPresent / (float)DAYS) * 100;

        if (percentage >= 90)
            printf("Student %2d: %.2f%% - Good\n", i + 1, percentage);
        else if (percentage >= 75)
            printf("Student %2d: %.2f%% - Average\n", i + 1, percentage);
        else {
            printf("Student %2d: %.2f%% - Poor\n", i + 1, percentage);
            defaulters++;
        }
    }

    printf("\nTotal Defaulters (attendance < 75%%): %d\n", defaulters);
}


