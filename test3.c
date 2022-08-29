#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



int main( int argc, char *argv[] )  {

    char *searchArg = argv[ 1 ];
    pid_t pid;

    if ( ( pid = fork() ) > 0 ) {
        wait( NULL );
        // printf("par\n");
    } 
   	else if ( pid == 0 ) {
        int fd1[ 2 ];
        pipe( fd1 );

        if ( (pid = fork()) > 0 ) {
            if (dup2( fd1[ 0 ] , 0 ) < 0) {
            }
            close( fd1[ 0 ] );
            close( fd1[ 1 ] ); // important; see below
            // Note: /usr/bin, not /bin
            execlp( "/usr/bin/wc", "wc", NULL, NULL );
        }
        else if ( pid == 0 ) {
            if (dup2( fd1[ 1 ] , 1 ) < 0) {
				return 0;
            }
            close( fd1[ 0 ] );
            close( fd1[ 1 ] );
            execlp( "/bin/ls", "ls", NULL );
        }
}
    return 0;
}