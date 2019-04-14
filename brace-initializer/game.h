#define LOWER(c)        ((c) >= 'A' && (c) <= 'Z' ? (c)+'a'-'A' : (c))

/* db.c */
bool     str_cmp             ( const char *astr, const char *bstr );
bool     str_prefix          ( const char *astr, const char *bstr );


/* car.c */
//#define MAX_CARS 4
struct car_type;

extern struct car_type car_table[];

/* module1.c */
int module1_main();

/* module2.c */
int module2_main();
