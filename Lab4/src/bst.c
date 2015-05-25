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
		printf("Found\n");
		return root;
	} else if (root->data > data) {
		return find(data, root->left);
	} else if (root->data < data) {
		return find(data, root->right);
	}
}