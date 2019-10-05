/*
 * Compile:
 * 		gcc -o md5 md5.c -lssl -lcrypto
 */

#include <openssl/md5.h>
#include <unistd.h>
#include <stdio.h>

#define MD5_HASH_SIZE 16

int main()
{
        int n;
        MD5_CTX c;
        char buf[512];
        ssize_t bytes;
        unsigned char out[MD5_HASH_SIZE];

        MD5_Init(&c);
        bytes=read(STDIN_FILENO, buf, 512);
        while(bytes > 0)
        {
                MD5_Update(&c, buf, bytes);
                bytes=read(STDIN_FILENO, buf, 512);
        }

        MD5_Final(out, &c);

        for(n=0; n<MD5_DIGEST_LENGTH; n++)
                printf("%02x", out[n]);

        return(0);        
}
