#include <stdio.h>

#include "game.h"
#include "car.h" // Modules need to import car header to make use of car_table

#include <typeinfo>


/**
   This module makes use of the cars.  A forward declaration is used in game.h. Then the car header is imported.
   Any module that needs to make use of the car_table needs to import that header.  This approach forces modules to 
   explicitly define their dependencies.
**/

#define CAR_TRAITS( type, car ) ( (type) == 1) ? \
                           static_cast<automatic_traits_type *>(car_table[(car)].traits) : \
                           static_cast<car_traits_type *>(car_table[(car)].traits) 
			   

int module2_main() {
    int car;

    car = car_lookup("Porsche");
    printf("%s is painted %s\n",car_table[car].name, car_table[car].traits->color);

    int car2 = car_lookup("Toyota");
    printf("%s has a top speed of %d\n",car_table[car2].name, static_cast<automatic_traits_type *>(car_table[car2].traits)->top_speed);

    int car3 = car_lookup("Honda");
    int type = car_table[car3].type;

    printf("%d type", type);
    printf("type: %s \n", typeid(static_cast<automatic_traits_type *>(car_table[car3].traits)).name() );
    printf("type: %s \n", typeid(CAR_TRAITS(type,car3)).name() );
    //printf("%s has a top speed of %d\n",car_table[car3].name, CAR_TRAITS(type,car3)->top_speed);
}

