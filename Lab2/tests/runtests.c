#include <stdio.h>
#include "utils.h"
#include "test.h"


int main(void) {
	printf("Testing subString function: %s\n\n", stringifyTestResult(testSubString())); 
	return 0;
}
