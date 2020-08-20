#ifndef ULS_CLION_YKSULS_H
#define ULS_CLION_YKSULS_H

#include "libmx.h"
#include <dirent.h>
#include <sys/types.h>

#define INVALID_USAGE "usage: uls [-l] [file ...]"

#define FLAGS "a l i \0"
#define FLAG_a

typedef struct s_flags {
    int argc;
    char **argv;
    char **all_flags;
    int *switch_flags;
    char **all_obj; // dir and files
    int number_of_obj;
    int fi; // flag index
}       t_flags;


void mx_check_flags(t_flags *flags);

#endif //ULS_CLION_YKSULS_H
