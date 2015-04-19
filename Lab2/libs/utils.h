#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include <stdarg.h>

char* subString(char* str, int from, int to) {
	char *newStr;
	
	if (from < 0)  from = 0;;

	if (to > (strlen(str) - 1)) to = strlen(str);

	int len = to - from;
	newStr = (char*) malloc(sizeof(char) * len);

	for (int i = 0; i < len; i++) {
		newStr[i] = str[from+i];
	}

	return newStr;
}

void debug(const char *format, ...) {
	va_list args;
	printf("DEBUG: ");
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	printf("\n");
}

#endif /* _UTILS_H_ */