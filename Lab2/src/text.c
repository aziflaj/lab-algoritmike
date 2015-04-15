#include <stdio.h>
#include <string.h>
#include "text.h"

Node createNodeFromCharArray(char *charArray) {
	int len = strlen(charArray);
	int numberOfNodes = (len % MAX_LENGTH == 0) ? (int) (len/MAX_LENGTH) : (int) (len/MAX_LENGTH) + 1;

	printf("%d chars\n", len);
	printf("%d nodes\n", numberOfNodes);
	return NULL;
}