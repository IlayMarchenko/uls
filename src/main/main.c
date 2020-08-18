#include "../../inc/uls_imarchenko.h"

int main(int argc, char *argv[]) {
    mx_flag_i(4, argv);
    system("leaks -q uls_clion");
    return 0;
}
