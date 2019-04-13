Organization of Components
====

## _How do store a set of attributes of a common type_

### struct definition in header

##`car.h`
```
struct car_type {
    char * name;
    int top_speed;
    int wheels;
};
```
### The table of values is stored in a single translational unit
##`car.cpp`

```
#include "car.h"
car_type car_table[] = {
    {"Honda",   85,  4  },
    {"Porsche", 165, 4  },
    {"Semi",    65,  18 },
};
```

### Common header file has forward declaration of type
##`game.h`
```
#define MAX_CARS 4   
struct car_type;
extern const struct car_type car_table[MAX_CARS];
```

### Modules that access the `car_table` must explicitly import the car header
```
#include <stdio.h>

#include "game.h"
#include "car.h"

int module2_main() {
    printf(car_table[1].name);
    return 0;
}

```

### And Inversely, modules that don't access the `car_table` should not import the car header:

```
#include <stdio.h>
#include "game.h"

int module1_main() {
//    printf(car_table[1].name); // uncommenting this line will error
    return 0;
}
```

### Lookup function to find the index of a car based on name

```
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
```
##### Usage:

```
    int car = car_lookup("Semi");
    printf("%s has %d wheels\n",car_table[car].name, car_table[car].wheels);
```
