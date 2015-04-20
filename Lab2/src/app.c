#include <stdio.h>
#include <stdlib.h>
#include "text.h"


int main(void) {
	/*
	/* Testing createTextFromCharArray() *
	Text hello = createTextFromCharArray("Hello, World!");

	/* Testing creation of empty node *
	Node newNode = createNode();
	printf("%d size\n", newNode->size);
	
	/* Testing creation of empty text *
	Text t = createText();
	if (t->head == NULL && t->tail == NULL) {
		printf("size: %d\n", t->size);
		printf("count: %d\n", t->count);
	}
	*/

	Text hello = createText();
	appendText(hello, "Hello, World!");
	printf("PRINTING TEXT\n");
	printText(hello);

	pushText(hello, "123---");
	printf("\nPRINTING OTHER TEXT\n");
	printText(hello);	

	return (EXIT_SUCCESS);
}