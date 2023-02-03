#ifndef _FILESYSTEM_PROPERTIES_H_
#define _FILESYSTEM_PROPERTIES_H_

#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<errno.h>
#include<time.h>
#include<limits.h>

#include"filesystem/base.h"

#ifdef __cplusplus
extern "C" {
#endif

__c_filesystem_api size_t __cdecl get_file_size( const PATH __filename );
__c_filesystem_api time_t __cdecl get_file_last_modified_time( const PATH __filename );

#ifdef __cplusplus
}
#endif

#endif // _FILESYSTEM_PROPERTIES_H_