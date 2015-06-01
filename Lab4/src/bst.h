#ifndef _BST_H_
#define _BST_H_


typedef enum { NOT_INSERTED, INSERTED } insertion_status;

typedef struct bst_node* BSTNode; /* typedef for node */
typedef struct bst_node* BSTHead; /* typedef for head node (yet another node) */
struct bst_node {
	int data;
	BSTNode left;
	BSTNode right;
};

/**
 * Creates a BST (Binary Search Tree) node.
 * Note that the root is yet another node.
 *
 * @param data The integer number being stored in the node
 * @return The node created
 *
 * @author Aldo Ziflaj
 */
BSTNode createBSTNode(int data);


/**
 * Inserts a node into a given BST, represented by its root, by using iteration.
 *
 * @param data The integer number to add in the BST
 * @param root The root of the BST
 * @return The status (INSERTED/NOT_INSERTED) of the insertion
 *
 * @author Aldo Ziflaj
 */
insertion_status insertNode(int data, BSTHead root);


/**
 * Inserts a node into a given BST, represented by its root, by using recursion.
 *
 * @param data The integer number to add in the BST
 * @param root The root of the BST
 * @return The status (INSERTED/NOT_INSERTED) of the insertion
 *
 * @author Aldo Ziflaj
 */
insertion_status insertNodeRec(int data, BSTHead root);


/**
 * Finds a given number in the BST.
 *
 * @param data The integer number to find in the BST
 * @param root The root of the BST
 * @return The node where the data is found (if found)
 *
 * @author Aldo Ziflaj
 */
BSTNode find(int data, BSTHead root);


/**
 * Calculates the depth of a BST
 *
 * @param root The root of the BST
 * @return The depth of the BST
 *
 * @author Aldo Ziflaj
 */
int depth(BSTHead root);


/**
 * Deletes an integer from the BST
 *
 * @param n The integer number to delete from the BST
 * @param root The root of the BST
 *
 * @author Aldo Ziflaj
 */
void delete(int n, BSTHead root);

#endif /* _BST_H_ */
