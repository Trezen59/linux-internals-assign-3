#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void* t_func(void* args)
{
	printf("in thread\n\n");
	
	pthread_cancel(pthread_self());
	
}

int main(){
		
	pthread_t tid;
	
	int n = pthread_create(&tid, NULL, t_func, NULL);
	
	if(n == 0)
		printf("thread created successfully\n\n");
	else
		printf("error\n\n");
		
	pthread_join(tid, NULL);
	
	pthread_exit(NULL);
		
		
return 0;
}
