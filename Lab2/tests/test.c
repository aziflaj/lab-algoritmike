#include <stdio.h>
#include "utils.h"

int main(void) {
	char *mainstr = "Hello, World";
	char *newStr = subString(mainstr, 1, 4);
	printf("%s\n", mainstr);
	printf("%s\n", newStr);
	return 0;
}