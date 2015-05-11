#include <stdio.h>
#include <stdlib.h>
#include "text.h"


int main(void) {

	Text hello = createText();
	appendText(hello, "Hello, World!");
	printf("PRINTING TEXT\n");
	printText(hello);

	pushText(hello, "123---");
	printf("\nPRINTING OTHER TEXT\n");
	printText(hello);
	printf("\n");

	return (EXIT_SUCCESS);
}