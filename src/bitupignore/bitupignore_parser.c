#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"filesystem/filesystem.h"
#include"cvector/vector.h"

#define __dirlist__ 1
#define __bitignore__ 2

char* clean_TabChars( char* __str ){
    int NoTabChars_BeginPos;
    int NoTabChars_EndPos;
    // this two int var contain the start and end pos of the str without tab chars

    char* str_WithoutTabChars = ( char* ) malloc( strlen( __str ) );
    // str without tab chars ('\t', '\0', '\n', ' ', etc.)

    for ( NoTabChars_BeginPos = 0 ; NoTabChars_BeginPos < strlen( __str ) ; NoTabChars_BeginPos++ )
    {
        if ( __str[NoTabChars_BeginPos] == ' ' || __str[NoTabChars_BeginPos] == '\t' )
        {
            continue;
        }
        else
        {
            break;
        }
    } // get the begin pos of the str without tab chars

    for ( NoTabChars_EndPos = strlen( __str ) ; NoTabChars_EndPos >= NoTabChars_BeginPos ; NoTabChars_EndPos-- )
    {
        if ( __str[NoTabChars_EndPos] == ' '  ||
             __str[NoTabChars_EndPos] == '\t' ||
             __str[NoTabChars_EndPos] == '\n' ||
             __str[NoTabChars_EndPos] == '\r' ||
             __str[NoTabChars_EndPos] == '\0'    )
        {
            continue;
        }
        else
        {
            break;
        }
    } // get the end pos of the str without tab chars

    unsigned short int str_WithoutTabChars_CopyPos;
    unsigned short int __str_CopyPos;
    for ( __str_CopyPos = NoTabChars_BeginPos , str_WithoutTabChars_CopyPos = 0 ; 
          __str_CopyPos <= NoTabChars_EndPos ; 
          __str_CopyPos++ , str_WithoutTabChars_CopyPos++ )
    {
        str_WithoutTabChars[str_WithoutTabChars_CopyPos] = __str[__str_CopyPos];
    } // copy the str without tab chars from __str to new str var
    str_WithoutTabChars[str_WithoutTabChars_CopyPos] = '\0';
    // here: end the new str with '\0', otherwise there will be an unexpected error

    return str_WithoutTabChars;
} // function clean_TabChars

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

    c_vector dirlist_v;
    c_vector bitignore_v;
    cv_init( &dirlist_v , 10 );
    cv_init( &bitignore_v , 10 );
    // create and init vectors

    char buf_dirlistReadIN[MAX_PATH_LENGTH_BY_BITUP];
    char buf_bitignoreReadIN[1024];

    while ( fgets( buf_dirlistReadIN , sizeof( buf_dirlistReadIN ) , dirlist ) != NULL )
    {
        cv_push_back( &dirlist_v , ( void* ) clean_TabChars( buf_dirlistReadIN ) );
    }

    printf( "%d\n" , cv_len( &dirlist_v ) );
    cv_print_str( &dirlist_v );

    while ( fgets( buf_bitignoreReadIN , sizeof( buf_bitignoreReadIN ) , bitignore ) != NULL )
    {
        char* temp = ( char* ) malloc( strlen( buf_bitignoreReadIN ) );
        strcpy( temp , clean_TabChars( buf_bitignoreReadIN ) );
        // create one temp str, clean all tab-chars in the str read in and save it into this temp str
        
        if ( strcmp( temp , "file {" ) == 0   ||
             strcmp( temp , "file{" ) == 0    ||
             strcmp( temp , "folder {" ) == 0 ||
             strcmp( temp , "folder{" ) == 0  ||
             strcmp( temp , "}" ) == 0        ||
             strcmp( temp , "" ) == 0            )
        {
            continue;
        }

        cv_push_back( &bitignore_v , ( void* ) temp );
    }

    printf( "%d\n" , cv_len( &bitignore_v ) );
    cv_print_str( &bitignore_v );

    fclose( dirlist );
    fclose( bitignore );

    return 0;
} // main