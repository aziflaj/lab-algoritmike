#ifndef _TEST_H_
#define _TEST_H_

#include <stdio.h>
#include <string.h>

/**********************************************/
char* stringifyTestResult(int test) {
	return (test == 1) ? "PASSED" : "FAILED";
}
/**********************************************/


int testSubString() {
	char *mainstr = "Hello, World";
	char *newStr = subString(mainstr, 1, 4);

	return !(strcmp(newStr, "ello"));
}

#endif /* _TEST_H_ */