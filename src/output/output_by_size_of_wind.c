#include "../../inc/uls_imarchenko.h"

static void one_line_output(char **array, int len_of_array, int max_len);

void mx_output_by_size_of_wind(char **array, int len_of_array) {
    int length_of_line = 0;
    struct winsize window;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
    int max_len = mx_the_biggest_name(array, len_of_array);
    if (max_len % 8 != 0) {
        while (max_len % 8 != 0) {
            max_len++;
        }
    }
    if (max_len * len_of_array >= window.ws_col) {
        one_line_output(array, len_of_array, max_len);
    } else {

    }
}

static void one_line_output(char **array, int len_of_array, int max_len) {
    int temp = 0;
    for (int i = 0; i < len_of_array; i++) {
        temp = max_len - mx_strlen(array[i]);
        mx_printstr(array[i]);
        if (temp != 0) {
            for (int j = 0; j < temp; ++j) {
                mx_printchar(' ');
            }
        }
    }
}

static void multiple_line_output(char **array, int len_of_array, int max_len, struct winsize window) {
    int number_of_col = len_of_array / 2 + 1;
    int number_objs_in_col;
    while (true) {
        if (number_of_col * max_len >= window.ws_col) {
            break;
        }
        else {
            if (number_of_col % 2 != 0) {
                number_of_col = len_of_array / 2 + 1;
            }
        }
    }
    number_objs_in_col = len_of_array / number_of_col;
    for (int i = 0; i < number_of_col; i++) {
        
    }
}