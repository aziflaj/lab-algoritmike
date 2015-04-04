#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "trace.h"

void readTrace(char* fileTrace, Trace *uneTrace) {
	int max, i = 0;
	FILE *fp = fopen(fileTrace, "r");
	if (fp == NULL) {
		fprintf(stderr, "%s nuk ekziston.\n", fileTrace);
		exit(1);
	}

	fscanf(fp, "%s", uneTrace->comment);
	fscanf(fp, "%d", &uneTrace->nbpts);

	max = uneTrace->nbpts;

	uneTrace->time = (float*) malloc(sizeof(float) * max);
	uneTrace->value = (float*) malloc(sizeof(float) * max);

	if (uneTrace->time == NULL || uneTrace->value == NULL) {
		printf("Failed to allocate memory for the trace\n");
	}

	while (i < max) {
		fscanf(fp, "%f", &uneTrace->time[i]);
		fscanf(fp, "%f", &uneTrace->value[i]);
		i++;
	}

	fclose(fp);
}



void printTrace(Trace uneTrace) {
	int i = 0, max = uneTrace.nbpts;
	printf("%s\n", uneTrace.comment);
	printf("%d\n", max);

	while(i < max) {
		printf("%.1f %.4f\n", *uneTrace.time, *uneTrace.value); 
		
		uneTrace.value++;
		uneTrace.time++;
		
		i++;
	}
}


void simulate(int tmax, float dt, float params[], Trace *uneTrace) {
	int i = 0, max;
	float v = 0, w = 0, dv = 0, dw = 0, t = 0;

	strcpy(uneTrace->comment, "Simulation");

	max = tmax/dt + 1;

	uneTrace->time = (float*) malloc(sizeof(float) * max);
	uneTrace->value = (float*) malloc(sizeof(float) * max);

	while (t <= tmax) {
		dv = (params[0] - v) * (v - 1) * v - w;
		dw = params[2] * (0.5 * v - w - params[1]);

		v += dv * dt;
		w += dw * dt;

		uneTrace->time[i] = t;
		uneTrace->value[i] = v;

		i++;
		t += dt;
	}
	uneTrace->nbpts = i;
}

/*
float errorTrace(Trace simTrace, Trace realTrace) {
	int n = simTrace.nbpts;
	int i;
	float sum = 0.0;
	float error;

	for (i = 0; i < n; i++) {
		sum += realTrace.value[i] - simTrace.value[i];
	}

	error = sum/n;
	if (error < 0) error = -error;
	
	return sqrt(error);
}

*/
void saveTraceBin(char* fileTrace, Trace uneTrace) {
	FILE *fp = fopen(fileTrace, "w+");
	int i = 0;
	if (fp == NULL) {
		fprintf(stderr, "Can't create %s\n", fileTrace);
		exit(1);
	}

	fprintf(fp, "%s\n", uneTrace.comment);

	while (i < uneTrace.nbpts) {
		fprintf(fp, "%f %f\n", uneTrace.time[i], uneTrace.value[i]);
		i++;
	}

	fclose(fp);
}