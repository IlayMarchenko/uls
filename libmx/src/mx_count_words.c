#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int wordCount = 0;
    while(*str) {
        if (*str != c)
            str++;
        else {
            wordCount++;
            while ( *str == c)
                str++;
        }
    }
    if (*(str-1) == c) wordCount--;
    else wordCount++;
    return wordCount;
}

