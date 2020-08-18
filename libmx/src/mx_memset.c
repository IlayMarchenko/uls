#include "libmx.h"

void *mx_memset(void *b, int c, size_t len) {

	char *a = b;

    while(len--) {
        *a++ = c;
    }

    return a;
}


