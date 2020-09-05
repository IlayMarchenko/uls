#include "../../inc/uls_imarchenko.h"

void mx_output_with_comma(char **array, int len_of_array) {
    for (int i = 0; i < len_of_array; i++) {
        mx_printstr(array[i]);
        if (i + 1 != len_of_array)
            mx_printstr(", ");
    }
    mx_printchar('\n');
}

