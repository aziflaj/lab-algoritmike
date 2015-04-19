#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "text.h"



/********* MORE READABLE TEST RESULTS *********/
char* stringifyTestResult(int test) {
	return (test == 1) ? "PASSED" : "FAILED";
}
/**********************************************/


/*********** UTILS HEADER TESTING *************/
int testSubString() {
	char *mainstr = "Hello, World";
	char *newStr = subString(mainstr, 1, 4);
	debug("%s\n", newStr);

	return !(strcmp(newStr, "ell"));
}
/**********************************************/


#endif /* _TEST_H_ */