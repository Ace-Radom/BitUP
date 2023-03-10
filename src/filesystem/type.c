#include"filesystem/type.h"

/**
 * @brief  check if this path is a file
 * @param  __path path
 * @return bool - is this path a file
 * @throw  when error occurs with opening this path, return false
 */
__c_filesystem_api bool __cdecl is_REG( const PATH __path ){
    struct stat statbuf;
    if ( stat( __path , &statbuf ) == -1 )
    {
        return false;
    } // error on opening this path

    if ( S_ISREG( statbuf.st_mode ) )
    {
        return true;
    } // this is a file

    return false;
}

/**
 * @brief  check if this path is a dir
 * @param  __path path
 * @return bool - is this path a dir
 * @throw  when error occurs with opening this path, return false
 */
__c_filesystem_api bool __cdecl is_DIR( const PATH __path ){
    struct stat statbuf;
    if ( stat( __path , &statbuf ) == -1 )
    {
        return false;
    } // error on opening this path

    if ( S_ISDIR( statbuf.st_mode ) )
    {
        return true;
    } // this is a dir

    return false;
}