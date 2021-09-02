#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int* arr, int size);
int* generate_array(int size);
void print_arr(int* arr, int size);

#define INITIAL_SIZE 10
#define MAX_VALUE 1000

/**
 * MAIN function
 **/
int main(int argc, char** argv) {
	int size = INITIAL_SIZE;
	if (argc == 2)
		sscanf(argv[1], "%d", &size);

	int* arr = generate_array(size);

	printf("Initial array: ");
	print_arr(arr, size);

	bubble_sort(arr, size);

	printf("Sorted array:  ");
	print_arr(arr, size);
}

/**
 * Swaps values of 2 integers.
 **/
void swap(int* a, int* b) {
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

/**
 * Sort an array with given size by using bubble sort algorithm.
 * Sorting algorithm is in-place.
 * 
 * @param arr - pointer to first element of the array that will be sorted.
 * @param size - a size of the array.
 **/
void bubble_sort(int* arr, int size) {
	for (int i = size - 1; i > 0; i--) {
		int flag = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j+1]) {
				swap(&arr[j], &arr[j+1]);
				flag = 0;
			}
		}
		if (flag) return;
	}
}

/**
 * Generate an array of random integers.
 * 
 * @param size - a size of generated array.
 * @return a pointer to the first element of the array with given size.
 **/
int* generate_array(int size) {
	int* arr = (int*) malloc(size * sizeof(int));
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % MAX_VALUE;
	}
	return arr;
}

/**
 * Prints an array.
 *
 * @param arr - pointer to first element of the array (array itself).
 * @param size - a size of the array.
 **/
void print_arr(int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}
