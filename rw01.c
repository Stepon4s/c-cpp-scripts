
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <aio.h>

#define BUFFLEN 1048576
int open_read(const char *name);
int open_write(const char *name);
int close(int fd);
int get_file_size(const char *filename);

int open_read(const char *name){
	int dskr;
	dskr = open( name, O_RDONLY );
    if( dskr == -1 ){
       perror( name );
       exit(1);
    }
   return dskr;
}

int open_write(const char *name){
	int dskr;
dskr = open( name, O_WRONLY | O_CREAT | O_TRUNC, 0644 );
    if( dskr == -1 ){
       perror( name );
       exit(1);
    }
   return dskr;
}

int close_file(int fd){
    int rv;
    rv = close( fd );
    if( rv != 0 ) perror ( "close() failed" );

    return rv;
}

int get_file_size(const char *filename){
	struct stat st;
	if(stat(filename, &st) == 0)
        return st.st_size;
	
	return -1;
}
	
int main( int argc, char * argv[] ){
   int r;
   int w;

   char buffer[BUFFLEN];

   r = open_read( argv[1] );
   w = open_write( argv[2] );
   int size = get_file_size(argv[1]);
   if(argc > 3){
	   int cmdSize = atoi(argv[3]);
	   if(cmdSize < size){
		  size = cmdSize;
	   }
   }
   for(int i = 0; i < size; i++){
   int c = read(r, buffer, 1);
   write(w, buffer, c);
   }
   
   close_file(r);
   close_file(w);
   return 0;
}