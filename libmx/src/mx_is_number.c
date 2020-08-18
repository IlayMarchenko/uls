#include "libmx.h"

bool mx_is_number(char a) {
    if (a >= '0' && a <= '9') {
        return true;
    }
    return false;
}
