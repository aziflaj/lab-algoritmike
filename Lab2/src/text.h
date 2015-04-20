#ifndef _TEXT_H_
#define _TEXT_H_

#define NODE_TEXT_LEN 4


typedef struct linked_list_text_item* Node; 
struct linked_list_text_item {
	//char data[NODE_TEXT_LEN];
	char *data;
	int size;
	Node next;
};


typedef struct text* Text;
struct text {
	Node head;
	Node tail;
	int count;
	int size;
};


typedef struct iter* Iter;
struct iter {
	Node self;
	int icase;
};

Text createTextFromCharArray(char *charArray);

Node createNode();

Text createText();

void freeText(Text t);

void printText(Text t);

void appendText(Text t, char* s);

void pushText(Text t, char* s);

Iter createIterAtBegin(Text t);

void freeIter(Iter iterator);

#endif /* _TEXT_H_ */
