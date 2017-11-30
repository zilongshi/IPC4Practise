#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>

#define BUFFER_SIZE 10

int main(int argc, char const *argv[])
{
    int n;
    int fd[2];
    pid_t pid;

    char send_buffer[BUFFER_SIZE] = "welcome!";
    char receive_buffer[BUFFER_SIZE];

    memset(receive_buffer, 0, sizeof(receive_buffer));

    if (pipe(fd) == -1)
    {
        fprintf(stderr, "pipe: %s\n", strerror(errno));
        exit(1);
    }

    if ((pid == fork()) < 0)
    {
        fprintf(stderr, "fork: %s\n", strerror(errno));
        exit(1);
    }
    else if (pid > 0)
    {
        close(fd[0]);
        write(fd[1], send_buffer, BUFFER_SIZE);
        printf("parent process %d send: %s\n", getpid(), send_buffer);
    }
    else
    {
        close(fd[1]);
        read(fd[0], receive_buffer, BUFFER_SIZE);
        printf("child process %d receive: %s\n", getpid(), receive_buffer);
    }

    return 0;
}
