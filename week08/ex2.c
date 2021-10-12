#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define M_10MB 10 * 1024 * 1024

int main() {
	int* ptr;
	for (int i = 1; i <= 10; i++) {
		ptr = malloc(M_10MB);
		memset(ptr, 0, M_10MB);
		sleep(1);
	}
	return 0;
}
