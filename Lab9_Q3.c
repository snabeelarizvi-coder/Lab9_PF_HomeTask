#include <stdio.h>
#include <stdlib.h>


void bookSeat(int **flights, int flightNum, int seatNum, int seatCount) {
    if (seatNum < 1 || seatNum > seatCount) {
        printf("Invalid seat number!\n");
        return;
    }
    if (flights[flightNum][seatNum - 1] == 1) {
        printf("Seat already booked!\n");
    } else {
        flights[flightNum][seatNum - 1] = 1;
        printf("Seat %d booked successfully!\n", seatNum);
    }
}

void cancelSeat(int **flights, int flightNum, int seatNum, int seatCount) {
    if (seatNum < 1 || seatNum > seatCount) {
        printf("Invalid seat number!\n");
        return;
    }
    if (flights[flightNum][seatNum - 1] == 0) {
        printf("Seat is already empty!\n");
    } else {
        flights[flightNum][seatNum - 1] = 0;
        printf("Booking for seat %d canceled.\n", seatNum);
    }
}

int countOccupied(int *flight, int seatCount) {
    int count = 0;
    for (int i = 0; i < seatCount; i++) {
        if (flight[i] == 1)
            count++;
    }
    return count;
}

int main() {
    int flightSeats[3] = {5, 7, 9}; 
    int *flights[3];                 
    for (int i = 0; i < 3; i++) {
        flights[i] = (int *)calloc(flightSeats[i], sizeof(int));  
    }

    int choice, flightNum, seatNum;
    do {
        printf("\n===== Airline Seat Booking System =====\n");
        printf("1. Book a seat\n");
        printf("2. Cancel a booking\n");
        printf("3. Display occupied seats per flight\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter flight number (1-3): ");
            scanf("%d", &flightNum);
            if (flightNum < 1 || flightNum > 3) {
                printf("Invalid flight number!\n");
                break;
            }
            printf("Enter seat number (1-%d): ", flightSeats[flightNum - 1]);
            scanf("%d", &seatNum);
            bookSeat(flights, flightNum - 1, seatNum, flightSeats[flightNum - 1]);
            break;

        case 2:
            printf("Enter flight number (1-3): ");
            scanf("%d", &flightNum);
            if (flightNum < 1 || flightNum > 3) {
                printf("Invalid flight number!\n");
                break;
            }
            printf("Enter seat number (1-%d): ", flightSeats[flightNum - 1]);
            scanf("%d", &seatNum);
            cancelSeat(flights, flightNum - 1, seatNum, flightSeats[flightNum - 1]);
            break;

        case 3:
            printf("\nOccupied seats per flight:\n");
            for (int i = 0; i < 3; i++) {
                printf("Flight %d: %d seats occupied out of %d\n",
                       i + 1, countOccupied(flights[i], flightSeats[i]), flightSeats[i]);
            }
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    for (int i = 0; i < 3; i++) {
        free(flights[i]);
    }

    return 0;
}


