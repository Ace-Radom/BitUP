#include"filesystem/dir.h"

__c_filesystem_api void __cdecl traverse_dir( const PATH __path ){
    intptr_t hFile = 0;
    struct _finddata_t FileInfo;
    char pathName[MAX_PATH_LENGTH_BY_BITUP];
    strcpy( pathName , __path );
    strcat( pathName , "/*" );
    if ( ( hFile = _findfirst( pathName , &FileInfo ) ) == -1 )
    {
        return;
    } // found no more
    do
    {
        if ( ( strcmp( FileInfo.name , "." ) != 0 ) && ( strcmp( FileInfo.name , ".." ) != 0 ) )
        {
            char this_path[MAX_PATH_LENGTH_BY_BITUP];
            strcpy( this_path , __path );
            strcat( this_path , "/" );
            strcat( this_path , FileInfo.name );
            // build the current path searched by this function

            printf( "%s\n" , this_path );
            // print this path

            if ( FileInfo.attrib & _A_SUBDIR )
            {
                traverse_dir( this_path );
            } // this path still has a subdir
        } // only when this searched path is not '.' or '..', build current searched path and push into vector
    } while ( _findnext( hFile , &FileInfo ) == 0 ); // do while still can find one path
    _findclose( hFile );
    return;
}

__c_filesystem_api void __cdecl traverse_dir_to_listfile( const PATH __path , FILE* __outputlistfile ){
    intptr_t hFile = 0;
    struct _finddata_t FileInfo;
    char pathName[MAX_PATH_LENGTH_BY_BITUP];
    strcpy( pathName , __path );
    strcat( pathName , "/*" );
    if ( ( hFile = _findfirst( pathName , &FileInfo ) ) == -1 )
    {
        return;
    } // found no more
    do
    {
        if ( ( strcmp( FileInfo.name , "." ) != 0 ) && ( strcmp( FileInfo.name , ".." ) != 0 ) )
        {
            char this_path[MAX_PATH_LENGTH_BY_BITUP];
            strcpy( this_path , __path );
            strcat( this_path , "/" );
            strcat( this_path , FileInfo.name );
            // build the current path searched by this function

            fputs( this_path , __outputlistfile );
            fputs( "\n" , __outputlistfile );
            // put this path to file

            if ( FileInfo.attrib & _A_SUBDIR )
            {
                traverse_dir_to_listfile( this_path , __outputlistfile );
            } // this path still has a subdir
        } // only when this searched path is not '.' or '..', build current searched path and push into vector
    } while ( _findnext( hFile , &FileInfo ) == 0 ); // do while still can find one path
    _findclose( hFile );
    return;
}

/**
 * @note doesn't work, no idea why
 */
// __c_filesystem_api void __cdecl change_listfile_to_cvector( FILE* __listfile , c_vector* __v ){
//     char buf[MAX_PATH_LENGTH_BY_BITUP];
//     while ( fgets( buf , sizeof( buf ) , __listfile ) != NULL )
//     {
//         printf( "%s" , buf );
//         cv_push_front( __v , ( void* ) buf );
//     }
//     return;
// }

__c_filesystem_api bool __cdecl is_root_dir( const PATH __path ){

    // here: I only care about Windows at first, therefore: this function is totally based on Windows' pathes rules
    // when (or if) BitUP needs to be ported to Linux, this function needs to be rewritten

    // and: I didn't care about those pathes which aren't got by BitUP filesystem, no why

    int plen = strlen( __path );
    if ( ( __path[0] >= 'A' ) && ( __path[0] <= 'Z' ) && ( __path[1] == ':' ) && ( __path[2] == '/' ) && ( plen == 3 ) )
    {
        return true;
    }
    return false;
}

__c_filesystem_api PATH __cdecl get_parent_dir( const PATH __path ){
    if ( is_root_dir( __path ) )
    {
        return __path;
    } // if this path is already the root dir, return itself

    int plen = strlen( __path );
    int pos;
    for ( pos = plen - 1 ; pos >= 0 ; pos-- )
    {
        if ( __path[pos] == '/' )
        {
            break;    
        }
    }
    char pardir[pos];
    memset( pardir , '\0' , sizeof( pardir ) );
    strncpy( pardir , __path , pos + 1 );
    if ( !is_root_dir( pardir ) )
    {
        pardir[strlen(pardir)-1] = '\0';
    } // original path's parent dir is still not a root dir, delete '/' at the end
    char* dest = ( char* ) malloc( pos );
    strcpy( dest , pardir );
    return dest;
}

__c_filesystem_api PATH __cdecl get_relative_path( const PATH __absolute_path , const PATH __root_dir ){
    if ( strcmp( __absolute_path , __root_dir ) == 0 )
    {
        return NULL;
    } // absolute path is same as the given root dir, return NULL

    char path_temp[strlen(__absolute_path)];
    memset( path_temp , '\0' , sizeof( path_temp ) );
    // use to check if the given absolute path is a child path of the given root dir
    strncpy( path_temp , __absolute_path , strlen( __root_dir ) );
    if ( strcmp( path_temp , __root_dir ) != 0 )
    {
        return NULL;
    } // the given absolute path isn't a child path of the given root dir, return NULL

    memset( path_temp , '\0' , sizeof( path_temp ) );
    strncpy( path_temp , __absolute_path + strlen( __root_dir ) + 1 , strlen( __absolute_path ) - strlen( __root_dir ) - 1 );
    // copy relative path
    char* dest = ( char* ) malloc( strlen( path_temp ) );
    strcpy( dest , path_temp );
    return dest;
}