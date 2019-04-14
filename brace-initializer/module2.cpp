#include <stdio.h>

#include "game.h"
#include "car.h" // Modules need to import car header to make use of car_table

#include <string.h>
#include <typeinfo>


/**
   This module makes use of the cars.  A forward declaration is used in game.h. Then the car header is imported.
   Any module that needs to make use of the car_table needs to import that header.  This approach forces modules to 
   explicitly define their dependencies.
**/


void print_car(int id);
		   

int module2_main() {

    for( int sn = 0; ; sn++) {
        if (car_table[sn].name == nullptr)
            break;
        print_car(sn);
    }
}

void print_car(int id) {
    printf("Car: %s\n", car_table[id].name);
    printf("color: %s\n", car_table[id].traits.color);

    char buf[256] = {};
    strcpy(buf, "upgrade1: ");
    char buf2[256] = {};

    struct upgrade_type upgrade1 = car_table[id].traits.upgrade[0];
    sprintf(buf2, "%f %f %f\n", upgrade1.a, upgrade1.aa, upgrade1.aaa);
    strcat(buf,buf2);

    strcpy(buf2, "upgrade2: ");
    strcat(buf,buf2);
    struct upgrade_type upgrade2 = car_table[id].traits.upgrade[1];
    sprintf(buf2, "%f %f %f\n", upgrade2.a, upgrade2.aa, upgrade2.aaa);
    strcat(buf,buf2);

    printf("%s", buf);
    printf("top speed: %d\n\n", car_table[id].traits.top_speed);
    
}
