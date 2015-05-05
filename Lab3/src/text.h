#ifndef _TEXT_H_
#define _TEXT_H_

#define NODE_TEXT_LEN 4


typedef struct linked_list_text_item* Node; 
struct linked_list_text_item {
	char data[NODE_TEXT_LEN];
	int size;
	Node next;
	Node prev;
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

/**
 * Creates an empty Node instance
 * 
 * @return An empty Node instance
 *
 * @author Aldo Ziflaj
 */
Node createNode();


/**
 * Creates an empty Text instance
 * 
 * @return An empty Text instance
 *
 * @author Aldo Ziflaj
 */
Text createText();


/**
 * Frees a Text instance from the memory
 *
 * @param t The text instance to free
 * 
 * @author Aldo Ziflaj
 */
void freeText(Text t);


/**
 * Prints the text stored into a Text instance
 *
 * @param t The text instance to print
 *
 * @author Aldo Ziflaj
 */
void printText(Text t);


/**
 * Appends some text in the end of a Text instance
 *
 * @param t The Text instance where to append
 * @param s The char array to append
 *
 * @author Aldo Ziflaj
 */
void appendText(Text t, char* s);


/**
 * Inserts some text in the beginning of a Text instance
 *
 * @param t The Text instance where to insert the text
 * @param s The char array to insert in the beginning of t
 *
 * @author Aldo Ziflaj
 */
void pushText(Text t, char* s);


/**
 * A factory function to create an Iter instance out of a Text 
 * instance
 *
 * @param t The text instance where to create the iterator
 *
 * @author Aldo Ziflaj
 */
Iter createIterAtBegin(Text t);


/**
 * Frees the memory from an Iter instance
 *
 * @param iterator The Iter instance to free
 *
 * @author Aldo Ziflaj
 */
void freeIter(Iter iterator);

#endif /* _TEXT_H_ */
