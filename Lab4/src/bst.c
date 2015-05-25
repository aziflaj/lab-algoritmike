#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BSTNode createBSTNode(int data) {
	BSTNode node = (BSTNode) malloc( sizeof(BSTNode) );
	node->data = data;
	return node;
}