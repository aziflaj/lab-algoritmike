#include <stdio.h>
#include <stdlib.h>
#include "trace.h"

/*********** GLOBAL VARIABLES ***********/

float Pa[] = { 
	0.5,   		/* alpha */
	0.01,  		/* delta */
	0.05   		/* epsilon */
};

float Pb[] = {
	0.75,   	/* alpha */
	0.3,  		/* delta */
	0.1   		/* epsilon */
};

float dt = 0.5; 
float tmax = 1000;

/******* END OF GLOBAL VARIABLES *******/

int main(void) {
	Trace realTrace; 		/* real trace, read from the file */
	Trace simTrace1;		/* first simulated trace */
	Trace simTrace2;		/* second simulated trace */
	double error1 = 0.0, error2 = 0.0;

	readTrace("../static/cell.txt", &realTrace);
	printf("There are %d records on the trace\n", realTrace.nbpts);
	printTrace(realTrace); 

/*
	simulate(tmax, dt, Pa, &simTrace1);
	saveTraceBin("../static/simone.txt", simTrace1);

	error1 = errorTrace(simTrace1, realTrace);
	printf("With the 1st method, the error is calculated to be %f\n", error1);


	simulate(tmax, dt, Pb, &simTrace2);
	saveTraceBin("../static/simtwo.txt", simTrace2);

	error2 = errorTrace(simTrace2, realTrace);
	printf("With the 2nd method, the error is calculated to be %f\n", error2);

	if ( error1 < error2 ) {
		printf("The first method is better");
	} else {
		printf("The second method is better\n");
	}

*/
	return (EXIT_SUCCESS);
}