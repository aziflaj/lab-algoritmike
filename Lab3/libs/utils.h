#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void debug(const char *format, ...) {
	va_list args;
	printf("DEBUG: ");
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	printf("\n");
}

void printString(char *str, int len) {
	for (int i=0; i<len;i++) {
		printf("%c", str[i]);
	}
	printf("\t| %d\n",len);
}

#endif /* _UTILS_H_ */
