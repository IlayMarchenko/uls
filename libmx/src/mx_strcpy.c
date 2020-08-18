#include "libmx.h"

char *mx_strcpy(char *dst, const char *src){

    int a = 0;

    while(src[a] != '\0'){
        dst[a] = src[a];
        a++;
    }

    dst[a] =  '\0';
    return dst;
}
