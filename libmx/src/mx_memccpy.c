#include "libmx.h"

/**
 * Function that has the same behavior as the standard stdlib function memccpy
 */
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n) {
    unsigned char *d = (unsigned char *)dst;
    unsigned char *s = (unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        d[i] = s[i];

        if (s[i] == (unsigned char)c)
            return d + i + 1;
    }

    return NULL;
}
