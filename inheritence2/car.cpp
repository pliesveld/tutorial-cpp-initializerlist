#include <stdio.h>
#include <memory>

struct car_traits_type;

struct upgrade_type {
    double a =   1.0;
    double aa =  1.0;
    double aaa = 1.0;
};

struct car_traits_type {
    const char * color = nullptr;
    upgrade_type upgrade[2] = {};
    int top_speed = 35;
};

struct car_type {
    const char * name;
    car_traits_type traits;
};

int car_lookup(const char* name);

#include "game.h"

struct car_type car_table[] = {
    {"Honda",   car_traits_type{"blue",{{2.5, 2.5, 2.5},{}}, 15}        },
    {"Porsche", car_traits_type()                                       },
    {"Toyota",  car_traits_type{"blue"}                                 },
    {"Ford",    car_traits_type{"blue", {}, 75}                         },
    {"Ford2",   car_traits_type{"blue", upgrade_type{2.0}, 75}          },
    {"Ford3",   car_traits_type{"blue", {2.0}, 75}                      },
    { nullptr, nullptr                                                  }
};

int car_lookup(const char* name) {
    for(int sn = 0; ; sn++) {
        if (car_table[sn].name == NULL)
            break;
        if (LOWER (name[0]) == LOWER (car_table[sn].name[0])
            && !str_prefix (name, car_table[sn].name))
            return sn;
    }
    return -1;
}


