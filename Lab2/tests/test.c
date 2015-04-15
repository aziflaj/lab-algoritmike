#include <string.h>
#include "utils.h"

int testSubString() {
	char *mainstr = "Hello, World";
	char *newStr = subString(mainstr, 1, 4);

	return (strcmp(newStr, "ello") == 0) ? 1 : 0;
}