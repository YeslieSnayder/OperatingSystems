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
void sjf(Proc** pcs, int size);
void printpcs(Proc** pcs, int size, double avgTT, double avgWT);

/**
 * MAIN FUNCTION
 */
int main() {
	int size;
	Proc** pcs = get_processes(&size);
	if (pcs == NULL)
		return -1;
	sjf(pcs, size);
}

int compareArrival(const Proc* a, const Proc* b) {
	if (a->arrival > b->arrival) return 1;
	return 0;
}

int compareBurst(const Proc* a, const Proc* b) {
	if (a->burst > b->burst) return 1;
	return 0;
}

/**
 * Bubble sort
 */
int bsort(Proc** pcs, int size, int start, int end, int (*cmp)(const Proc*, const Proc*)) {
	if (end > size) end = size;
	for (int i = start; i < end; i++) {
		int flag = 0;
		for (int j = end - 1; j > i; j--) {
			if (cmp(pcs[j-1], pcs[j])) {
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
 * Algorithm of scheduling: shortest job next (SJN) / shortest job first (SJF)
 * It sorts subarray of current processes by burst time.
 * Computational time: O(n^3)
 */
void sjf(Proc** pcs, int size) {
	bsort(pcs, size, 0, size, compareArrival);
	
	double avgTT = 0, avgWT = 0;
	int time = 0;
	
	int si = 0;	// Time index
	for (int i = 0; i < size; i++) {
		int needSort = 0;
		while (si < size && pcs[si]->arrival <= time) {
			si++; needSort = 1;
		}
		if (needSort) bsort(pcs, size, i, si, compareBurst);
		
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
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i,
			pcs[i]->arrival, pcs[i]->burst,
			pcs[i]->CT, pcs[i]->TAT, pcs[i]->WT);
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
