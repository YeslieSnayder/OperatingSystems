#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("Integer = %d\nFloat = %f\nDouble = %f\n", INT_MAX, FLT_MAX, DBL_MAX);
	printf("Sizeof integer = %lu\n", sizeof(int));
	printf("Sizeof float = %lu\n", sizeof(float));
	printf("Sizeof double = %lu\n", sizeof(double));

	return 0;
}
