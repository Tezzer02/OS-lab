#include <stdio.h>
#include <pthread.h>

pthread_mutex_t lock;
int shared = 0;

void* func(void* arg) {
    pthread_mutex_lock(&lock);
    int t = shared;
    printf("Thread %ld read %d\n", pthread_self(), t);
    t += 1;
    shared = t;
    printf("Thread %ld updated to %d\n", pthread_self(), shared);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t t1,t2;
    pthread_mutex_init(&lock, NULL);
    pthread_create(&t1,NULL,func,NULL);
    pthread_create(&t2,NULL,func,NULL);
    pthread_join(t1,NULL); pthread_join(t2,NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}
