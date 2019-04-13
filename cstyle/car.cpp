#include <stdio.h>

#include "car.h"
#include "game.h"

struct car_type car_table[MAX_CARS] = {
    {"Honda",   85,  4  },
    {"Porsche", 165, 4  },
    {"Semi",    65,  18 },
    { nullptr,  0,   0  },
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
