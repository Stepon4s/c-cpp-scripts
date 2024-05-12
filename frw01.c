
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUFFLEN 1048576
FILE *open_read(const char *name);
FILE *open_write(const char *name);
int close_file(FILE *fp);
int get_file_size(const char *filename);

FILE *open_read(const char *name){
	FILE *fp;
	fp = fopen(name, "rb");
    if(fp == NULL){
       perror(name);
       exit(1);
    }
   return fp;
}

FILE *open_write(const char *name){
	FILE *fp;
	fp = fopen(name, "wb");
    if(fp == NULL){
       perror(name);
       exit(1);
    }
   return fp;
}

int close_file(FILE *fp){
    if(fclose(fp) != 0){
        perror("fclose() failed");
        return 1;
    }
    return 0;
}

int get_file_size(const char *filename){
	struct stat st;
	if(stat(filename, &st) == 0)
        return st.st_size;
	
	return -1;
}
	
int main(int argc, char *argv[]){
   FILE *r;
   FILE *w;
   char buffer[BUFFLEN];
   r = open_read(argv[1]);
   w = open_write(argv[2]);
   int size = get_file_size(argv[1]);
   if(argc > 3){
	   int cmdSize = atoi(argv[3]);
	   if(cmdSize < size){
		  size = cmdSize;
	   }
   }
   int bytesRead;
   while((bytesRead = fread(buffer, 1, BUFFLEN, r)) > 0){
       fwrite(buffer, 1, bytesRead, w);
   }
   
   close_file(r);
   close_file(w);
   return 0;
}