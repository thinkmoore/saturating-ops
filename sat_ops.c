#include "sat_ops.h"

#include <stdint.h>

#define MYUINT_MAX ((myuint)~0UL)

/*@
  behavior no_overflow:
    assumes a + b <= UINT32_MAX;
    ensures \result == a+b;
  behavior saturate:
    assumes a+b > UINT32_MAX;
    ensures \result == UINT32_MAX;
*/
uint32_t my_add(uint32_t a, uint32_t b) {
  uint32_t r = a + b;
  if (r < a)
    return UINT32_MAX;
  return r;
}

/** Return the value of @x + @y using saturating unsigned addition. */
/*@
  behavior no_overflow:
    assumes x + y <= MYUINT_MAX;
    ensures \result == x + y;
  behavior saturate:
    assumes x + y > MYUINT_MAX;
    ensures \result == MYUINT_MAX;
*/
myuint sat_unsigned_add(myuint x, myuint y) {
  myuint ret = x + y;
  if (ret < x) {
    return MYUINT_MAX;
  } else {
    return ret;
  }
}

/** Return the value of @x - @y using saturating unsigned subtraction. */
/*
myuint sat_unsigned_sub(myuint x, myuint y) {
  myuint ret = x - y;
  if (ret > x) {
    return 0;
  } else {
    return ret;
  }
}
*/

/** Return the value of @x + @y using saturating signed addition. */
/*
mysint sat_signed_add(mysint x, mysint y) {
  return x + y;
}
*/

/** Return the value of @x - @y using saturating signed subtraction. */
/*
mysint sat_signed_sub(mysint x, mysint y) {
  return x - y;
}
*/
