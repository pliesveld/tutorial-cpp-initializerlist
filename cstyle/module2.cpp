#include <stdio.h>

#include "game.h"
#include "car.h" // Modules need to import car header to make use of car_table

/**
   This module makes use of the cars.  A forward declaration is used in game.h. Then the car header is imported.
   Any module that needs to make use of the car_table needs to import that header.  This approach forces modules to 
   explicitly define their dependencies.
**/

int module2_main() {
    printf("%s has %d wheels\n", car_table[1].name, car_table[1].wheels);

    int car = car_lookup("Semi");
    printf("%s has %d wheels\n",car_table[car].name, car_table[car].wheels);
    return 0;
}

