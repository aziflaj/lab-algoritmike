#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "bst.h"

#define MAX 10000

int main(void) {
	clock_t start, end;
	double time;
	int sumInserted = 0;

	srand(clock());
	int rnd_factor = rand() % 100;

	//*
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
	//*/

	printf("\n\n");

	//*	
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
	//*/

	return (EXIT_SUCCESS);
}