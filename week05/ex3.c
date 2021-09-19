#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *producer_job(void *arg);
void *consumer_job(void *arg);

int global = 0;

int main() {
	pthread_t producer;
	pthread_t consumer;

	pthread_create(&producer, NULL, producer_job, NULL);
	pthread_create(&consumer, NULL, consumer_job, NULL);

	sleep(10);

	return 0;
}

void *producer_job(void *arg) {
	while (1) {
		global += 1;
		sleep(1);
	}
}

void *consumer_job(void *arg) {
	while (1) {
		printf("The number: %d\n", global);
		sleep(1);
	}
}
