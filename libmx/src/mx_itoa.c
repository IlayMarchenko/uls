#include "libmx.h"

char *mx_itoa(int number) {
    
    long num = number;
    long num1 = number;
    int length = 0;
    char temp;
    int i = 0;
    bool is_negative = false;
    int begin;

    if (num == 0)
        return "0";

    if (num1 < 0) {
        num1 *= -1;
        num *= -1;
        i++;
        length++;
        is_negative = true;
    }

    while(num > 0) {
        num /= 10;
        length++;
    }

    char *result = (char *)malloc(sizeof(char) * length + 1);

    if (i == 1)
        result[length] = '-';

    for (; i < length; ++i) {
        temp = (num1 % 10) + 48;
        num1 /= 10;
        result[i] = temp;
    }

    int end = length;

    if (is_negative) {
        for(begin = 1; begin < end; begin++){
            mx_swap_char(&result[begin], &result[end]);
            end --;
        }
        result++;
        result[length] = '\0';
    }
    else {
        for(begin = 0; begin < end; begin++){
            mx_swap_char(&result[begin], &result[end]);
            end --;
        }
        result++;
        result[length] = '\0';        
    }

    return result;
}

