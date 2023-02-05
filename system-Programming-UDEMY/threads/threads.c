#include <pthread.h>
#include <stdio.h>

void *threadSafe(void *vargp){
	printf("Hello from the thread!\n");
}


int main()
{

	pthread_t id;
	printf("Not in the thread\n");
	pthread_create(&id, NULL, threadSafe, NULL);
	pthread_join(id, NULL);
	printf("After thread finished\n");

	return 0;
}
