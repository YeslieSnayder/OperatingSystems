#include <stdlib.h>
#include <stdio.h>

// Max size of a command
#define SIZE 1024

int main() {
	printf("Press CTRL+C to stop:\n");
	while (1) {
		printf("> ");
		char cmd[SIZE];
		fgets(cmd, SIZE, stdin);
		system(cmd);
	}
}
