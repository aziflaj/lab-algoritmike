#include <stdio.h>
#include <stdlib.h>
#include "text.h"


int main(void) {

	Text hello = createText();
	appendText(hello, "Hello, World!");
	pushText(hello, "123---");
	printText(hello);
	printf("\n");

	float evaluated = evalText(hello);
	printf("evalText of the above is %.2f%%\n", evaluated);

	normalizeText(hello);
	printf("text after normalization is evaluated @ %.2f%%\n", evalText(hello));

	Iter iterator = createIterAtBegin(hello);
	iterator->icase = 1;

	//printWithPosition(hello, iterator);

	moveForwardIter(hello, iterator, 70);

	printf("New iterator: icase %d\n", iterator->icase);

	printf("The text on that node is: %s\n", iterator->self->data);


	return (EXIT_SUCCESS);
}
