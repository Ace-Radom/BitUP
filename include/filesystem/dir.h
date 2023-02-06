#ifndef _FILESYSTEM_DIR_H_
#define _FILESYSTEM_DIR_H_

#include<io.h>
#include<stdio.h>
#include<string.h>

#include"base.h"
#include"cvector/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

__c_filesystem_api void __cdecl traverse_dir( const PATH __path , c_vector* __v );

#ifdef __cplusplus
}
#endif

#endif // _FILESYSTEM_DIR_H_