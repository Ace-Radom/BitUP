#ifndef _FILESYSTEM_BASE_H_
#define _FILESYSTEM_BASE_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef EXPORTING_APIS
#define __c_filesystem_api __declspec( dllexport )
#else
#define __c_filesystem_api __declspec( dllimport )
#endif

#define MAX_FILE_SIZE ULLONG_MAX
#define MAX_PATH_LENGTH_BY_BITUP 32767
typedef char* PATH;

#ifdef __cplusplus
}
#endif

#endif // _FILESYSTEM_BASE_H_