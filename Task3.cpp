//Task 3 :- Develop a program that simulates a movie ticket booking system.
//Allow users to view movie listings, select seats, make bookings,
//and calculate the total cost. Consider implementing seat
//availability and seat selection validation.

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

using namespace std;

const int NUM_ROWS = 5;
const int SEATS_PER_ROW = 10;
const double TICKET_PRICE = 10.0;


vector<vector<bool>> seatAvailability(NUM_ROWS, vector<bool>(SEATS_PER_ROW, true));


map<pair<int, int>, int> userBookings;

void displaySeatMap() {
    cout << "   ";
    for (int i = 1; i <= SEATS_PER_ROW; ++i) {
        cout << setw(3) << i;
    }
    cout << endl;

    for (int row = 0; row < NUM_ROWS; ++row) {
        cout << setw(2) << (row + 1) << " ";
        for (int seat = 0; seat < SEATS_PER_ROW; ++seat) {
            if (seatAvailability[row][seat]) {
                cout << "  O";
            } else {
                cout << "  X";
            }
        }
        cout << endl;
    }
}

bool isSeatAvailable(int row, int seat) {
    return seatAvailability[row][seat];
}

void bookSeat(int row, int seat) {
    seatAvailability[row][seat] = false;
}

int main() {
    char choice;
    do {
        int row, seat;
        cout << "Movie Ticket Booking System" << endl;
        cout << "1. View Movie Listings" << endl;
        cout << "2. Book a Ticket" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Movie Listings:" << endl;
                
                break;
            case '2':
                displaySeatMap();
                cout << "Enter row number: ";
                cin >> row;
                cout << "Enter seat number: ";
                cin >> seat;

                if (row >= 1 && row <= NUM_ROWS && seat >= 1 && seat <= SEATS_PER_ROW) {
                    if (isSeatAvailable(row - 1, seat - 1)) {
                        bookSeat(row - 1, seat - 1);
                        userBookings[make_pair(row - 1, seat - 1)] = 1;
                        cout << "Seat booked successfully!" << endl;
                    } else {
                        cout << "Sorry, the selected seat is not available." << endl;
                    }
                } else {
                    cout << "Invalid row or seat number." << endl;
                }
                break;
            case '3':
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '3');

    return 0;
}
