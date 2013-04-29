/*
  Return the nth value of the Fibonocci series.

  Do NOT use the closed form equation (there really is one and there
  has been one since at least the 1950's!!)


*/
#include <stdio.h>
#include <stdlib.h>

int Fibonocci(int n) {

  //
  // define ints for storing the nth, nth+1 and nth+2 entries
  //
  int value1, value2, next_value;

  int nth_entry;

  value1 = 1;
  value2 = 1;

  // until defined otherwise, return an error value of -1, when n is < 0
  if (n < 0) {return -1;}

  for (nth_entry = 0; nth_entry < n; nth_entry++) {
     //
     // compute next element in series
     //
     next_value = value1 + value2;

     value1 = value2;
     value2 = next_value;

   } //endfor

   return value1;

   //
   // Note.  There is a consideration when computing very large values
   // produced by a large n that might result in an overflow.
   //
   // First, can use unsigned ints, and then use unsigned long (double word) values.
   // Finally, add code to detect an overflow and report any, if any, overflows
   // with an error code of -2.
   //

} // endfunction
