#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../sys/debug.h"

#define FIFO "/tmp/my_fifo"

int main(int argc, char** argv)
{ 
    char receive_buff[100];
    int fd;
    int nread;

    if ((mkfifo(FIFO, O_CREAT) < 0) && (errno != EEXIST))
    {
        debug_error("Cannot create FIFO\n");
        exit(1);
    }

    debug_info("Prepare reading data\n");
    fd = open(FIFO, O_RDONLY | O_NONBLOCK, 0);
    if (fd == -1)
    {
        debug_error("Open FIFO\n");
        exit(1);
    }
    long int number_of_read = 0;

    while (1)
    {
        if ((nread = read(fd, receive_buff, 100)) == -1)
        {
            if (errno == EAGAIN)
                debug_error("There is NO data\n");
        }

        if (receive_buff[0] == 'Q')
            break;

        receive_buff[nread] = 0;
        number_of_read++;
        debug_info("Read data [%ld] from FIFO : %s\n", number_of_read, receive_buff);

        sleep(1);
    }

    return 0;
}
