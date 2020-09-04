#include "../../inc/uls_imarchenko.h"

int main(int argc, char *argv[]) {
    t_flags *flags = (t_flags*)malloc(sizeof(t_flags));
    flags->all_flags = (char **)malloc(sizeof(char *) * 3);
    flags->switch_flags = (int *)malloc(sizeof(int) * 3);
    flags->argc = argc;
    flags->argv = argv;
    flags->all_obj = (char **)malloc(sizeof(char *) * 5);
    for (int i = 0; i < 4; ++i) {
        flags->all_obj[i] = mx_strnew(40);
    }
    flags->all_obj[4] = NULL;
    for (int j = 0; j < 4; ++j) {
        flags->all_obj[j] = mx_strcpy(flags->all_obj[j], argv[j + 2]);
    }
    flags->number_of_obj = 5;
    t_lattrib **lattrib = (t_lattrib **)malloc(sizeof(t_lattrib *) * 5);
    for (int k = 0; k < 5; ++k) {
        lattrib[k] = malloc(sizeof(t_lattrib));
    }
    lattrib[0]->size = 102;
    lattrib[1]->size = 130361;
    lattrib[2]->size = 102;
    lattrib[3]->size = 102;
    lattrib[4]->size = 1666;
    if (mx_strcmp(argv[1], "-i") == 0)
        mx_flag_i(flags);
    else if (mx_strcmp(argv[1], "-p") == 0)
        mx_flag_p(flags);
    else if (mx_strcmp(argv[1], "-lh") == 0)
        mx_flag_h(lattrib, flags);
    else
        mx_printstr("sorry, such flag doesn't work yet...\n");


//    // -------------------------------------
//    struct winsize w;
//    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//    printf("\n\ncolumns %d\n", w.ws_col);
//    // -------------------------------------
//    mx_printchar('\n');
//    system("leaks -q uls_clion");
}
