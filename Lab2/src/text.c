#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"

Text createTextFromCharArray(char *charArray) {
	int len = strlen(charArray);
	int numberOfNodes = (len % NODE_TEXT_LEN == 0) ? 
						(int) (len/NODE_TEXT_LEN) : 
						(int) (len/NODE_TEXT_LEN) + 1;

	printf("%d chars\n", len);
	printf("%d nodes\n", numberOfNodes);
	return NULL;
}

Node createNode() {
	Node n = (Node) malloc(sizeof(Node));
	n->next = NULL;
	n->prev = NULL;
	n->size = 0;
	return n;
}

Text createText() {
	Text t = (Text) malloc(sizeof(Text));
	t->head = NULL;
	t->tail = NULL;
	t->count = 0;
	t->size = 0;
	return t;
}