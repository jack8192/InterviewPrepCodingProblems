/*
     Problem:  Given a string of characters determine if
	           it is a palindrone, e.g.:
			        ABA is
					ABB isn't

*/
#include <stdio.h>
#include <stdlib.h>

//
// Module Under Test (MUT)
//
#include "IsPal.c"


struct TestCase * construct_testcase(char *in_ch, struct TestCase *prior, bool in_result) {


        struct TestCase *next;

		next = calloc(sizeof(struct TestCase),1);

		next->ch_array        = in_ch;
		next->expected_result = in_result;
		next->next_test       = NULL;

		if (prior != NULL) {prior->next_test = next;}

		return next;

} // endfunction


void exec_testcases(struct TestCase *head) {

    struct TestCase *curr_case;
	bool   result;
	int    nr_passed = 0;
	int    nr_tests  = 0;

	for (curr_case = head; curr_case != NULL; curr_case = curr_case->next_test) {

		printf ("\nTest case of :%s:", curr_case->ch_array);

		// same when combined, only clearer
		result = IsPal(curr_case->ch_array);
		(result) ? printf(" is a palindrome") : printf(" is NOT a palindrome");

		printf (" and has ");

	    if (result == curr_case->expected_result) {
			printf("passed");
		    nr_passed++;

		} else {
		    printf("failed");

		} //endif

		printf (" the test.");

		nr_tests++;
	} //endfor

	printf("\n\nDone! %d of %d tests have passed.\n",nr_passed,nr_tests);


} //endfunction

void main() {

     struct TestCase *head;
	 struct TestCase *tail;

	 head = NULL;
	 head = construct_testcase("ABA", head, true);
	 tail = construct_testcase("ABB", head, false);
	 tail = construct_testcase("ABBA", tail, true);
	 tail = construct_testcase("ABBC", tail, false);
	 tail = construct_testcase("ABABBABA", tail, true);
	 tail = construct_testcase("ABBAABBA", tail, true);
	 tail = construct_testcase("ABCBA", tail, true);
	 tail = construct_testcase("A", tail, true);
	 tail = construct_testcase("AAAAAAAAAAA", tail, true);
	 tail = construct_testcase("AB", tail, false);
	 tail = construct_testcase("", tail, false);
	 tail = construct_testcase("ABCBA", tail, true);
	 tail = construct_testcase("AAAAAAXAAAA", tail, false);
	 tail = construct_testcase("AAAAAVAAAAAA", tail, false);


	 exec_testcases(head);



} // endmain
