#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "utils.h"


Node createNode() {
	Node n = (Node) malloc(sizeof(Node));
	strcpy(n->data, "");
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

void printText(Text t) {
	Iter cursor = createIterAtBegin(t);

	while (cursor->self != NULL) {
		printString(cursor->self->data, cursor->self->size);
		cursor->self = (cursor->self)->next;
		cursor->icase++;
	}
}

void appendText(Text t, char* s) {
	// calculate the size of the appended string
	int newSize = strlen(s);

	// calculate the number of nodes to add to the text.
	int newCount = (newSize % NODE_TEXT_LEN == 0) ? 
					(int) (newSize/NODE_TEXT_LEN) : 
					(int) (newSize/NODE_TEXT_LEN) + 1;

	for (int i=0; i<newCount; i++) {
		Node n = createNode();

		strncpy(n->data, s + (i*NODE_TEXT_LEN), NODE_TEXT_LEN);

		n->size = strlen(n->data);

		if (t->head == NULL) {
			// Text is empty: head is also tail
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

void pushText(Text t, char* s) {
	Text otherText = createText();
	appendText(otherText, s);

	Node other_tail = otherText->tail;
	other_tail->next = t->head;
	t->head = otherText->head;

	t->size += otherText->size;
	t->count += otherText->count;
}

Iter createIterAtBegin(Text t) {
	Iter iterator = (Iter) malloc(sizeof(struct iter));

	iterator->self = t->head;
	iterator->icase = 0;

	return iterator;
}

void freeText(Text t) {
	free(t);
}

void freeIter(Iter iterator) {
	free (iterator);
}