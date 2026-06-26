#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <semaphore.h>

#define SHM_SIZE 1024

int main() {
    int shmid;
    char *shared_memory;
    sem_t sem;

    // Initialize semaphore
    sem_init(&sem, 1, 0);

    // Create shared memory segment
    shmid = shmget(IPC_PRIVATE, SHM_SIZE, IPC_CREAT | 0666);

    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        shared_memory = (char *)shmat(shmid, NULL, 0);

        sem_wait(&sem);

        printf("Child read: %s\n", shared_memory);

        shmdt(shared_memory);
        exit(0);
    }
    else {
        // Parent process
        shared_memory = (char *)shmat(shmid, NULL, 0);

        strcpy(shared_memory, "Hello from Parent Process!");

        printf("Parent wrote: %s\n", shared_memory);

        sem_post(&sem);

        wait(NULL);

        shmdt(shared_memory);
        shmctl(shmid, IPC_RMID, NULL);
        sem_destroy(&sem);
    }

    return 0;
}
