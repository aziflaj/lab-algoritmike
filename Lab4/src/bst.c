#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BSTNode createBSTNode(int data) {
	BSTNode node = (BSTNode) malloc( sizeof(BSTNode) );
	node->data = data;
	return node;
}



int insertNode(int data, BSTHead root) {
	
	/* if root is null, create the new root */
	if (root == NULL) {
		root = createBSTNode(data);
	}

	else {
		BSTNode bstCursor = root;
		BSTNode newNode = createBSTNode(data);

		do {
			
			if (bstCursor->data > data) {
				/* add data node to the right */
				bstCursor = bstCursor->right;
				return INSERTED;

			} else if ( bstCursor->data < data) {
				/* add data node to the left */
				bstCursor = bstCursor->left;	
				return INSERTED;			
			}

		} while (bstCursor->left != NULL || bstCursor->right != NULL);


		if (bstCursor->data > data) {
			/* add to the left of bstCursor */
			bstCursor->left = newNode;
			return INSERTED;

		} else if (bstCursor->data < data) {
			/* add to the right of bstCursor */
			bstCursor->right = newNode;
			return INSERTED;

		} else {
			//printf("This node is already inserted\n");
			return NOT_INSERTED;
		}
	}

}



int insertNodeRec(int data, BSTHead root) {

	if (root == NULL) {
		return NOT_INSERTED;
	}

	if (root->data == data) {
		//printf("This node is already inserted\n");
		return NOT_INSERTED;
	}

	if (root->data > data) {
		// insert on the left 
		if (root->left == NULL) {
			BSTNode newNode = createBSTNode(data);
			root->left = newNode;
			return INSERTED;
		} else {
			insertNodeRec(data, root->left);
		}

	} else {
		// insert on the right 
		if (root->right == NULL) {
			BSTNode newNode = createBSTNode(data);
			root->right = newNode;
			return INSERTED;
		} else {
			insertNodeRec(data, root->right);
		}

	}
}



BSTNode find(int data, BSTHead root) {
	if (root == NULL) {
		fprintf(stderr, "%d not found\n", data);
		return NULL;
	}

	if (root->data == data) {
		printf("%d found\n", data);
		return root;
	} else if (root->data > data) {
		return find(data, root->left);
	} else if (root->data < data) {
		return find(data, root->right);
	}
}


void delete(int n, BSTHead root) {

	BSTNode node = find(n, root);

	if (node == NULL) {
		printf("%d not found\n", n);
		return;
	}

	if (node->left == NULL && node->right == NULL) {
		// just delete the blody node!
		free(node);
		return;
	}


	//only one child
	//only right child
	if (node->left == NULL && node->right != NULL) {
		node->data = node->right->data;
		free(node->right); 
		return;
	}

	//only left child
	if (node->right == NULL && node->left != NULL) {
		node->data = node->left->data;
		free(node->left);
		return;
	}	


	//two children
	node->data = node->right->data;
	delete(n, node->right);

}

int depth(BSTHead root) {
	if (root == NULL) 
		return -1;

	return depth(root->left) > depth(root->right) ? 1 + depth(root->left) : 1 + depth(root->right);
}