/*
*******************************************************************************************************************************************
 *Purpose/Description:		This is a program that is based on the use of multithreading. Your goal is to create 10 different threads, 
			which will share one variable. Each thread must block the shared variable so that no other thread can modify it at 
			the same time, then use a for loop that loops 6 times and each time it increases the shared variable by an amount 
			equal to the thread ID. When each thread finishes executing the loop, it should show a message saying that it is 
			finished and showing its TID. Finally, the program shows the final value of the shared variable.

 * Author’s Name: Jose Aparicio
 * Author’s Panther ID: 6186111 
 * Certification: I hereby certify that this work is my own and none of it is the work of any other person.
*********************************************************************************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define loop 6											//variable to loop 


typedef struct _thread_data_t {									//create thread argument struct for thr_func()
	 int tid;
} thread_data_t;


double shared_x;										//shared data between threads
pthread_mutex_t lock_x;

void *thr_func(void *arg) {
	int i;											//variable to be used in the for loop
        thread_data_t *data = (thread_data_t *)arg;
        pthread_mutex_lock(&lock_x);								//get mutex before modifying and printing shared_x					
        for(i=0;i<loop;i++)									//looping 6 times
                shared_x += data->tid;
        printf("Thread [%d] has finished!\n", data->tid);
        pthread_mutex_unlock(&lock_x);

        pthread_exit(NULL);
}




int main(int argc, char **argv) {
	printf("\n");						
	pthread_t thr[NUM_THREADS];
	int i, rc;
  	thread_data_t thr_data[NUM_THREADS];							//create a thread_data_t argument array

  	shared_x = 0;										//initialize shared data
  	
	pthread_mutex_init(&lock_x, NULL);							//initialize pthread mutex protecting "shared_x"

  	for (i = 0; i < NUM_THREADS; ++i) {							//create threads
    		thr_data[i].tid = i;
    		if ((rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]))) {
      			fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
      			return EXIT_FAILURE;
    		}
  	}
  	/*  */
  	for (i = 0; i < NUM_THREADS; ++i) {							//block until all threads complete
    		pthread_join(thr[i], NULL);
  	}
	printf("Final Value: %lf\n\n",shared_x);						//displaying the final value of shared_x

  	return EXIT_SUCCESS;
}
