#ifndef _HASH_H_
#define _HASH_H_

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

#include<openssl/md5.h>

#define BLOCK_SIZE 1024

#ifdef __cplusplus
extern "C" {
#endif

errno_t __cdecl hashfile_md5( const char* __file , char* __output );

#ifdef __cplusplus
}
#endif

#endif // _HASH_H_