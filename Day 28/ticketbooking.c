#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 10

struct Ticket {
    int seatNo;
    char passengerName[50];
    int isBooked;
};

int main() {
    struct Ticket seats[TOTAL_SEATS];
    int choice;

    // initialize all seats as available
    for (int i = 0; i < TOTAL_SEATS; i++) {
        seats[i].seatNo = i + 1;
        seats[i].isBooked = 0;
        strcpy(seats[i].passengerName, "-");
    }

    do {
        printf("\n----- TICKET BOOKING SYSTEM -----\n");
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. Display Seat Status\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int seatNo;
                printf("Enter seat number (1-%d): ", TOTAL_SEATS);
                scanf("%d", &seatNo);

                if (seatNo < 1 || seatNo > TOTAL_SEATS) {
                    printf("Invalid seat number.\n");
                } else if (seats[seatNo - 1].isBooked) {
                    printf("Seat already booked.\n");
                } else {
                    printf("Enter passenger name: ");
                    scanf(" %[^\n]s", seats[seatNo - 1].passengerName);
                    seats[seatNo - 1].isBooked = 1;
                    printf("Ticket booked successfully for seat %d.\n", seatNo);
                }
                break;
            }

            case 2: {
                int seatNo;
                printf("Enter seat number to cancel: ");
                scanf("%d", &seatNo);

                if (seatNo < 1 || seatNo > TOTAL_SEATS) {
                    printf("Invalid seat number.\n");
                } else if (!seats[seatNo - 1].isBooked) {
                    printf("Seat is not booked.\n");
                } else {
                    seats[seatNo - 1].isBooked = 0;
                    strcpy(seats[seatNo - 1].passengerName, "-");
                    printf("Booking cancelled for seat %d.\n", seatNo);
                }
                break;
            }

            case 3:
                printf("\nSeat No\tStatus\t\tPassenger\n");
                for (int i = 0; i < TOTAL_SEATS; i++)
                    printf("%d\t%s\t%s\n", seats[i].seatNo,
                           seats[i].isBooked ? "Booked" : "Available",
                           seats[i].passengerName);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}