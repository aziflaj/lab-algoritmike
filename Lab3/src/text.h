#ifndef _TEXT_H_
#define _TEXT_H_

#define NODE_TEXT_LEN 4


typedef struct linked_list_text_item* Node; 
struct linked_list_text_item {
	char data[NODE_TEXT_LEN+1];
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

/****************************************************/

/**
 * Calculates the efficiency of memory usage
 *
 * @param t A Text instance to calculate the memory usage
 * @return The value of efficiency
 *
 * @author Aldo Ziflaj
 */
float evalText(Text t);


/**
 * Normalizes a Text instance to use the memory in the most efficient way
 *
 * @param t A Text instance to normalize
 *
 * @author Aldo Ziflaj 
 */
void normalizeText(Text t);


/**
 * Prints a Text instance with an Iterator at its position, marked by asterix (*)
 *
 * @param t A Text instance to print
 * @param iterator An Iter instance holding a position at the given Text
 *
 * @author Aldo Ziflaj 
 */ 
void printWithPosition(Text t, Iter iterator);


/**
 * Moves the iterator forward (right) by a given number of characters
 *
 * @param t A Text instance where the iterator lives
 * @param iterator The Iter instance to be moved
 * @param n The number of characters to pass
 *
 * @author Aldo Ziflaj  
 */
void moveForwardIter(Text t, Iter iterator, int n);

/**
 * Moves the iterator backward (left) by a given number of characters
 *
 * @param t A Text instance where the iterator lives
 * @param iterator The Iter instance to be moved
 * @param n The number of characters to pass
 *
 * @author Aldo Ziflaj   
 */
void moveBackwardIter(Text t, Iter iterator, int n);


/**
 * Inserts a given string after the iterator
 *
 * @param t A Text instance where to add the text
 * @param i An Iter instance that holds the position where to insert the string
 * @param str The string to insert into the text
 *
 * @author Aldo Ziflaj
 */
void insertTextAfterIter(Text t, Iter i, char *str);

/**
 * Deletes a given number of characters before the iterator
 *
 * @param t A Text instance where to delete the characters
 * @param i An Iter instance that holds the position were to start deleting
 * @param n The number of characters to be deleted
 *
 * @author Aldo Ziflaj 
 */
void deleteTextBeforeIter(Text t, Iter i, int n);

#endif /* _TEXT_H_ */
