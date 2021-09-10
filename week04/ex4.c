#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


// Character limit for command
#define SIZE 1024

// Limit for array of arguments
#define ARGV_SIZE 64

// Path to the shell program
#define SHELL "/bin/sh"


int main() {
	printf("To exit press CTRL+C:\n");
	
	char cmd[SIZE];		// Command from user
	char* argv[ARGV_SIZE];	// List of arguments
	argv[0] = SHELL;
	argv[1] = "-c";
	argv[3] = NULL;
	
	while(1) {
		printf("> ");
		fgets(cmd, SIZE, stdin);
		argv[2] = cmd;

		int is_back = 0;	// flag for mode (0 - foreground, 1 - background)
		int count = 0;
		while (cmd[count] != '\0' && cmd[count] != '\n') count++;
		if (count > 1)
			is_back = cmd[count-2] == '&';

		pid_t pid = fork();
		int status;
		if (pid < 0) {
			printf("ERROR: fork returns error\n");
			exit(1);
		} else if (pid == 0) {
			if (execvp(SHELL, argv) < 0) {
				printf("ERROR: execvp returns error\n");
				exit(1);
			}
		} else if (!is_back) {
			// If process should be launched in foreground
			while (wait(&status) != pid);
		}
	}
	return 0;
}
