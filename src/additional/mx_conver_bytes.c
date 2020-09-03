#include "../../inc/uls_imarchenko.h"

static char *convert(int size, char *type, int n) {
    char *result;
    char *temp;
    size /= n;
    result = mx_strnew(mx_intlen(size) + 1);
    temp = mx_itoa(size);
    result = mx_strcpy(result, temp);
    result = mx_strcat(result, type);
    return result;
}

char *mx_convert_bytes(int size) {
    char *result = NULL;
    if (size < 0 || size > 2147483647) {
        return NULL;
    }
    else if (size > 0 && size <= 1024) {
        result = convert(size, "B", 1);;
    }
    else if (size > 1024 && size <= 1048576) {
        result = convert(size, "K", 1024);
    }
    else if (size > 1048576 && size <= 1073741824) {
        result = convert(size, "M", 1048576);
    }
    else {
        result = convert(size, "G", 1073741824);
    }
    return result;
}
