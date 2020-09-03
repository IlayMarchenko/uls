#ifndef ULS_CLION_YKSULS_H
#define ULS_CLION_YKSULS_H

#include "libmx.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <time.h>
#include <sys/ioctl.h>

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

typedef struct s_lattrib {
    int *id;
    int *bl;
    char *ftype;
    char *rights;
    int *lins;
    char *user;
    int *group;
    off_t size;
    char *size_with_type;
    int *full_time;
    char *name;
}       t_lattrib;


void mx_check_flags(t_flags *flags);

#endif //ULS_CLION_YKSULS_H
