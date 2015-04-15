#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

char* subString(char* str, int from, int to) {
	char *newStr;
	int len = to - from;
	newStr = (char*) malloc(sizeof(char) * len);

	for (int i = 0; i <= len; i++) {
		newStr[i] = str[from+i];
	}

	return newStr;
}