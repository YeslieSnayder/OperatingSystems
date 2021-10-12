#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/resource.h>
#include <stdio.h>

// macro for 1000 MB of memory
#define M_1000MB 1000 * 1024 * 1024

void print_statistics(int i) {
	printf("\nITERATION: %d\n", i);

	struct rusage* usage;
	getrusage(RUSAGE_SELF, usage);
	printf("user CPU time used:\t\t %lu\nsystem CPU time used:\t\t %lu\nmaximum resident set size:\t %lu\n", usage->ru_utime.tv_sec, usage->ru_stime.tv_sec, usage->ru_maxrss);
	printf("integral shared memory size:\t %lu\nintegral unshared data size:\t %lu\nintegral unshared stack size:\t %lu\n", usage->ru_ixrss, usage->ru_idrss, usage->ru_isrss);
	printf("page reclaims(soft page faults)\t %lu\npage faults (hard page faults):\t %lu\nswaps:\t\t\t\t %lu\n", usage->ru_minflt, usage->ru_majflt, usage->ru_nswap);
	printf("block input operations:\t\t %lu\nblock output operations:\t %lu\nIPC messages sent:\t\t %lu\n", usage->ru_inblock, usage->ru_oublock, usage->ru_msgsnd);
	printf("IPC messages received:\t\t %lu\nsignals received:\t\t %lu\nvoluntary context switches:\t %lu\n", usage->ru_msgrcv, usage->ru_nsignals, usage->ru_nvcsw);
	printf("involuntary context switches:\t %lu\n", usage->ru_nivcsw);
}

int main() {
	int* ptr;
	for (int i = 1; i <= 10; i++) {
		ptr = malloc(M_1000MB);
		memset(ptr, 0, M_1000MB);
		print_statistics(i);
		sleep(1);
	}
	return 0;
}
