#include <stdio.h>

#define MAX_MOVIES 5
#define TICKET_PRICE 100  

typedef struct {
    char movieName[50];
    int availableSeats;
} Movie;

void showMovies(Movie movies[], int movieCount) {
    printf("\nAvailable Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s - %d seats available\n", i + 1, movies[i].movieName, movies[i].availableSeats);
    }
}

void calculateAndDisplayBill(int ticketCount, const char* movieName) {
    float gstRate = 0.18;  // 18% GST
    float ticketCost = TICKET_PRICE * ticketCount;
    float gstAmount = ticketCost * gstRate;
    float totalCost = ticketCost + gstAmount;

    printf("\n--- Bill Summary ---\n");
    printf("Movie: %s\n", movieName);
    printf("Number of Tickets: %d\n", ticketCount);
    printf("Ticket Price: %.2f each\n", TICKET_PRICE);
    printf("Subtotal (Ticket Cost): %.2f\n", ticketCost);
    printf("GST (18%%): %.2f\n", gstAmount);
    printf("Total Cost (with GST): %.2f\n", totalCost);
    printf("--------------------\n");
}

// Function to book a ticket for a movie
void bookTicket(Movie movies[], int movieIndex) {
    int ticketCount;

    // Ask the user how many tickets they want to book
    printf("Enter the number of tickets you want to book: ");
    scanf("%d", &ticketCount);

    if (ticketCount <= 0) {
        printf("Invalid number of tickets. Please enter a positive number.\n");
        return;
    }

    if (movies[movieIndex].availableSeats >= ticketCount) {
        // Deduct the number of booked tickets from available seats
        movies[movieIndex].availableSeats -= ticketCount;
        printf("\nTicket(s) booked successfully for %s.\n", movies[movieIndex].movieName);
        printf("Seats remaining: %d\n", movies[movieIndex].availableSeats);

        // Calculate and display the bill summary
        calculateAndDisplayBill(ticketCount, movies[movieIndex].movieName);
    } else {
        printf("Sorry, there are not enough seats available for %s.\n", movies[movieIndex].movieName);
    }
}

int main() {
    Movie movies[MAX_MOVIES] = {
        {"Avengers: Endgame", 50},
        {"Spider-Man: No Way Home", 30},
        {"The Matrix Resurrections", 20},
        {"Inception", 40},
        {"Batman v Superman", 60}
    };

    int choice, movieIndex;

    while (1) {
        showMovies(movies, MAX_MOVIES);

        printf("\nEnter the number of the movie you want to book (1-%d) or 0 to exit: ", MAX_MOVIES);
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting the program...\n");
            break;
        }

        if (choice < 1 || choice > MAX_MOVIES) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        movieIndex = choice - 1;
        bookTicket(movies, movieIndex);
    }

    return 0;
}
