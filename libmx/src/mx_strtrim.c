#include "libmx.h"

static bool space(char a) {
	if (a == ' ' || a == '\t' || a == '\r' || a == '\n' || a == '\v' || a == '\f' || a == '\b') {
		return true;
	}
	return false;
}

char *mx_strtrim(const char *str) {
    char *result = NULL;
    int x = 0;
    int i = 0;
    int len_str = 0;

    if (!str) {
    	return NULL;
    }

    result = mx_strnew(mx_strlen(str));
    len_str = mx_strlen(str);

    while (space(str[x])) {
        x++;
    }

    len_str--;
    while (space(str[len_str])){
        len_str--;
    }

    for (; x <= len_str; x++) {
        result[i] = str[x];
        i++;
    }

    result = (char *)mx_realloc(result, sizeof(char) * mx_strlen(result) + 1);
    return result;
}
