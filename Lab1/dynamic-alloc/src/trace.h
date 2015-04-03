#ifndef _TRACE_H_
#define _TRACE_H_

typedef struct {
	char comment[40]; 	/* Name of the experiment */
	int nbpts; 		/* Number of measurements (0-based) */
	float *time;		/* Time of a measurement */
	float *value;		/* The value measured */
} Trace;


/**
 * This function simulates a Trace instance based in the FitzHugh - Nagumo equation
 *
 * @param tmax The finish time of the simulation
 * @param dt The difference of time between simulations
 * @param params The alpha, delta, epsilon array of parameters to simulate
 * @param uneTrace The Trace instance to be simulated
 *
 * @author: Aldo Ziflaj
 */
void simulate(int tmax, float dt, float params[], Trace *uneTrace);


/**
 * This function prints a Trace instance 
 *
 * @author: Aldo Ziflaj
 */
void printTrace(Trace uneTrace);


/**
 * This function saves a Trace instance in a file
 *
 * @param fileTrace The name of the file where to be saved
 * @param uneTrace The Trace instance to be saved
 *
 * @author: Aldo Ziflaj
 */
void saveTraceBin(char* fileTrace, Trace uneTrace);


/**
 * This function reads a Trace instance from a file
 *
 * @param fileTrace The name of the file where to read
 * @param uneTrace The Trace instance to read
 *
 * @author: Aldo Ziflaj
 */
void readTrace(char* fileTrace, Trace *uneTrace);


/**
 * This function calculates the error between two Trace instances
 *
 * @param simTrace The simulated Trace instance
 * @param realTrace The real Trace instance, measured
 *
 * @author: Aldo Ziflaj
 */
float errorTrace(Trace simTrace, Trace realTrace);


#endif /* _TRACE_H_ */
