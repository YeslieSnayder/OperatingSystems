#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_func(int *num);

const int N = 4;

int main() {
	pthread_t threads[N];
	for (int i = 0; i < N; i++) {
		printf("Thread %d was created!\n", i);
		pthread_create(&threads[i], NULL, thread_func, &i);
		pthread_join(threads[i], NULL);
		printf("Thread %d was terminated!\n", i);
	}
	return 0;
}

void *thread_func(int *num) {
	printf("Thread %d is processing...\n", *num);
	return NULL;
}
