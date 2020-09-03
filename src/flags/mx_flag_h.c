#include "../../inc/uls_imarchenko.h"

void mx_flag_h(t_lattrib **lattrib, t_flags *flags) {
    for (int i = 0; i < flags->number_of_obj; i++) {
        lattrib[i]->size_with_type = mx_convert_bytes(lattrib[i]->size);
        mx_printstr(lattrib[i]->size_with_type);
        mx_printchar('\n');
    }
}

