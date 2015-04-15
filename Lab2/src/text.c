#include <stdio.h>
#include <string.h>
#include "text.h"

Node createTextFromCharArray(char *charArray) {
	int len = strlen(charArray);
	int numberOfNodes = (len % NODE_TEXT_LEN == 0) ? 
						(int) (len/NODE_TEXT_LEN) : 
						(int) (len/NODE_TEXT_LEN) + 1;

	printf("%d chars\n", len);
	printf("%d nodes\n", numberOfNodes);
	return NULL;
}