#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"filesystem/filesystem.h"

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

    char buf[1024];

    while ( fgets( buf , sizeof( buf ) , bitignore ) != NULL )
    {
        int NoTabChars_BeginPos;
        int NoTabChars_EndPos;
        // this two int var contain the start and end pos of the str without tab chars

        char* str_WithoutTabChars = ( char* ) malloc( strlen( buf ) );
        // str without tab chars ('\t', '\0', '\n', ' ', etc.)

        for ( NoTabChars_BeginPos = 0 ; NoTabChars_BeginPos < strlen( buf ) ; NoTabChars_BeginPos++ )
        {
            if ( buf[NoTabChars_BeginPos] == ' ' || buf[NoTabChars_BeginPos] == '\t' )
            {
                continue;
            }
            else
            {
                break;
            }
        } // get the begin pos of the str without tab chars

        for ( NoTabChars_EndPos = strlen( buf ) ; NoTabChars_EndPos >= NoTabChars_BeginPos ; NoTabChars_EndPos-- )
        {
            if ( buf[NoTabChars_EndPos] == ' '  ||
                 buf[NoTabChars_EndPos] == '\t' ||
                 buf[NoTabChars_EndPos] == '\n' ||
                 buf[NoTabChars_EndPos] == '\r' ||
                 buf[NoTabChars_EndPos] == '\0'    )
            {
                continue;
            }
            else
            {
                break;
            }
        } // get the end pos of the str without tab chars

        int str_WithoutTabChars_CopyPos;
        int buf_CopyPos;
        for ( buf_CopyPos = NoTabChars_BeginPos , str_WithoutTabChars_CopyPos = 0 ; buf_CopyPos <= NoTabChars_EndPos ; buf_CopyPos++ , str_WithoutTabChars_CopyPos++ )
        {
            str_WithoutTabChars[str_WithoutTabChars_CopyPos] = buf[buf_CopyPos];
        }
        str_WithoutTabChars[buf_CopyPos] = '\0';

        printf( "%s\n" , str_WithoutTabChars );
    }



    fclose( dirlist );
    fclose( bitignore );

    return 0;
}