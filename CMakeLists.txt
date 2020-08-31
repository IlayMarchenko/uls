cmake_minimum_required(VERSION 3.16)
project(uls_clion C)

set(CMAKE_C_STANDARD 11)

include_directories(libmx/inc)

add_executable(uls_clion
        libmx/inc/libmx.h
        libmx/src/mx_binary_search.c
        libmx/src/mx_bubble_sort.c
        libmx/src/mx_count_substr.c
        libmx/src/mx_count_words.c
        libmx/src/mx_create_node.c
        libmx/src/mx_del_extra_spaces.c
        libmx/src/mx_del_strarr.c
        libmx/src/mx_file_to_str.c
        libmx/src/mx_foreach.c
        libmx/src/mx_get_char_index.c
        libmx/src/mx_get_substr_index.c
        libmx/src/mx_hex_to_nbr.c
        libmx/src/mx_in_alphabet.c
        libmx/src/mx_intlen.c
        libmx/src/mx_is_number.c
        libmx/src/mx_itoa.c
        libmx/src/mx_list_size.c
        libmx/src/mx_memccpy.c
        libmx/src/mx_memchr.c
        libmx/src/mx_memcmp.c
        libmx/src/mx_memcpy.c
        libmx/src/mx_memmem.c
        libmx/src/mx_memmove.c
        libmx/src/mx_memrchr.c
        libmx/src/mx_memset.c
        libmx/src/mx_nbr_to_hex.c
        libmx/src/mx_pop_back.c
        libmx/src/mx_pop_front.c
        libmx/src/mx_pow.c
        libmx/src/mx_print_strarr.c
        libmx/src/mx_print_unicode.c
        libmx/src/mx_printchar.c
        libmx/src/mx_printerr.c
        libmx/src/mx_printint.c
        libmx/src/mx_printstr.c
        libmx/src/mx_push_back.c
        libmx/src/mx_push_front.c
        libmx/src/mx_quicksort.c
        libmx/src/mx_read_line.c
        libmx/src/mx_realloc.c
        libmx/src/mx_replace_substr.c
        libmx/src/mx_sort_list.c
        libmx/src/mx_space.c
        libmx/src/mx_sqrt.c
        libmx/src/mx_str_reverse.c
        libmx/src/mx_strcat.c
        libmx/src/mx_strcmp.c
        libmx/src/mx_strcpy.c
        libmx/src/mx_strdel.c
        libmx/src/mx_strdup.c
        libmx/src/mx_strjoin.c
        libmx/src/mx_strlen.c
        libmx/src/mx_strncpy.c
        libmx/src/mx_strndup.c
        libmx/src/mx_strnew.c
        libmx/src/mx_strsplit.c
        libmx/src/mx_strstr.c
        libmx/src/mx_strtrim.c
        libmx/src/mx_swap_char.c
        libmx/src/mx_to_lower.c
        libmx/src/mx_to_upper.c
        src/flags/mx_flag_i.c
        src/main/main.c
        inc/uls_imarchenko.h inc/yksuls.h src/flags/mx_check_flags.c src/additional/mx_alphabet_sort.c src/output/output_by_size_of_wind.c src/additional/mx_the_biggest_name.c src/additional/mx_alphabet_sort2.c src/additional/mx_max_len_of_inode.c src/flags/mx_flag_p.c src/additional/mx_file_dir_sort.c src/output/mx_output_in_one_column.c)
