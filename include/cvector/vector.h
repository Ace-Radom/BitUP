#ifndef _CVECTOR_VECTOR_H_
#define _CVECTOR_VECTOR_H_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef EXPORTING_APIS
#define __cvector_api __declspec( dllexport )
#else
#define __cvector_api __declspec( dllimport )
#endif

typedef struct {
    long long cap;  // capacity
    long long len;  // length
    void** items;   // items
} c_vector;

__cvector_api void __cdecl cv_init( c_vector* __v , long long __cap );
__cvector_api void __cdecl cv_resize( c_vector* __v , long long __cap );
__cvector_api void __cdecl cv_push_front( c_vector* __v , void* __item );
__cvector_api void __cdecl cv_push_back( c_vector* __v , void* __item );
__cvector_api void* __cdecl cv_pop_front( c_vector* __v );
__cvector_api void* __cdecl cv_pop_back( c_vector* __v );
__cvector_api void __cdecl cv_insert( c_vector* __v , void* __item , long long __pos );
__cvector_api void* __cdecl cv_delete( c_vector* __v , long long __pos );
__cvector_api void __cdecl cv_clean( c_vector* __v );
__cvector_api long long __cdecl cv_len( c_vector* __v );

__cvector_api void __cdecl cv_print_str( c_vector* __v );

#ifdef __cplusplus
}
#endif

#endif // _CVECTOR_VECTOR_H_