/*
  Print one or more verbs depending on value of parameter
  E.g.
      Print Fizz if value is divisible by 3
	  Print Bizz if value is divisible by 5
	  Otherwise print the value itself


*/
#include <stdio.h>

//
// Module Under Test
//
#include "BizzFizz.c"

void main() {

  int n = 15;
  printf ("\nExpecting: Fizz Bizz\n");
  BizzFizz(n);

  n = 4;
  printf ("\nExpecting: %d\n",n);
  BizzFizz(n);

  n = 18;
  printf ("\nExpecting: Fizz\n");
  BizzFizz(n);

  n = 25;
  printf ("\nExpecting: Bizz\n");
  BizzFizz(n);

}