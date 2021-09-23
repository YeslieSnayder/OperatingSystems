#include <stdio.h>
#include <stdlib.h>


#define FILEPATH "./input.csv"


/**
 * Structure that represents a process.
 */
typedef struct {
	int arrival;	// Arrival time
	int burst;	// Burst time
	int CT;		// Completion time
	int TAT;	// Turnaround time
	int WT;		// Waiting time
} Proc;

Proc** get_processes(int *size);
void fcfs(Proc** pcs, int size);
void printpcs(Proc** pcs, int size, double avgTT, double avgWT);

/**
 * MAIN FUNCTION
 */
int main() {
	int size;
	Proc** pcs = get_processes(&size);
	if (pcs == NULL)
		return -1;
	fcfs(pcs, size);
}

/**
 * Bubble sort
 */
int sort(Proc** pcs, int size) {
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = size - 1; j > i; j--) {
			if (pcs[j]->arrival < pcs[j-1]->arrival) {
				flag = 1;
				Proc temp = *pcs[j];
				*pcs[j] = *pcs[j-1];
				*pcs[j-1] = temp;
			}
		}
		if (!flag) break;
	}
}

/**
 * Algorithm of scheduling: first come, first served (FCFS)
 */
void fcfs(Proc** pcs, int size) {
	sort(pcs, size);
	
	double avgTT = 0, avgWT = 0;
	
	int time = pcs[0]->arrival;
	for (int i = 0; i < size; i++) {
		time = (time > pcs[i]->arrival) ? time : pcs[i]->arrival;
		pcs[i]->CT = time + pcs[i]->burst;
		pcs[i]->WT = time - pcs[i]->arrival;
		pcs[i]->TAT = pcs[i]->burst + pcs[i]->WT;
		time += pcs[i]->burst;
		
		avgTT += pcs[i]->TAT;
		avgWT += pcs[i]->WT;
	}
	printpcs(pcs, size, avgTT/size, avgWT/size);
}

/**
 * Prints array of processes, their properties,
 * average turnaround time, and average waiting time.
 *
 * @param pcs - an array of pointers to processes.
 * @param size - a size of the array.
 * @param avgTT - average turnaround time (of all processes in the array).
 * @param avgWT - average waiting time (of all processes in the array).
 */
void printpcs(Proc** pcs, int size, double avgTT, double avgWT) {
	printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
	for (int i = 0; i < size; i++) {
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i, pcs[i]->arrival, pcs[i]->burst, pcs[i]->CT, pcs[i]->TAT, pcs[i]->WT);
	}
	printf("\nAverage Turnaround Time = %lf\n", avgTT);
	printf("Average WT = %lf\n", avgWT);
}

/**
 * Convert CSV-file and returns an array of pointers to struct Proc.
 * File has to be formated in this way: "arrival_time,burst_time".
 * The constants arrival_time and burst_time have to be separated by comma (,)
 * without spaces.
 */
Proc** get_processes(int *size) {
	Proc** processes = (Proc**) malloc(sizeof(Proc*) * 10);
	
	FILE *fp;
	int arrival, burst, count = 0;
	
	fp = fopen(FILEPATH, "r");
	if (fp == NULL) {
		printf("ERROR: File %s has to be in same directory with executable\n", FILEPATH);
		return NULL;
	}
	while (fscanf(fp, "%d,%d", &arrival, &burst) == 2) {
		if (count == 10) break;
		
		processes[count] = (Proc*) malloc(sizeof(Proc));
		processes[count]->arrival = arrival;
		processes[count]->burst = burst;
		count++;
	}
	if (feof(fp) || count == 10) {
		if (count < 10)
			processes[count] = NULL;
		*size = count;
		return processes;
	} else {
		printf("Error while reading file '%s'\n", FILEPATH);
		return NULL;
	}
}
