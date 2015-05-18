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
	Node cursor = t->head;

	while (cursor != NULL) {
		printf("%s", cursor->data);
		cursor = cursor->next;
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
		n->data[NODE_TEXT_LEN] = '\0';

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

/*****************************************************/

float evalText(Text t) {
	float r = 0.0;
	int numberOfNodes = t->count;
	int sumOfSizes = 0;

	if (t == NULL) { /* do nothing! r == 0.0 */ }

	else if (t->head == t->tail) {
		r = (float) ( (t->head)->size ) / NODE_TEXT_LEN;
	}

	/* head != tail */
	else {
		Node n = createNode();
		n = t->head;

		do {

			sumOfSizes += n->size;
			n = n->next;

		} while (n != NULL);

		r = (float) sumOfSizes / (numberOfNodes * NODE_TEXT_LEN);
	}	

	
	return r * 100;
}

void normalizeText(Text t) {
	char *stringOfText = (char*) malloc(sizeof(char) * t->size);

	if ( (t == NULL) || (t->head == t->tail) ) {
		return;
	}

	Node n = createNode();
	n = t->head;
	strcpy(stringOfText, n->data);
	n = n->next;

	while (n != NULL) {
		strcat(stringOfText, n->data);
		n = n->next;
	}

	freeText(t);
	t = createText();
	appendText(t, stringOfText);
}


void printWithPosition(Text t, Iter i) {
	if (t == NULL || i == NULL) {
		return;
	}

	Node cursor = t->head;

	do {
		printf("%s\n", cursor->data);
		cursor = cursor->next;
	} while (cursor != NULL);
}

void moveForwardIter(Text t, Iter iterator, int n) {
	if (t == NULL || iterator == NULL) {
		return;
	}

	int newCharPosition = iterator->icase + n;
	int newNodePosition = ((newCharPosition) / 4) + 1;

	if (newCharPosition > t->size) {
		newCharPosition = t->size;
	}

	if (newNodePosition > t->count) {
		newNodePosition = t->count;
	}

	iterator->icase = newCharPosition;
	//set the correct node;

	Node cursor = t->head;
	int counter = 1; //counting nodes as 1-based lists

	do {
		if (counter != newNodePosition) {
			cursor = cursor->next;
			++counter;
		} else {
			iterator->self = (Node) cursor;
			break;
		}

	} while (cursor != NULL);

}

void moveBackwardIter(Text t, Iter iterator, int n) {
	if (t == NULL || iterator == NULL) {
		return;
	}

	int newCharPosition = iterator->icase - n;
	int newNodePosition = ((newCharPosition) / 4) + 1;

	if (newCharPosition < 0) {
		newCharPosition = 0;
	}

	if (newNodePosition < 0) {
		newNodePosition = 1;
	}

	iterator->icase = newCharPosition;
	//set the correct node;

	Node cursor = t->head;
	int counter = 1; //counting nodes as 1-based lists

	do {
		if (counter != newNodePosition) {
			cursor = cursor->next;
			++counter;
		} else {
			iterator->self = (Node) cursor;
			break;
		}

	} while (cursor != NULL);

}