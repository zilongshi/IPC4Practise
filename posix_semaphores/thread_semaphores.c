#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "../sys/debug.h"

sem_t sem;

void *thread(void *dummy)
{
    sleep(1);
    debug_info("new thread posting\n");
    sem_post(&sem);

    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t pid;
    pthread_create(&pid, NULL, thread, NULL);
    sem_init(&sem, 0, 0);

    sem_wait(&sem);
    debug_info("main thread wait succeed\n");
    sem_post(&sem);

    sem_destroy(&sem);

    pthread_join(pid, NULL);

    return 0;
}
