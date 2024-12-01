#include <iostream>
#include "Cargo_T.h"
#include "Passanger_T.h"
#include "DisplayDetails.h"

using namespace std;

int main() {
    CargoTransportation cargo;
    PassengerTransportation passenger;
    DisplayDetails display;

    cout << "Enter cargo transportation details:" << endl;
    cargo.inputDetails();
    cout << "\nEnter passenger transportation details:" << endl;
    passenger.inputDetails();

    cout << "\nDisplaying cargo details:" << endl;
    display.showDetails(cargo);
    cout << "\nDisplaying passenger details:" << endl;
    display.showDetails(passenger);

    return 0;
}
