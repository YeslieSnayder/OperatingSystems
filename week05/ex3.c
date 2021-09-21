#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *producer_job(void *arg);
void *consumer_job(void *arg);

/**
 * Variable that will be changed by producer
 * and used by consumer.
 */
int global = 0;

int main() {
	pthread_t producer;
	pthread_t consumer;

	pthread_create(&producer, NULL, producer_job, NULL);
	pthread_create(&consumer, NULL, consumer_job, NULL);

	sleep(121);
	printf("Final number: %d\n", global);

	return 0;
}

/**
 * Method that the producer will execute.
 * Changes the global variable. +10 every second.
 */
void *producer_job(void *arg) {
	while (1) {
		global += 1;
		usleep(100000);
	}
}

/**
 * Method that the consumer will execute.
 * Prints the global variable every 60 seconds.
 */
void *consumer_job(void *arg) {
	while (1) {
		printf("The number: %d\n", global);
		sleep(60);
	}
}
