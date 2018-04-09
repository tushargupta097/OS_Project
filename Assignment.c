#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <pthread.h>
#define MIN_PID 300
#define MAX_PID 5000
int threadCount = 1;
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

int allocate_pid()                             
{

	int j=1;
       while(j>=0)
	{
	   if(pidArr[j].bitmap == 0)
        {
           	if(j<threadCount)
			{
        		pidArr[threadCount].pid=pidArr[j].pid;
        		pidArr[j].bitmap = 1;
        		pidArr[threadCount].bitmap=1;
	 		return 0;
			}
			else
			{  
	    
            pidArr[j].pid = tid;
            tid+=1;
            pidArr[j].bitmap = 1;  
            return tid ;
        	}		
    	}j++;
	}
}

void release_pid(int pid)                              
{
	printf("\n------------------------------------------------------------------------------");
	printf("\n\nProcess %d finished, releasing its process id.\n",pid);
	sleep(2);
    printf("\n\nprocess id for process %d released: %d\n",pid,pidArr[pid].pid);
    pidArr[pid].bitmap = 0;
}

void * threadCall(void* voidA )                       
{	   // sleep(1);
printf("\n\nProcess Number: %d",threadCount);
        pthread_mutex_lock(&mutex);  

		sleep(3);
		allocate_pid();   
        
		        
        printf("\n------------------------------------------------------------------------------");

        

        printf("\n\nProcess Id Allocated %d to process: %d\n",pidArr[threadCount].pid,threadCount);
    	sleep(2);

		threadCount++;
        
		if (threadCount == 21)
       		{
       		printf("\n------------------------------------------------------------------------------");
       		
       		printf("\n\t\t********Process release initiated*******\n");
       		
       		sleep(1);
       		
			release_pid(10);
       		
			release_pid(11);
			
			release_pid(13);
       		}
       		if (threadCount == 31)
       		{
       		printf("\n------------------------------------------------------------------------------");

       		printf("\n\t\t********Process release initiated*******\n");
       		
			sleep(1);
			           
			release_pid(1);
       		
			release_pid(2);
			
			release_pid(21);
       		}
       		  pthread_mutex_unlock(&mutex); 
}
void exec()
{
		int z =0;
		pthread_t thread[100];
		pthread_mutex_init(&mutex, NULL);
		allocate_map();
		for( z=0;z<100;z++)
		{

			pthread_create(&thread[z], NULL, threadCall, NULL);
			sleep(5);
			//printf("thread[%d]",z);
		}
		for(z=0;z<100;z++)
		{
		pthread_join(thread[z], NULL);
        }
}
int main()
{
    printf("\n\t\t********* Thread Creation initiated.*********");
    sleep(2); 
	printf("\n\nProcesses will be given process id's and locks are used to avoid race condition.");      
	sleep(3);
    exec();
}
