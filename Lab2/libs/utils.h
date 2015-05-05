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

#endif /* _UTILS_H_ */