#include"filesystem/dir.h"

__c_filesystem_api void __cdecl traverse_dir( const PATH __path , c_vector* __v ){
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

            cv_push_back( __v , ( void* ) this_path );
            // printf( "%s\n" , this_path );
            // push this path into cvector

            if ( FileInfo.attrib & _A_SUBDIR )
            {
                traverse_dir( this_path , __v );
            } // this path still has a subdir
        } // only when this searched path is not '.' or '..', build current searched path and push into vector
    } while ( _findnext( hFile , &FileInfo ) == 0 ); // do while still can find one path
    _findclose( hFile );
    return;
}