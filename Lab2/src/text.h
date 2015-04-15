#ifndef _TEXT_H_
#define _TEXT_H_

#define NODE_TEXT_LEN 4


typedef struct linked_list_text_item* Node; 
struct linked_list_text_item {
	char data[NODE_TEXT_LEN];
	int size;
	Node prev;
	Node next;
};


typedef struct text* Text;
struct text {
	Node head;
	Node tail;
	int count;
	int size;
};


struct iter {
	Node self;
	int icase;
};

Text createTextFromCharArray(char *charArray);

Node createNode();

Text createText();

void printText(Text t);


#endif /* _TEXT_H_ */
