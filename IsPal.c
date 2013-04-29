/*
     Problem:  Given a string of characters determine if
	           it is a palindrone, e.g.
			        ABA is
					ABB isn't

*/
#include <stdio.h>
#include <stdlib.h>

#include "IsPal.h"

bool IsPal(char *in_ch_array) {

   bool  ret_value;

   /* find end of char array */
   char *ch_first;
   char *ch_last;

   ch_first = in_ch_array;   // pointer
   ch_last  = in_ch_array;

   while (*ch_last != '\0') {ch_last++;}

   if (ch_last == in_ch_array) {
       printf ("Error 1, null input");
	   return false;
   } //endif

   ch_last--;  // backup to avoid null string terminator

   /* now loop, assume it is a pal */
   ret_value = true;
   while (ch_first < ch_last) {

       if (*ch_first != *ch_last) {
			ret_value = false;
			break;
	   }

	   //
	   // pop and trim
	   //
	   ch_first++;
	   ch_last--;

	} //endwhile

	return ret_value;

} // endfunction
