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
void round_robin(Proc** pcs, int size, int quantum);
void printpcs(Proc** pcs, int size, double avgTT, double avgWT);


/**
 * MAIN FUNCTION
 */
int main(int argc, char** argv) {
	if (argc != 2) {
		printf("Please, provide quantum as parameter of the program!\n");
		return -1;
	}
	int quant;
	sscanf(argv[1], "%d", &quant);

	int size;
	Proc** pcs = get_processes(&size);
	if (pcs == NULL)
		return -1;
	round_robin(pcs, size, quant);
}

/**
 * Bubble sort
 */
int sort(Proc** pcs, int size) {
	for (int i = 0; i < size; i++) {
		int flag = 0;
		for (int j = i+1; j < size; j++) {
			if (pcs[j-1]->arrival > pcs[j]->arrival) {
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
 * Algorithm of scheduling: Round robin.
 */
void round_robin(Proc** pcs, int size, int quantum) {
	sort(pcs, size);
	
	double avgTT = 0, avgWT = 0;
	int time = size > 0 ? pcs[0]->arrival : 0, pcsnum = size, is_done = 0;
	int temp[size];
	for (int i = 0; i < size; i++)
		temp[i] = pcs[i]->burst;
	
	for (int i = 0; pcsnum != 0; ) {
		if (temp[i] <= quantum && temp[i] > 0) {
			time += temp[i];
			temp[i] = 0;
			is_done = 1;
		} else if (temp[i] > 0) {
			temp[i] -= quantum;
			time += quantum;
		}
		if (temp[i] == 0 && is_done) {
			pcsnum--;
			is_done = 0;
			pcs[i]->CT = time;
			pcs[i]->TAT = time - pcs[i]->arrival;
			pcs[i]->WT = pcs[i]->TAT - pcs[i]->burst;
			
			avgTT += pcs[i]->TAT;
			avgWT += pcs[i]->WT;
			
			if (i < size-1 && pcs[i+1]->arrival > time)
				time = pcs[i+1]->arrival;
		}
		if (i == size-1) i = 0;
		else if (pcs[i+1]->arrival <= time) i++;
		else i = 0;
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
