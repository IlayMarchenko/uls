#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int f = open(file, O_RDONLY);
    if (f < 0) return NULL;

    char buf[1];
    int str_size = 0;

    while (read(f, &buf, 1))
        str_size++;

    if (str_size == 0) return NULL;

    char *result = mx_strnew(str_size);

    close(f);
    f = open(file, O_RDONLY);

    int result_len = 0;
    while (read(f, &buf, 1))
        result[result_len++] = *buf;

    return result;
}
