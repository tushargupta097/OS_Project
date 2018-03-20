#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void * threadcall(void * P){
	
	while(thread<100)
	{
        pthread_mutex_lock(&mutex);     
        if (thread >= 100)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
		thread++;
	pthread_mutex_unlock(&mutex);
}
	
}
int main()
{
    pthread_t thread[50];
    
    for(i = 0; i < 100; i++)
    {
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&thread[i], NULL, threadCall, NULL);
        threadCall(NULL);
    }
}
		
		
