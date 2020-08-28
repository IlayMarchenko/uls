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
    flags->number_of_obj = 1;
    mx_flag_i(flags); // TODO clean 16 leaks
//
//    // -------------------------------------
//    struct winsize w;
//    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//    printf ("\n\ncolumns %d\n", w.ws_col);
//    // -------------------------------------
    //system("leaks -q uls_clion");
}
