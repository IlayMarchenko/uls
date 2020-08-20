#include "../../inc/uls_imarchenko.h"

static void check_what_flag(t_flags *flags);
static void connect_flags(t_flags *flags);

void mx_check_flags(t_flags *flags) {
// check for flags
    flags->switch_flags = (int *)malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++) {
        flags->switch_flags[i] = 0;
    }
    flags->all_flags = mx_strsplit(FLAGS, ' ');
    for (int k = 1; k < flags->argc; k++) {
        if (flags->argv[k][0] == '-') {
            for (int h = 1; flags->argv[k][h]; h++) {
                for (int j = 0; flags->all_flags[j]; j++) {
                    if (flags->argv[k][h] == flags->all_flags[j][0]) {
                        flags->switch_flags[j] = 1;
                    }
                }
            }
        }
    }
    connect_flags(flags);
}

static void check_what_flag(t_flags *flags) {
    for (int i =0; i < 3; i++) {
        printf("! %d ", flags->fi);
    }
    if (flags->fi == 0) // flag -a
        printf("---flag 'a'---\n");
    if (flags->fi == 1) // flag -l
        printf("---flag 'l'---\n");
    if (flags->fi == 2) // flag -i
        mx_flag_i(flags);
}
static void connect_flags(t_flags *flags) {
    for (flags->fi = 0; flags->fi < 3; flags->fi++)
        if (flags->switch_flags[flags->fi] == 1){
            printf("INDEX2222: %d\n", flags->fi);
            check_what_flag(flags);
        }
}
