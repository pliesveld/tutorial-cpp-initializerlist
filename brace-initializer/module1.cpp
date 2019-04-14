#include <stdio.h>

/**
    Pretend this module has no direct interactions with cars.  Including the car
    definitions into module would cause a leaky abstraction.  This separation
    guarentees that the if car.h or car.cpp were to change, then this module would
    be isolated from those changes.
**/


#include "game.h"

int module1_main() {
//    printf(car_table[1].name); // uncommenting this line will error
    return 0;
}

