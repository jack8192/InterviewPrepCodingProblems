#ifndef IsPal_h
#define IsPal_h

typedef enum _bool {false=0, False=0, true=1, True=1} bool;

struct TestCase {
  char              *ch_array;
  bool               expected_result;
  struct   TestCase *next_test;
}; // endstruct


struct TestCase * construct_testcase(char *, struct TestCase *, bool);

#endif
