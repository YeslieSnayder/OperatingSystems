#include <stdio.h>

void swap(int* first, int* second);
void printNums(int a, int b);
int convert(int* a, int* b, char* argv[]);

int main(int argc, char* argv[]) {
	// Check the number of parameters
	if (argc != 3) {
		printf("Please, execute a program with only 2 integer parameters!\n");
		return -1;
	}

	// Convert parameters to integer
	int a, b;
	if (convert(&a, &b, argv))
		return -1;
	
	printNums(a, b);
	swap(&a, &b);	// Swap 2 integers
	printNums(a, b);

	return 0;
}

/**
 * Swap two integers by using XOR operations.
 *
 * @param first - a pointer to the first integer.
 * @param second - a pointer to the second integer.
 **/
void swap(int* first, int* second) {
	*first = *first ^ *second;
	*second = *first ^ *second;
	*first = *first ^ *second;
}

/**
 * Print numbers to a console.
 **/
void printNums(int a, int b) {
	printf("First number = %d\n", a);
	printf("Second number = %d\n", b);
}

/**
 * Convert array of chars to integers and returns a result.
 *
 * @param a, b - integers which will contain values from char array.
 * @param argv - an array of characters which contains numbers.
 * @return	0 - If conversion was successfull,
 * 		1 - If convertion was unsuccessfull.
 **/
int convert(int* a, int* b, char* argv[]) {
	if (!sscanf(argv[1], "%d", a)) {
		printf("A type of parameters should be integer\n");
		return -1;
	}
	if (!sscanf(argv[2], "%d", b)) {
		printf("A type of parameters should be integer\n");
		return -1;
	}
	return 0;
}
