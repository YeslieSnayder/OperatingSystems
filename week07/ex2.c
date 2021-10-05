#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		printf("Please, provide a parameter to program.\n");
		return -1;
	}
	int n;
	sscanf(argv[1], "%d", &n);

	if (n < 0) {
		printf("The number has to be positive!\n");
		return -1;
	}

	int* arr = (int*) malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		arr[i] = i;

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	free(arr);
	return 0;
}
