#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

#define MAX 10000

void iter_VS_rec();

void find_test();

void delete_test();

void depth_test();

int main(void) {
	
	//iter_VS_rec();

	//find_test();

	//delete_test();

	//depth_test();

	return (EXIT_SUCCESS);
}

void iter_VS_rec() {
	clock_t start, end;
	double time;
	int sumInserted = 0;

	srand(clock());
	int rnd_factor = rand() % 100;

	BSTHead iter_head = createBSTNode(7);
	printf("Created head of tree with data %d\n", iter_head->data); 
	
	start = clock();
	for (int i = 0; i < MAX*rnd_factor; i++) {	
		int random = rand() % (MAX * 100);
		//printf("%d ", random);
		sumInserted += insertNode(random, iter_head);	
	}
	end = clock();

	printf("Done. %d inserted\n", sumInserted);
	
	time = ((double) end - start) / CLOCKS_PER_SEC;
	printf("time for iterative insertion: %f\n", time);
	

	printf("\n\n");

		
	BSTHead rec_head = createBSTNode(7);
	printf("Created head of tree with data %d\n", rec_head->data);
	sumInserted = 0;
	start = clock();
	for (int i = 0; i < MAX*rnd_factor; i++) {	
		int random = rand() % (MAX * 100);
		//printf("%d ", random);
		sumInserted += insertNodeRec(random, rec_head);	
	}
	end = clock();

	printf("Done. %d nodes inserted\n", sumInserted);
	
	time = ((double) end - start) / CLOCKS_PER_SEC;
	printf("time for recursive insertion: %f\n", time);

}

void find_test() {
	//create a BST and randomly fill it
	BSTHead root = createBSTNode(7);

	srand(clock());
	int rnd_factor = rand() % 100;
	int item;

	for (int i = 0; i < 30; i++) {	
		int random = rand() % (100);
		printf("%d ", random);
		insertNodeRec(random, root);	
	}

	printf("\nWhich to find? ");
	scanf("%d", &item);

	BSTNode node = find(item, root);
	printf("%d\n", node->data);
}


void delete_test() {
	int nodes[] = { 4, 9, 8, 12, 10, 11, 13, 15, 14 };

	BSTHead root = createBSTNode(16);

	insertNodeRec(4, root);
	insertNodeRec(9, root);
	insertNodeRec(8, root);
	insertNodeRec(12, root);
	insertNodeRec(10, root);
	insertNodeRec(11, root);
	insertNodeRec(13, root);
	insertNodeRec(15, root);
	insertNodeRec(14, root);
	
	/*****************************************/
	//delete 8
	printf("\n\nbefore delete\n");
	find(8, root);
	delete(8, root);
	printf("after delete\n");
	find(8, root);

 	/*****************************************/
 	//delete 15
	printf("\n\nbefore delete\n");
	find(15, root);
	delete(15, root);
	printf("after delete\n");
	find(15, root);
	find(14, root);
	

	/*****************************************/
	//delete 12
	printf("\n\nbefore delete\n");
	find(12, root);
	delete(12, root);
	printf("after delete\n");
	find(12, root);
	find(10, root);
	find(14, root);

}

void depth_test() {
	int nodes[] = { 4, 9, 8, 12, 10, 11, 13, 15, 14 };

	BSTHead root = createBSTNode(16);

	insertNodeRec(4, root);
	insertNodeRec(9, root);
	insertNodeRec(8, root);
	insertNodeRec(12, root);
	insertNodeRec(10, root);
	insertNodeRec(11, root);
	insertNodeRec(13, root);
	insertNodeRec(15, root);
	insertNodeRec(14, root);

	printf("depth is %d\n", depth(root));
}