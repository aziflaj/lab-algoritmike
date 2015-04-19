#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "utils.h"

/*
Text createTextFromCharArray(char *charArray) {
	Node head, tail;
	int size = strlen(charArray);
	int count = (size % NODE_TEXT_LEN == 0) ? 
					(int) (size/NODE_TEXT_LEN) : 
					(int) (size/NODE_TEXT_LEN) + 1;

	int i = 0;
	int headTaken = 0; /* Status of head *
	Node cursor;

	while(i < count) {
		Node n = (Node) malloc(sizeof(Node));
		if (headTaken == 0) {
			head = n;
			char *kot;
			subString(charArray, i*NODE_TEXT_LEN, (i+1)*NODE_TEXT_LEN, kot);
			debug("%s\n", kot);
			strcpy(head->data, kot );
			cursor = n;
			headTaken = 1;
		} else {
			/* head already taken *
			txt->tail->next = n; *
		}

		i++;
	}

	debug("%d chars\n", size);
	debug("%d nodes\n", count);
	return NULL;
}
*/


Node createNode() {
	Node n = (Node) malloc(sizeof(Node));
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
	int i = 0;

	while (cursor != NULL) {
		debug("iter %d\n", i);
		debug("%s", cursor->data);
		cursor = cursor->next;
		i++;
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
		/* debug("node %d. data %s; size %d\n\n", i, n->data, n->size); */

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