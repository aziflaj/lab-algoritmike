#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "trace.h"

void readTrace(char* fileTrace, Trace* uneTrace) {
	FILE *fp = fopen(fileTrace, "r");
	int i = 0;
	if (fp == NULL) {
		fprintf(stderr, "%s nuk ekziston.\n", fileTrace);
		exit(1);
	}

	fscanf(fp, "%s", uneTrace->comment);

	while (i < MAX_RECORDS && !feof(fp)) {
		fscanf(fp, "%f", &uneTrace->time[i]);
		fscanf(fp, "%f", &uneTrace->value[i]);
		i++;
	}

	uneTrace->nbpts = i; 

	fclose(fp);
}


void printTrace(Trace uneTrace) {
	int i = 0;

	printf("%s\n", uneTrace.comment);
	while(i < uneTrace.nbpts) {
		printf("%.1f %.4f\n", uneTrace.time[i], uneTrace.value[i]);
		i++;
	}

}

void simulate(int tmax, float dt, float params[], Trace *uneTrace) {
	int i = 0;
	float v = 0, w = 0, dv = 0, dw = 0, t = 0;

	strcpy(uneTrace->comment, "Simulation");

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