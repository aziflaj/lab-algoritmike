#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"
#include "utils.h"

Text createTextFromCharArray(char *charArray) {
	Node head, tail;
	int size = strlen(charArray);
	int count = (size % NODE_TEXT_LEN == 0) ? 
					(int) (size/NODE_TEXT_LEN) : 
					(int) (size/NODE_TEXT_LEN) + 1;

	int i = 0;
	int headTaken = 0; /* Status of head */
	Node cursor;

	while(i < count) {
		Node n = (Node) malloc(sizeof(Node));
		if (headTaken == 0) {
			head = n;
			char *kot;
			subString(charArray, i*NODE_TEXT_LEN, (i+1)*NODE_TEXT_LEN, kot);
			printf("%s\n", kot);
			strcpy(head->data, kot );
			cursor = n;
			headTaken = 1;
		} else {
			/* head already taken *
			txt->tail->next = n; */
		}

		i++;
	}

	printf("%d chars\n", size);
	printf("%d nodes\n", count);
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

void printText(Text t) {
	Node cursor = t->head;

	do {
		printf("%s", cursor->data);
		cursor = cursor->next;
	} while (cursor != NULL);

}