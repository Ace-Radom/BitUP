#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"filesystem/dir.h"

#define __dirlist__ 1
#define __bitignore__ 2

int main( int argc , char** argv ){

    // normally, in argv there should be three args: exe name, list file location, .bitupignore file location
    // all location must be set in direct path

    if ( argc != 3 )
    {
        printf( "[bip.exe] -> fatal: wrong args given\n" );
        return -1;
    }

    char dirlist_path[strlen( argv[__dirlist__] )];
    char bitignore_path[strlen( argv[__bitignore__] )];
    strcpy( dirlist_path , argv[__dirlist__] );
    strcpy( bitignore_path , argv[__bitignore__] );

    char* bitignore_dir = ( char* ) malloc( strlen( bitignore_path ) );
    strcpy( bitignore_dir , get_parent_dir( bitignore_path ) );
    // get .bitignore dir

    printf( "%s\n%s\n%s\n" , dirlist_path , bitignore_path , bitignore_dir );

    FILE* dirlist = NULL;
    FILE* bitignore = NULL;

    if ( ( dirlist = fopen( dirlist_path , "r+" ) ) == NULL )
    {
        printf( "[bip.exe] -> fatal: cannot open dirlist file (usually end with .bitupcache)\n" );
        return -1;
    } // open dirlist
    if ( ( bitignore = fopen( bitignore_path , "r+" ) ) == NULL )
    {
        printf( "[bip.exe] -> fatal: cannot open bitignore file" );
        return -1;
    } // open bitignore file

    

    return 0;
}