#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "utils.h"


Node createNode() {
	Node n = (Node) malloc(sizeof(Node));
	n->data = (char*) malloc(sizeof(char) * NODE_TEXT_LEN);
	n->next = NULL;
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

void printText(Text t) {
	Node cursor = t->head;

	while (cursor != NULL) {
		printf("%s", cursor->data);
		cursor = cursor->next;
	}
}

void appendText(Text t, char* s) {

	int newSize = strlen(s);
	int newCount = (newSize % NODE_TEXT_LEN == 0) ? 
					(int) (newSize/NODE_TEXT_LEN) : 
					(int) (newSize/NODE_TEXT_LEN) + 1;

	for (int i=0; i<newCount; i++) {
		Node n = createNode();
		strcpy(n->data, subString(s, i*NODE_TEXT_LEN, (i+1)*NODE_TEXT_LEN));
		n->size = strlen(n->data);

		if (t->head == NULL) {
			/* Text is empty: head is also tail */
			t->head = n;
			t->tail = n;
		} else {
			Node tail = t->tail;
			tail->next = n;
			t->tail = n;
		}
	}

	t->size += newSize;
	t->count += newCount;
}