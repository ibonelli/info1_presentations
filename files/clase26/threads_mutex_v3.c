/*
 * threads_mutex_v2.c - compile with:
 *           gcc -o threads_m2 threads_mutex_v2.c -lpthread
 */

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void *doSomeThing(void *arg) {
    unsigned long i = 0;

    pthread_t id = pthread_self();

    if(pthread_equal(id,tid[0])) {
        printf("\n First thread in parallel 1st block started pthread_t %ld\n", id);
    } else {
        printf("\n Second thread in parallel 1st block started pthread_t %ld\n", id);
    }

    for(i=0; i<(0x0FFFFFFF);i++);

    if(pthread_equal(id,tid[0])) {
        printf("\n First thread in parallel 1st block finished pthread_t %ld\n", id);
    } else {
        printf("\n Second thread in parallel 1st block finished pthread_t %ld\n", id);
    }

    pthread_mutex_lock(&lock);
    counter += 1;

    printf("\n Job %d started\n", counter);

    for(i=0; i<(0x0FFFFFFF);i++);

    printf("\n Job %d finished\n", counter);

    pthread_mutex_unlock(&lock);

    if(pthread_equal(id,tid[0])) {
        printf("\n First thread in parallel 2nd block started pthread_t %ld\n", id);
    } else {
        printf("\n Second thread in parallel 2nd block started pthread_t %ld\n", id);
    }

    for(i=0; i<(0x0FFFFFFF);i++);

    if(pthread_equal(id,tid[0])) {
        printf("\n First thread in parallel 2nd block finished pthread_t %ld\n", id);
    } else {
        printf("\n Second thread in parallel 2nd block finished pthread_t %ld\n", id);
    }

    return NULL;
}

int main(void) {
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("\n mutex init failed\n");
        return 1;
    }

    while(i < 2) {
        err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
