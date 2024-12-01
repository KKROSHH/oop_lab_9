#pragma once
#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Transportation {
protected:
    string vehicle;
    int transportationID;
    int transportationTime;
    int breakTime;
    string departure;
    string destination;

public:
    Transportation() : vehicle("None"), transportationID(0), transportationTime(0), breakTime(0), departure("None"), destination("None") {}

    virtual void inputDetails() {
        while (true) {
            cout << "Enter vehicle: ";
            getline(cin, vehicle);
            if (vehicle.empty()) {
                cout << "Vehicle cannot be empty. Please try again." << endl;
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter transportation ID: ";
            cin >> transportationID;
            if (cin.fail() || transportationID <= 0) {
                cout << "Invalid input. ID must be a positive integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter transportation time (minutes): ";
            cin >> transportationTime;
            if (cin.fail() || transportationTime <= 0) {
                cout << "Invalid input. Time must be a positive integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter break time (minutes): ";
            cin >> breakTime;
            if (cin.fail() || breakTime < 0 || breakTime >= transportationTime) {
                cout << "Invalid input. Break time must be a non-negative integer and less than transportation time." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера
        while (true) {
            cout << "Enter departure city: ";
            getline(cin, departure);
            if (departure.empty()) {
                cout << "Departure city cannot be empty. Please try again." << endl;
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter destination city: ";
            getline(cin, destination);
            if (destination.empty()) {
                cout << "Destination city cannot be empty. Please try again." << endl;
            } else {
                break;
            }
        }
    }

    int remainTime() const {
        return transportationTime - breakTime;
    }

    virtual void printDetails() const {
        cout << "Vehicle: " << vehicle << endl;
        cout << "Transportation ID: " << transportationID << endl;
        cout << "Transportation time: " << transportationTime << " minutes" << endl;
        cout << "Break time: " << breakTime << " minutes" << endl;
        cout << "Departure city: " << departure << endl;
        cout << "Destination city: " << destination << endl;
        cout << "Remaining time: " << remainTime() << " minutes" << endl;
    }
};
