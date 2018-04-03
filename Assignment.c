#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int MIN_PID=300;
int MAX_PID=5000;
pthread_mutex_t mutex;
int tid = 300;
struct pid_tab
{
    int pid;
    bool bitmap;
}pidArr[4700];
int allocate_map(void)                                
{
    int i,j;
    for(i = MIN_PID, j =0; i <= MAX_PID; i++, j++)
    {
        pidArr[j].bitmap = 0;
    }
    if(i == MAX_PID && j == 4700)
    return 1;
}


void * threadcall(void * P){
	
        pthread_mutex_lock(&mutex);     
        if (thread >= 100)
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
		thread++;
	pthread_mutex_unlock(&mutex);
}

	
void release_pid(int pid)                              
{
	int i=0;
    for( i = 0; i <= 4700; i++)
    {
        if(pidArr[i].pid == pid)
        {
        	printf("\npid released: %d",pidArr[i].pid);
            pidArr[i].bitmap = 0;
            
        } 
    }
    
}

}
int main()
{
    pthread_t thread[50];
    allocate_map();
    for(i = 0; i < 100; i++)
    {
        pthread_mutex_init(&mutex, NULL);
        pthread_create(&thread[i], NULL, threadCall, NULL);
        threadCall(NULL);
    }
}
		
		
