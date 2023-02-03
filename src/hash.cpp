#include"hash.h"

/**
 * @brief calc one file's md5
 * @param __file   file path
 * @param __output output string
 * @throw if error occurs during file opening, return -1, otherwise return 0
 * @note  because of the use of multi-block calculation, there's no size-limit on file
 */
errno_t __cdecl hashfile_md5( const char* __file , char* __output ){
    unsigned char md[MD5_DIGEST_LENGTH] = { 0 };
    MD5_CTX C;
    MD5_Init( &C );
    FILE* Fp = NULL;

    errno_t err;
    if ( ( err = fopen_s( &Fp , __file , "rb" ) ) != 0 )
    {
        fclose( Fp );
        return -1;
    } // check if file is successfully opened

    // begin hashfile process

    unsigned char buf[BLOCK_SIZE] = { 0 };
    while ( 1 )
    {
        int rFileLength = fread( buf , sizeof( unsigned char ) , BLOCK_SIZE , Fp );
        if ( rFileLength == 0 )
        {
            break;
        } // read to end of this file
        MD5_Update( &C , buf , rFileLength );
        // update MD5
    }

    MD5_Final( md , &C );
    fclose( Fp );

    // begin to build output string

    for ( int i = 0 ; i < MD5_DIGEST_LENGTH ; i++ )
    {
        sprintf( &( __output[i*2] ) , "%02x" , ( unsigned char ) md[i] );
    }
    return 0;
}