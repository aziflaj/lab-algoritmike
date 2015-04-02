#ifndef _TRACE_H_
#define _TRACE_H_

#define MAX_RECORDS 4096

typedef struct {
	char comment[40]; 			/* Name of the experiment */
	int nbpts; 					/* Number of measurements (0-based) */
	float time[MAX_RECORDS];	/* Time of a measurement */
	float value[MAX_RECORDS];	/* The value measured */
} Trace;

void simulate(int tmax, float dt, float params[], Trace *uneTrace);

void printTrace(Trace uneTrace);

void saveTraceBin(char* fileTrace, Trace uneTrace);

void readTrace(char* fileTrace, Trace* uneTrace);

float errorTrace(Trace simTrace, Trace realTrace);


#endif /* _TRACE_H_ */