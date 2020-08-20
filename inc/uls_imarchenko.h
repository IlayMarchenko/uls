#ifndef ULS_CLION_ULS_IMARCHENKO_H
#define ULS_CLION_ULS_IMARCHENKO_H

#include "libmx.h"
#include <dirent.h>
#include "yksuls.h"

typedef struct s_sorted_obj {
    char **files;
    char **dirs;
    int len_of_files_array;
    int len_of_dirs_array;
}              t_sorted_odj;

void mx_flag_i(t_flags *flags);
void mx_alphabet_sort(char **array, int len);

#endif //ULS_CLION_ULS_IMARCHENKO_H
