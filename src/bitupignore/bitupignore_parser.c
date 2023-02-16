#include<stdio.h>

int main( int argc , char** argv ){

    // normally, in argv there should be three args: exe name, list file location, .bitupignore file location

    if ( argc != 3 )
    {
        printf( "[bip.exe] -> fatal: wrong args given\n" );
        return -1;
    }

    

}