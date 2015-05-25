#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main(void) {

	BSTHead tree_head = createBSTNode(7);

	printf("Created head of tree with data %d\n", tree_head->data); 

	return (EXIT_SUCCESS);
}