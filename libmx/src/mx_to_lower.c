#include "libmx.h"

void mx_to_lower(char *str) {
    char *a = str;
    while (*a) {
        if (*a >= 'A' && *a <= 'Z') {
            *a += 32;
        }
        a++;
    }
}
