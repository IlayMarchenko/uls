#include "libmx.h"

void mx_str_reverse(char *s){
    int end = mx_strlen(s) - 1;
    int begin;

    for(begin=0; begin < end; begin++){
	mx_swap_char(&s[begin], &s[end]);
	end --;
    }
}

