#include <stdio.h>
#include <stdlib.h>
#include "text.h"


int main(void) {
	/*
	Text hello = createTextFromCharArray("Hello, World!");
	*/

	Node newNode = createNode();
	printf("%d size\n", newNode->size);


	return (EXIT_SUCCESS);
}