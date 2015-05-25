#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BSTNode createBSTNode(int data) {
	BSTNode node = (BSTNode) malloc( sizeof(BSTNode) );
	node->data = data;
	return node;
}



void insertNode(int data, BSTHead root) {
	
	/* if root is null, create the new root */
	if (root == NULL) {
		root = createBSTNode(data);
	}

	else {
		BSTNode bstCursor = head;
		BSTNode newNode = createBSTNode(data);

		do {
			
			if (bstCursor->data > data) {
				/* add data node to the right */
				bstCursor = bstCursor->right;

			} else if ( bstCursor->data < data) {
				/* add data node to the left */
				bstCursor = bstCursor->left;				
			}

		} while (bstCursor->left != NULL || bstCursor->right != NULL);


		if (bstCursor->data > data) {
			/* add to the left of bstCursor */
			bstCursor->left = newNode;

		} else if (bstCursor->data < data) {
			/* add to the right of bstCursor */
			bstCursor->right = newNode;

		} else {
			printf("This node is already inserted\n");
		}
	}

}

//*
void insertNodeRec(int data, BSTHead root) {

	if (root == NULL) {
		return;
	}

	if (root->data == data) {
		printf("This node is already inserted\n");
		return;
	}

	if (root->data > data) {
		// insert on the left 
		if (root->left == NULL) {
			BSTNode newNode = createBSTNode(data);
			root->left = newNode;
		} else {
			insertNodeRec(data, root->left);
		}

	} else {
		// insert on the right 
		if (root->right == NULL) {
			BSTNode newNode = createBSTNode(data);
			root->right = newNode;
		} else {
			insertNodeRec(data, root->right);
		}

	}
}
//*/