#include <stdio.h>

#include "car.h"
#include "game.h"

struct car_type car_table[MAX_CARS] = {
    {"Honda",   A, new automatic_traits_type{"blue"}     },
    {"Porsche", U, new car_traits_type{"green"}          },
    {"Toyota",  A, new automatic_traits_type{"blue", 65} },
    { nullptr,  0, nullptr                               }
};

int car_lookup(const char* name) {
    for(int sn = 0; sn < MAX_CARS; sn++) {
        if (car_table[sn].name == NULL)
            break;
        if (LOWER (name[0]) == LOWER (car_table[sn].name[0])
            && !str_prefix (name, car_table[sn].name))
            return sn;
    }
    return -1;
}

/*
template<typename T>
void* car_traits_lookup(int id) {

    switch(car_table[id].type) {
	case A:
		return static_cast<automatic_traits_type *>(car_table[id].traits);
		break;
	default:
		return static_cast<car_traits_type *>(car_table[id].traits);
		break;
    }
}


void* car_traits_lookup(int TYPE) {
	return static_cast<car_traits_type *>(car_table[0].traits);
}


*/
/*
template<typename T>
T* car_traits_lookup(int id) {

    switch(car_table[id].type) {
	case A:
		return static_cast<automatic_traits_type>(car_table[id].traits);
		break;
	default:
		return static_cast<car_traits_type>(car_table[id].traits);
		break;
    }
}
*/

