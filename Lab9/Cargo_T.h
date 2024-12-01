#pragma once
#include "Transportation.h"
#include <limits> // Для обробки некоректного вводу

class CargoTransportation : public Transportation {
private:
    int cargoWeight;
    int cargoValue;
    string cargoType;

public:
    CargoTransportation() : cargoWeight(0), cargoValue(0), cargoType("None") {}

    void inputDetails() override {
        Transportation::inputDetails();

        while (true) {
            cout << "Enter cargo weight (kg): ";
            cin >> cargoWeight;
            if (cin.fail() || cargoWeight <= 0) {
                cout << "Invalid input. Weight must be a positive integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        while (true) {
            cout << "Enter cargo value: ";
            cin >> cargoValue;
            if (cin.fail() || cargoValue < 0) {
                cout << "Invalid input. Value must be a non-negative integer." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищення буфера
        while (true) {
            cout << "Enter cargo type: ";
            getline(cin, cargoType);
            if (cargoType.empty()) {
                cout << "Cargo type cannot be empty. Please try again." << endl;
            } else {
                break;
            }
        }
    }

    void printDetails() const override {
        Transportation::printDetails();
        cout << "Cargo weight: " << cargoWeight << " kg" << endl;
        cout << "Cargo value: " << cargoValue << endl;
        cout << "Cargo type: " << cargoType << endl;
    }
};
