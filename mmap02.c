
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Netinkamas argumentu kiekis");
        return 1;
    }

    int src = open(argv[1], O_RDONLY);
    if (src == -1) {
        perror("open");
        return 1;
    }
	 int dest = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        perror("open");
        return 1;
    }
	
	struct stat st;
    if (fstat(src, &st) == -1) {
        perror("fstat");
        return 1;
    }
	
	if (ftruncate(dest, st.st_size) == -1) {
        perror("ftruncate");
        return 1;
    }
	void *src_map = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, src, 0);
    if (src_map == MAP_FAILED) {
        perror("mmap");
        return 1;
    }
	void *dest_map = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest, 0);
    if (dest_map == MAP_FAILED) {
        perror("mmap");
        return 1;
    }

    memcpy(dest_map, src_map, st.st_size);

    munmap(src_map, st.st_size);
    munmap(dest_map, st.st_size);

    close(src);
    close(dest);

    return 0;
}