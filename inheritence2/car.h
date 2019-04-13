#include <memory>

struct car_traits_type;

enum { U = 0, A = 1, M = 2 };

struct car_type {
    const char * name;
    int type;
    car_traits_type * traits;
};

struct car_traits_type {
    const char * color;
};

struct automatic_traits_type : car_traits_type {
    automatic_traits_type(const char * color) : car_traits_type{color}, top_speed{55} {}
    automatic_traits_type(const char * color, int _top_speed) : car_traits_type{color}, top_speed{_top_speed} {}
    int top_speed;
};

int car_lookup(const char* name);

void car_traits_type_lookup(car_traits_type *trait);




