#ifndef ARITHTYPE
// define this to a number between 0 and 4
#define ARITHTYPE 2
#endif

#if ARITHTYPE == 0
typedef signed char mysint;
typedef unsigned char myuint;
#elif ARITHTYPE == 1
typedef short mysint;
typedef unsigned short myuint;
#elif ARITHTYPE == 2
typedef int mysint;
typedef unsigned int myuint;
#elif ARITHTYPE == 3
typedef long mysint;
typedef unsigned long myuint;
#elif ARITHTYPE == 4
typedef long long mysint;
typedef unsigned long long myuint;
#else
#error "Unknown ARITHTYPE"
#endif

/** Return the value of @x + @y using saturating unsigned addition. */
myuint sat_unsigned_add(myuint x, myuint y);

/** Return the value of @x - @y using saturating unsigned subtraction. */
myuint sat_unsigned_sub(myuint x, myuint y);

/** Return the value of @x + @y using saturating signed addition. */
mysint sat_signed_add(mysint x, mysint y);

/** Return the value of @x - @y using saturating signed subtraction. */
mysint sat_signed_sub(mysint x, mysint y);
