#pragma once
#include "Transportation.h"
#include <limits>

class PassengerTransportation : public Transportation {
private:
    int seatsAvailable;
    int seatsSold;

public:
    PassengerTransportation() : seatsAvailable(0), seatsSold(0) {}

    void inputDetails() override {
        Transportation::inputDetails();

        while (true) {
            cout << "Enter available seats: ";
            cin >> seatsAvailable;
            if (cin.fail() || seatsAvailable <= 0) {
                cout << "Invalid input. Seats must be a positive integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter seats sold: ";
            cin >> seatsSold;
            if (cin.fail() || seatsSold < 0 || seatsSold > seatsAvailable) {
                cout << "Invalid input. Sold seats must be between 0 and available seats." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }
    }

    void printDetails() const override {
        Transportation::printDetails();
        cout << "Seats available: " << seatsAvailable << endl;
        cout << "Seats sold: " << seatsSold << endl;
    }
};
