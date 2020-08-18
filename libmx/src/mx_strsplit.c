#include "libmx.h"

char **mx_strsplit(const char *s, char c) {

    char *str = (char *)s;
    int number_of_words = mx_count_words(str, c);
    char **arr = malloc((number_of_words + 1) * 8);
    int index_in_arr = 0;
    int temp_len = 0;
    char *temp_str;

    while (*str != '\0') {
        while (*str == c && *str != '\0')
            str++;

        if (*str == '\0')
            break;

        while (*str != c && *str != '\0') {
            str++;
            temp_len++;
        }

        if (*str == '\0')
            break;

        temp_str = mx_strnew(temp_len);

        str -= temp_len;

        for (int i = 0; i < temp_len; i++) {
            temp_str[i] = *str++;
        }
        arr[index_in_arr] = temp_str;
        index_in_arr++;
        temp_len = 0;
    }
    arr[number_of_words] = NULL;
    return arr;
}


