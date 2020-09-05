#include "../../inc/uls_imarchenko.h"

void mx_check_and_output(t_flags *flags) {


    if (flags->switch_flags[2]) // -S
        mx_sort_by_size();
    if (flags->switch_flags[3]) // -r
        mx_reverse();


    if (flags->switch_flags[4] && !flags->switch_flags[5] && !flags->switch_flags[8]) { // -l && !-i !-h
        t_lattrib **big_arr = mx_flag_l();
        print_l();
    } else if (flags->switch_flags[4] && flags->switch_flags[5] && !flags->switch_flags[8]) { // -l && -i && !-h
        t_lattrib **big_arr = mx_flag_li();
    } else if (flags->switch_flags[4] && !flags->switch_flags[5] && flags->switch_flags[8]) { // -l && -i && -h
        t_lattrib **big_arr = mx_flag_l();
        mx_flag_h();
        print_l();
    } else if (flags->switch_flags[11] && flags->switch_flags[5] && !flags->switch_flags[8]) { // -l && -i && !-h
        t_lattrib **big_arr = mx_flag_lT();
    }



    if (flags->switch_flags[5]) { // -i
        t_result = mx_flag_i();
        if (flags->switch_flags[9]) { // -1 / cat
            mx_output_in_one_column();
        }
        else {
            mx_output_by_size_of_wind();
        }
    }

    if (flags->switch_flags[6]) { // -p
        t_result = mx_flag_p();
        if (flags->switch_flags[9]) { // -1 / cat
            mx_output_in_one_column();
        }
        else {
            mx_output_by_size_of_wind();
        }
    }

    if (flags->switch_flags[7]) { // -s
        t_result = mx_flag_p();
        if (flags->switch_flags[9]) { // -1 / cat
            mx_output_in_one_column();
        }
        else {
            mx_output_by_size_of_wind();
        }
    }

}
