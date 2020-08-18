#include "libmx.h"

bool mx_space(char a) {
    if (a == ' ' || a == '\t' || a == '\r' || a == '\n' || a == '\v' || a == '\f' || a == '\b') {
        return true;
    }
    return false;
}
