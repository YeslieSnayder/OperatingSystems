#include <stdio.h>
#include <string.h>

void printFigure(char* figure, int size);
void printPyramid(int size);
void printTriangle(int size);
void printRhombus(int size);
void printSquare(int size);

int main(int argc, char *argv[]) {
	// Check the number of parameters
	if (!(argc == 2 || argc == 3)) {
		printf("Please, execute a program with 1 or 2 parameters!\n\n");
		printf("First parameter is a height of a figure.\n");
		printf("Second parameter (optional) is a type of a figure:\n'pyramid' (initial), 'triangle', 'rhombus', 'square'.\n\n");
		printf("Example 1: ./program 5\n");
		printf("Example 2: ./program 3 triangle\n");
		return -1;
	}

	// Convert the first parameter to int
	int n;
	if (!sscanf(argv[1], "%d", &n)) {
		printf("A type of parameter must be integer\n");
		return -1;
	}
	
	// Check the parameter to be positive
	if (n < 0) {
		printf("Parameter should be positive!\n");
		return -1;
	}

	// Print a figure
	char* figure = "pyramid";
	if (argc == 3)
		figure = argv[2];
	printFigure(figure, n);

	return 0;
}

/**
 * Print a special figure of a special size (height of a figure).
 *
 * @param figure - string that represents a type of a figure.
 * Now available only 4 types: 'pyramid', 'triangle', 'rhombus', 'square'.
 * @param size - height of a pyramid.
 **/
void printFigure(char* figure, int size) {
	if (strcmp(figure, "pyramid") == 0)
		printPyramid(size);
	else if (strcmp(figure, "triangle") == 0)
		printTriangle(size);
	else if (strcmp(figure, "rhombus") == 0)
		printRhombus(size);
	else if (strcmp(figure, "square") == 0)
		printSquare(size);
	else
		printf("The type of figure (%s) is not available!\n", figure);
}

/**
 * Print a pyramid of a special height.
 *
 * @param size - height of a pyramid.
 **/
void printPyramid(int size) {
	for (int i = 0; i < size; i++) {
		// Print spaces
		for (int j = 0; j < size-i-1; j++)
			printf(" ");

		// Print stars
		for (int j = 0; j < 2*i+1; j++)
			printf("*");
		printf("\n");
	}
}

/**
 * Print a right triangle of a special height.
 *
 * @param size - height of triangle.
 **/
void printTriangle(int size) {
	for (int i = 1; i <= size; i++) {
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}

/**
 * Print a rhombus of a special height.
 *
 * @param size - height of rhombus.
 **/
void printRhombus(int size) {
	// Print the first half of a rhomb
	for (int i = 1; i <= size / 2; i++) {
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
	// Print a middle part (if exists)
	if (size % 2 == 1) {
		for (int i = 0; i <= size / 2; i++)
			printf("*");
		printf("\n");
	}
	// Print the second half of a rhomb
	for (int i = size / 2; i > 0; i--) {
		for (int j = 0; j < i; j++)
			printf("*");
		printf("\n");
	}
}

/**
 * Print a square of a special size (height * height).
 *
 * @param size - size of square.
 **/
void printSquare(int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("*");
		printf("\n");
	}
}
