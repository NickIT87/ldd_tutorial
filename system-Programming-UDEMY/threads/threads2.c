#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *ThreadSafe(void *args)
{
	int *threadId = (int *)args;
	printf("Hello from Thread: %d\n",*threadId);

}

int main()
{

	int i,j;
	int NUM_THREADS = 10;

	pthread_t threads[NUM_THREADS];
	int thread_args[NUM_THREADS];

	printf("Before thread!\n");

	// Creating 10 threads
	for(i = 0; i < NUM_THREADS; i++)
	{
	thread_args[i] = i;
	pthread_create(&threads[i],NULL,ThreadSafe, (void *)&thread_args[i]);
	}

	// Waiting for 10 threads to finsih
	for(j = 0; j < NUM_THREADS; j++)
	{
	pthread_join(threads[j],NULL);
	}

	printf("After thread!\n");

	pthread_exit(NULL);

	
	return 0;
}
