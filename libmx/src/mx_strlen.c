#include "libmx.h"

int mx_strlen(const char *s) {

    int counter = 0;
    int i;

    for(i=0; s[i]!='\0'; i++) {
        counter++;
    }
    
    return counter;
}
