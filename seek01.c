

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <aio.h>

int create_file(const char *name);
int close_file(int fd);

int create_file(const char *name){
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

int main( int argc, char * argv[] ){
   int file = create_file(argv[1]);
   char byte = 'a';
   
   lseek(file, 1000000, SEEK_SET);
   write(file, &byte, 1);
   
   close_file(file);
   return 0;
}