#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <semaphore.h>
#include "../sys/debug.h"

#define SEM_NAME "/test_semaphores"

void parent()
{
    sem_t *sem;
    sem_unlink(SEM_NAME);

    sem = sem_open(SEM_NAME, O_CREAT | O_EXCL, 0666, 0);
    if (sem == SEM_FAILED)
    {
        sem = sem_open(SEM_NAME, 0);
        if (sem == SEM_FAILED)
        {
            perror("sem_open\n");
            return;
        }

    }

    sem_wait(sem);
    debug_info("parent wait succeded\n");
    sem_post(sem);

    sem_close(sem);
    sem_unlink(SEM_NAME);
}

void child()
{
    sem_t *sem;
    sem = sem_open(SEM_NAME, 0);
    if (sem == SEM_FAILED)
    {
        perror("sem_open\n");
    }

    sleep(1);
    debug_info("child going to post\n");
    sem_post(sem);
}

int main(int argc, char const *argv[])
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0)
    {
        debug_error("fork error\n");
        exit(-1);
    }
    else if (pid > 0)
    {
        parent();
        wait(&status);
    }
    else
    {
        child();
    }

    exit(0);

}
