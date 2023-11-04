/*
 * gcc -o PiNI Pi_NI.c -lpthread -lm
 */

#include <stdio.h>
#include <math.h>
#include <pthread.h>

#define NUM_RECT 10000000
#define NUMTHREADS 4

double gPi = 0.0;  //  global accumulator for areas computed
pthread_mutex_t gLock;

void *Area(void *pArg){
	int myNum = *((int *)pArg);
	double h = 2.0 / NUM_RECT;
	double partialSum = 0.0, x;  // local to each thread

	// use every NUMTHREADS-th ste
	for (int i = myNum; i < NUM_RECT; i += NUMTHREADS){
		x = -1 + (i + 0.5f) * h;
		partialSum += sqrt(1.0 - x*x) * h;
	}
	pthread_mutex_lock(&gLock);
	gPi += partialSum;  // add partial to global final answer
	pthread_mutex_unlock(&gLock);
	return 0;
}

int main(int argc, char **argv) {

pthread_t tHandles[NUMTHREADS]; int tNum[NUMTHREADS], i;
pthread_mutex_init(&gLock, NULL);

for ( i = 0; i < NUMTHREADS; ++i ) {
	tNum[i] = i;
	pthread_create(&tHandles[i],		// Returned thread handle
					NULL,				// Thread Attributes
					Area,				// Thread function
					(void*)&tNum[i]);	// Data for Area()
}

for ( i = 0; i < NUMTHREADS; ++i ) {
   pthread_join(tHandles[i], NULL);
}

gPi *= 2.0;
printf("Computed value of Pi:  %12.9f\n", gPi );

pthread_mutex_destroy(&gLock);

return 0;
}
