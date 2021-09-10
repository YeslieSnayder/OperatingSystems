#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * Creates new child process and prints special text
 * for child and parent processes.
 **/
int main() {
	int pid = fork();
	int n = 123;
	if (pid == 0) {
		printf("Hello from child[PID: %d - N: %d]\n", pid, n);
	} else {
		printf("Hello from parent[PID: %d - N: %d]\n", pid, n);
	}
	return 0;
}
