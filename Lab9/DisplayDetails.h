#include "Cargo_T.h"
#include "Passanger_T.h"
#pragma once

class DisplayDetails {
public:
    void showDetails(Transportation &t) {
        t.printDetails();
    }
};
