#include <stdio.h>
#include <string.h>

#define SIZE 256	// Max size of a sentence

void reverse(char* str, int size);

int main() {
	char s[SIZE];	// Variable for a sentence

	printf("Please, enter a string (max size 200 characters):\n");
	fgets(s, SIZE, stdin);	// Listening user

	reverse(s, strlen(s));	// Reverse a string

	printf("Reversed sentence:%s\n", s);
	
	return 0;
}

/**
 * A function that reverses input string.
 *
 * @param str - a pointer that points to a first element of an array of chars.
 * @param size - a size of input string.
 **/
void reverse(char* str, int size) {
	if (size <= 1)
		return;
	
	char* begin = str;
	char* end = &str[size-1];
	
	for (int i = 0; i < size / 2; i++) {
		char t = *begin;
		*begin = *end;
		*end = t;

		begin++; end--;
	}
}

