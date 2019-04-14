#include <memory>

struct car_traits_type;

struct output_type {
    double a =   1.0;
    double aa =  1.0;
    double aaa = 1.0;
};

struct upgrade_type {
    double a =   1.0;
    double aa =  1.0;
    double aaa = 1.0;
};

struct car_traits_type {
    const char * color = nullptr;
    upgrade_type upgrade[2] = {};
    int top_speed = 35;
    output_type output = {2.0, 2.0, 2.0};
};

struct car_type {
    const char * name;
    car_traits_type traits;
};


