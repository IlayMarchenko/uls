#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    return mx_memcpy(dst, src, len);
}

