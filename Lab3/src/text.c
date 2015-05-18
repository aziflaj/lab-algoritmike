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
	if ( (t == NULL) || (t->head == t->tail) ) {
		return;
	}

	char *stringOfText = (char*) malloc(sizeof(char) * t->size);

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


void moveForwardIter(Text t, Iter iterator, int n) {
	if (t == NULL || iterator == NULL) {
		return;
	}

	int newCharPosition = iterator->icase + n;
	int newNodePosition = ((newCharPosition) / NODE_TEXT_LEN) + 1;

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
	int newNodePosition = ((newCharPosition) / NODE_TEXT_LEN) + 1;

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

void printWithPosition(Text t, Iter iterator) {
	if (t == NULL) {
		return;
	}

	if (iterator == NULL) {
		printf("*");
		printText(t);
		return;
	}

	//translate iterator's icase into node number
	int nodePosition = ((iterator->icase) / NODE_TEXT_LEN) + 1;
	//find the index of icase
	int icaseIndex = (nodePosition + 1) % NODE_TEXT_LEN ;
	debug("node position %d, char %d", nodePosition, icaseIndex);

	Node cursor = t->head;
	int counter = 1; //to count the nodes (1-based)

	do {
		if (counter == nodePosition) {

			for (int i=0;i<icaseIndex;i++) {
				printf("%c", cursor->data[i]);
			}
			
			printf("*");
			
			for (int i=icaseIndex;i<NODE_TEXT_LEN; i++) {
				printf("%c", cursor->data[i]);
			}
			++counter;

		} else {
			printf("%s", cursor->data);
			++counter;
		}
		cursor = cursor->next;
	} while (cursor != NULL);
}


void insertTextAfterIter(Text t, Iter i, char *str) {
	int addedLength = strlen(str);

	/* TOKENIZING THE OLD TEXT */
	char *oldText = (char*) malloc(sizeof(char) * t->size);

	Node n = createNode();
	n = t->head;
	strcpy(oldText, n->data);
	n = n->next;

	while (n != NULL) {
		strcat(oldText, n->data);
		n = n->next;
	}

	int length1 = i->icase+1;
	int length2 = t->size - i->icase - 1;

	char token1[length1];
	char token2[length2];

	strncpy(token1, oldText, length1);
	token1[length1] = '\0';

	strncpy(token2, oldText + length1, length2);
	token2[length2] = '\0';

	/* CREATE THE NEW STRING */
	char *newText = (char*) malloc(sizeof(char) * (t->size + addedLength));
	strcpy(newText, token1);
	strcat(newText, str);
	strcat(newText, token2);

	freeText(t);
	t = createText();
	appendText(t, newText); //normalized text;

	/* SET THE ITERATOR AT THE END OF THE ADDED STRING */
	i->icase = length1 + addedLength -1 ;
	int nodePosition = ((i->icase) / NODE_TEXT_LEN) + 1;

	Node cursor = t->head;
	int counter = 1; //counting nodes as 1-based lists

	do {
		if (counter != nodePosition) {
			cursor = cursor->next;
			++counter;
		} else {
			i->self = (Node) cursor;
			break;
		}

	} while (cursor != NULL);
}