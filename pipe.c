#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "debug.h"

#define MAXLINE 256
#define FROM 0
#define TO 1

int main(int argc, char const *argv[])
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if (pipe(fd) < 0)
    {
        debug_error("Pipe error");
        exit(-1);
    }

    if ((pid = fork()) < 0)
    {
        debug_error("fork error");
        exit(-1);
    }
    else if (pid > 0)
    {
        close(fd[FROM]);
        write(fd[TO], "Hello PIPE\n", 12);
    }
    else
    {
        close(fd[TO]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }

    return 0;
}
