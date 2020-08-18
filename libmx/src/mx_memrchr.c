#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *string = (unsigned char *)s;

    while (n)
        if (string[--n] == (unsigned char)c)
            return string + n;

    return NULL;
}
