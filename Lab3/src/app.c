#include <stdio.h>
#include <stdlib.h>
#include "text.h"


int main(void) {
	//*
	Text hello = createText();
	appendText(hello, "Hello, World!");
	pushText(hello, "123---");
	printText(hello);
	printf("\n");
	/*
	float evaluated = evalText(hello);
	printf("evalText of the above is %.2f%%\n", evaluated);

	normalizeText(hello);		
	printf("text after normalization is evaluated @ %.2f%%\n", evalText(hello));
	//*/

	normalizeText(hello);
	Iter iterator = createIterAtBegin(hello);
	iterator->icase = 1;

	printf("Initial print\n");
	printWithPosition(hello, iterator);
	printf("\n");

	printf("Moving the iterator 5 chars forward\n");
	moveForwardIter(hello, iterator, 5);
	printWithPosition(hello, iterator);
	printf("\n");

	printf("Moving the iterator 30 chars backward\n");
	moveBackwardIter(hello, iterator, 30);
	printWithPosition(hello, NULL);
	printf("\n");
	//*/

	return (EXIT_SUCCESS);
}
