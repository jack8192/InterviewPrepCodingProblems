/*
  Return the nth value of the Fibonocci series
  Do NOT use the closed form equation



*/
#include <stdio.h>
#include "Fibonocci_testbench.h"

//
// Module Under Test
//
#include "Fibonocci.c"

void exec_testcase(n, fn) {

   int value;

   value = Fibonocci(n);

   printf("\nThe %dth entry has a value of %d", n, value);
   (value == fn) ? printf(", test has passed") : printf(", test has NOT passed");

}

void main() {

  exec_testcase(0, 1);
  exec_testcase(1, 1);
  exec_testcase(2, 2);
  exec_testcase(3, 3);
  exec_testcase(4, 5);
  exec_testcase(5, 8);
  exec_testcase(6, 13);
  exec_testcase(7, 21);
  exec_testcase(8, 34);
  exec_testcase(9, 55);
  exec_testcase(10, 89);
  exec_testcase(11, 144);

  exec_testcase(20, 10946);  // must run two passes??
  exec_testcase(30, 1346269);
  exec_testcase(40, 1);      // you get the idea...

  exec_testcase(-3, -1);     // parameter error is flagged

} //endmain
