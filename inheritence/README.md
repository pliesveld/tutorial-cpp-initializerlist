I have an array car_table defined as follows:


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

	struct car_type car_table[MAX_CARS] = {
	    {"Honda",   A, new automatic_traits_type{"blue"}     },
	    {"Porsche", U, new car_traits_type{"green"}          },
	    {"Toyota",  A, new automatic_traits_type{"blue", 65} },
	    { nullptr,  0, nullptr                               }
	};


In the driver code, I type cast the traits pointer to the derived class:

	car = car_lookup("Porsche");
	printf("%s is painted %s\n",car_table[car].name, car_table[car].traits->color);

	int car2 = car_lookup("Toyota");
	printf("%s has a top speed of %d\n",car_table[car2].name, static_cast<automatic_traits_type *>(car_table[car2].traits)->top_speed);


This works fine, and executes.

I would like to create a utility function or macro to perform the type casting so that my driver code is less verbose.  I tried using an enum to capture the type, so that the appropriate type casts can be done in the driver code, ie:


	#define CAR_TRAITS( type, car ) (( (type) == 1) ? \
	   static_cast<automatic_traits_type *>(car_table[(car)].traits) : \
	   static_cast<car_traits_type *>(car_table[(car)].traits)) 

	int car3 = car_lookup("Honda");
	int type = car_table[car3].type;

	printf("%d type", type);
	printf("%s has a top speed of %d\n",car_table[car3].name, CAR_TRAITS(type,car3)->top_speed);


However, I am getting the follow compile error:

	module2.cpp:30:86: error: ‘struct car_traits_type’ has no member named ‘top_speed’
	     printf("%s has a top speed of %d\n",car_table[car3].name, CAR_TRAITS(type,car3)->top_speed);


I am expecting the evaluation of the CAR_TRAITS macro to type cast the expression to `automatic_traits_type *`.

Any ideas on why this is not happening, or a better apporach to pursue are welcome.

