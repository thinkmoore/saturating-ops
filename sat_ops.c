#include "sat_ops.h"

#define MYUINT_MAX ((myuint)~((myuint)0))
#define MYUINT_MIN 0
#define TOPBIT (MYUINT_MAX >> 1)
#define MYSINT_MAX ((mysint)TOPBIT)
#define MYSINT_MIN ((mysint)~TOPBIT)

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
  if (x > (MYUINT_MAX - y))
      return MYUINT_MAX;
  return x + y;
}

/** Return the value of @x - @y using saturating unsigned subtraction. */
/*@
  behavior no_overflow:
    assumes x - y >= MYUINT_MIN;
    ensures \result == x - y;
  behavior saturate:
    assumes x - y < MYUINT_MIN;
    ensures \result == MYUINT_MIN;
*/
myuint sat_unsigned_sub(myuint x, myuint y) {
  if (x < y)
    return MYUINT_MIN;
  return x - y;
}

/** Return the value of @x + @y using saturating signed addition. */
/*@
  behavior no_overflow:
    assumes x + y <= MYSINT_MAX && x + y >= MYSINT_MIN;
    ensures \result == x + y;
  behavior saturate_max:
    assumes x + y > MYSINT_MAX;
    ensures \result == MYSINT_MAX;
  behavior saturate_min:
    assumes x + y < MYSINT_MIN;
    ensures \result == MYSINT_MIN;
*/
mysint sat_signed_add(mysint x, mysint y) {
  if (x > 0 && y > 0 && x > (MYSINT_MAX - y))
    return MYSINT_MAX;
  if (x < 0 && y < 0 && x < (MYSINT_MIN - y))
    return MYSINT_MIN;
  return x + y;
}

/** Return the value of @x - @y using saturating signed subtraction. */
/*@
  behavior no_overflow:
    assumes x - y <= MYSINT_MAX && x - y >= MYSINT_MIN;
    ensures \result == x - y;
  behavior saturate_max:
    assumes x - y > MYSINT_MAX;
    ensures \result == MYSINT_MAX;
  behavior saturate_min:
    assumes x - y < MYSINT_MIN;
    ensures \result == MYSINT_MIN;
*/
mysint sat_signed_sub(mysint x, mysint y) {
  if (x < 0 && y > 0 && x < (MYSINT_MIN + y))
    return MYSINT_MIN;
  if (x >= 0 && y < 0 && x > (MYSINT_MAX + y))
    return MYSINT_MAX;
  return x - y;
}
