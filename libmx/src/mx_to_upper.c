#include "libmx.h"

void mx_to_upper(char *str) {
    char *a = str;
    while (*a) {
        if (*a >= 'a' && *a <= 'z') {
            *a -= 32;
        }
        a++;
    }
}
