#ifndef _BST_H_
#define _BST_H_


typedef struct bst_node* BSTNode; /* typedef for node */
typedef struct bst_node* BSTHead; /* typedef for head node (yet another node) */
struct bst_node {
	int data; 
	BSTNode left;
	BSTNode right;
};

BSTNode createBSTNode(int data);

#endif /* _BST_H_ */