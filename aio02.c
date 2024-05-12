#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <aio.h>
#include <string.h>
#include <errno.h>

#define SIZE_TO_READ 1048576 // 1MB
#define BUFFER_SIZE 1

int main() {
    int fd = open("/dev/random", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
	
	char* buffer = malloc(BUFFER_SIZE);
    if (buffer == NULL) {
        perror("malloc");
        return 1;
    }

    struct aiocb cb;
    memset(&cb, 0, sizeof(struct aiocb));
    cb.aio_nbytes = BUFFER_SIZE;
    cb.aio_fildes = fd;
    cb.aio_buf = buffer;
	
	for (int i = 0; i < SIZE_TO_READ; i++) {
        cb.aio_offset = i;
        if (aio_read(&cb) == -1) {
            printf("Unable to create request: \n");
            close(fd);
            return 1;
        }

        while (aio_error(&cb) == EINPROGRESS) {
        }

        int numBytes = aio_return(&cb);
        if (numBytes != -1) {
            printf("Number of bytes read: %d\n", numBytes);
        } else {
            printf("Error occurred: \n");
        }
		

    }

    free(buffer);
    close(fd);
    return 0;
}