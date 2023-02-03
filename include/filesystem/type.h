#ifndef _FILESYSTEM_TYPE_H_
#define _FILESYSTEM_TYPE_H_

#include<sys/stat.h>

#include"base.h"

#ifdef __cplusplus
extern "C" {
#endif

__c_filesystem_api bool __cdecl is_REG( const PATH __path );
__c_filesystem_api bool __cdecl is_DIR( const PATH __path );

#ifdef __cplusplus
}
#endif

#endif // _FILESYSTEM_TYPE_H_