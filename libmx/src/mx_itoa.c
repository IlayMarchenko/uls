#include "libmx.h"

char * mx_itoa(int number) {

    int len = 0;
    int num = number;
    char *str = 0;
    int isNeg = 0;

    if (number == 0) {
        str = (char*) malloc (sizeof(char) * 2);
        str = "0\0";
        return str;
    }
    for (;num != 0; len++, num/=10);
    if (number == -2147483648) {
        str = (char*) malloc (sizeof(char) * 12);
        str = "-2147483648\0";
        return str;
    }
    if (number < 0) {
        number = -number;
        isNeg = 1;
        str = (char*) malloc (sizeof(char) * len +2);
        str[0] = '-';
    }
    else
        str = (char *) malloc(sizeof(char) * len + 1);

    for (int i = len + isNeg - 1; i >= isNeg; i--) {
        str[i] = number % 10 + 48;
        number /= 10;
    }
    str[len + isNeg] = 0;
    return str;
}

