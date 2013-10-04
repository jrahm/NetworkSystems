#include <stdio.h>
#include <errno.h>

#include "gbn_socket.h"

#define READ_SIZE (4096<<1)

int main( int argc, char** argv ) {
    (void) argc;

    gbn_socket_t* sock;

    if( ! argv[1] ) {
        fprintf( stderr, "File argument required\n" );
        return 1;
    }

	// 192.168.0.170
    sock = gbn_socket_open_client( "38.89.2.211", 5432 ) ;

    FILE* read = fopen( argv[1], "r" );

    if( ! read ) {
        perror( "Could not open file" );
        return errno;
    }

    char buffer[READ_SIZE];
    size_t bytes_read;

    while( (bytes_read = fread(buffer, 1, READ_SIZE, read)) > 0 ) {
        gbn_socket_write( sock, buffer, bytes_read );
    }
    
    gbn_socket_close( sock );
    return 0;
}
