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

	// normalizeText(hello);

	return (EXIT_SUCCESS);
}
