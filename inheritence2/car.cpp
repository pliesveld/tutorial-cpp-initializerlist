#include <stdio.h>
#include <vector>
#include <memory>

#include "car.h"
#include "game.h"

std::vector<car_type> car_table = {
    {"Honda",   A, new automatic_traits_type{"blue"}     },
    {"Porsche", U, new car_traits_type{"green"}          },
    {"Toyota",  A, new automatic_traits_type{"blue", 65} },
    { nullptr,  0, nullptr                               }
};

int car_lookup(const char* name) {
    for(int sn = 0; sn < car_table.size(); sn++) {
        if (car_table[sn].name == NULL)
            break;
        if (LOWER (name[0]) == LOWER (car_table[sn].name[0])
            && !str_prefix (name, car_table[sn].name))
            return sn;
    }
    return -1;
}


