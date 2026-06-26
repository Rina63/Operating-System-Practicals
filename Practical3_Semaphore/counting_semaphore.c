#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* worker(void* arg) {
    int id = *(int*)arg;

    sem_wait(&sem);

    printf("Thread %d entered critical section\n", id);
    sleep(2);

    printf("Thread %d leaving critical section\n", id);

    sem_post(&sem);

    return NULL;
}

int main() {
    pthread_t threads[5];
    int ids[5];

    // Allow 3 threads at a time
    sem_init(&sem, 0, 3);

    for (int i = 0; i < 5; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);

    return 0;
}
