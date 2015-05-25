#ifndef _BST_H_
#define _BST_H_

#define INSERTED 1
#define NOT_INSERTED 0

typedef struct bst_node* BSTNode; /* typedef for node */
typedef struct bst_node* BSTHead; /* typedef for head node (yet another node) */
struct bst_node {
	int data; 
	BSTNode left;
	BSTNode right;
};

BSTNode createBSTNode(int data);

int insertNode(int data, BSTHead root);

int insertNodeRec(int data, BSTHead root);

BSTNode find(int data, BSTHead root);

int depth(BSTHead root);

void delete(int n, BSTHead root);

#endif /* _BST_H_ */