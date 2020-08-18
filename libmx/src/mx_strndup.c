#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *new_str = mx_strnew(n);

    if (new_str == NULL || s1 == NULL) return NULL;

    mx_strncpy(new_str, s1, n);
    return new_str;
}
