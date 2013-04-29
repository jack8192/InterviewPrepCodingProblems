/*
  Print one or more verbs depending on value of parameter
  E.g.
      Print Fizz if value is divisible by 3
	  Print Bizz if value is divisible by 5
	  Otherwise print the value itself


*/
#include <stdio.h>
#include <stdlib.h>

#include "BizzFizz.h"

void BizzFizz(int n) {

  //
  // define ints for storing a boolean, enumerated, result
  //
  int n3, n5;

  //
  // Determine if n is divisible by 3 and/or 5
  //
  n3 = (n%3 == 0) ? true : false;
  n5 = (n%5 == 0) ? true : false;

  if (n3 || n5) {

    if (n3) {printf("Fizz\n");}
    if (n5) {printf("Bizz\n");}

  } else {
    printf ("%d\n",n);

  } //endif

} // endfunction
