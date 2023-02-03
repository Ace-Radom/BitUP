#include"filesystem/properties.h"

/**
 * @brief  get a file's size
 * @param  __filepath file's path
 * @return size_t - file size
 * @throw  when file doesn't exist or this "file" is a folder, return @c ULLONG_MAX
 */
__c_filesystem_api size_t __cdecl get_file_size( const PATH __filepath ){
    struct stat statbuf;
    if ( stat( __filepath , &statbuf ) == -1 )
    {
        return MAX_FILE_SIZE;
    } // error on opening this given file

    if ( S_ISREG( statbuf.st_mode ) )
    {
        return statbuf.st_size;
    } // this file is a real "file"

    return MAX_FILE_SIZE;
    // other error occurs
}

/**
 * @brief  get a file's last modified time
 * @param  __filepath file's path
 * @return time_t - timestamp
 * @throw  when file doesn't exist or this "file" is a folder, return -1
 */
__c_filesystem_api time_t __cdecl get_file_last_modified_time( const PATH __filepath ){
    struct stat statbuf;
    if ( stat( __filepath , &statbuf ) == -1 )
    {
        return -1;
    } // error on opening this given file
    
    if ( S_ISREG( statbuf.st_mode ) )
    {
        return statbuf.st_mtime;
    } // this file is a real "file"

    return -1;
    // other error occurs
}