#ifndef _TEXT_H_
#define _TEXT_H_

#define MAX_LENGTH 4


typedef struct linked_list_text_item* Node; 
struct linked_list_text_item {
	char data[MAX_LENGTH];
	int size;
	Node prev;
	Node next;
};

Node createNodeFromCharArray(char *charArray);


#endif /* _TEXT_H_ */
