#ifndef _FILESYSTEM_DIR_H_
#define _FILESYSTEM_DIR_H_

#include<io.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#include"base.h"
#include"cvector/vector.h"

#ifdef __cplusplus
extern "C" {
#endif

__c_filesystem_api void __cdecl traverse_dir( const PATH __path );
__c_filesystem_api void __cdecl traverse_dir_to_listfile( const PATH __path , FILE* __outputlistfile );

// __c_filesystem_api void __cdecl change_listfile_to_cvector( FILE* __listfile , c_vector* __v );

__c_filesystem_api bool __cdecl is_root_dir( const PATH __path );
__c_filesystem_api PATH __cdecl get_parent_dir( const PATH __path );
__c_filesystem_api PATH __cdecl get_relative_path( const PATH __absolute_path , const PATH __root_dir );

#ifdef __cplusplus
}
#endif

#endif // _FILESYSTEM_DIR_H_