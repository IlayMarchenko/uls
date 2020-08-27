#include "../../inc/uls_imarchenko.h"

static void one_obj(char *obj);
static char *trim(char *string, char **current_file);
static void add_inode_to_name_of_file(t_sorted_odj *sort);
static void two_and_more_obj(t_flags *flags);
static void file_dir_sort(t_sorted_odj *sort, t_flags *flags);


void mx_flag_i(t_flags *flags) {
    if (flags->number_of_obj == 0) {
        one_obj(".");
    }
    else if (flags->number_of_obj == 1) {
        one_obj(flags->all_obj[0]);
    }
    else if (flags->number_of_obj > 1) {
        two_and_more_obj(flags);
    }
}

static void one_obj(char *obj) {
    int len_of_array = 0;
    int max_len_of_inode;
    int temp;
    int i = 0;
    char **array = NULL;
    DIR *d;
    struct dirent *directory;
    d = opendir(obj);
    if (d) {
        while ((directory = readdir(d)) != NULL) {
            if (directory->d_name[0] != '.') {
                len_of_array++;
            }
        }
        closedir(d);
        max_len_of_inode = mx_max_len_of_inode(obj);
        d = opendir(obj);
        array = (char **)malloc(sizeof(char *) * len_of_array);
        while ((directory = readdir(d)) != NULL) {
            if (directory->d_name[0] != '.') {
                temp = max_len_of_inode - mx_intlen(directory->d_ino);
                array[i] = mx_strnew(directory->d_namlen + max_len_of_inode + 1);
                if (temp != 0) {
                    for (int j = 0; j < temp; ++j) {
                        if (j == 0) {
                            array[i] = mx_strcpy(array[i], " ");
                        }
                        else {
                            array[i] = mx_strcat(array[i], " ");
                        }
                    }
                }
                array[i] = mx_strcat(array[i], mx_itoa(directory->d_ino)); // TODO find length of the biggest inode number
                array[i] = mx_strcat(array[i], " ");
                array[i] = mx_strcat(array[i], directory->d_name);
                i++;
            }
        }
        closedir(d);
        mx_alphabet_sort2(array, len_of_array);
        mx_output_by_size_of_wind(array, len_of_array);
        mx_strdel(&array[len_of_array - 1]);
        mx_del_strarr(&array);
    }
}

static char *trim(char *string, char **current_file) {
    int count = 0;
    int index = 0;
    bool has_slash = false;
    char *res = NULL;
    int len = mx_strlen(string);
    for (int j = 0; j < len; ++j) {
        if (*string == '/') {
            has_slash = true;
            index = count;
        }
        string++;
        count++;
    }
    string -= count;
    res = mx_strnew(index);
    if (has_slash) {
        for (int i = 0; i <= index; i++) {
            *res = *string;
            res++;
            string++;
        }
        index++;
    }
    *current_file = mx_strdup(string);
    string -= index;
    res -= index;
    if (index == 0) {
        res = mx_strcpy(res, ".");
    }
    return res;
}

static void two_and_more_obj(t_flags *flags) {
    t_sorted_odj *sort = (t_sorted_odj *)malloc(sizeof(t_sorted_odj));
    sort->len_of_dirs_array = sort->len_of_files_array = 0;
    file_dir_sort(sort, flags); // 4 leaks
    mx_alphabet_sort(sort->files, sort->len_of_files_array);
    mx_alphabet_sort(sort->dirs, sort->len_of_dirs_array);
    add_inode_to_name_of_file(sort); // 2 leaks
    mx_output_by_size_of_wind(sort->files, sort->len_of_files_array);
    for (int j = 0; j < sort->len_of_dirs_array; ++j) {
        mx_printchar('\n');
        mx_printstr(sort->dirs[j]);
        mx_printstr(":\n");
        one_obj(sort->dirs[j]); // 5 leaks * sort->len_of_dirs_array
    }
    mx_del_strarr(&sort->files);
    mx_del_strarr(&sort->dirs);
    free(sort);

}

static void file_dir_sort(t_sorted_odj *sort, t_flags *flags) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    sort->files = (char **)malloc(sizeof(char *) * flags->number_of_obj); // NO
    sort->dirs = (char **)malloc(sizeof(char *) * flags->number_of_obj); // NO
    for (int i = 0; i < flags->number_of_obj; i++) {
        if (opendir(flags->all_obj[i])) {
            sort->dirs[a] = mx_strdup(flags->all_obj[i]);
            a++;
        } else {
            sort->files[b] = mx_strdup(flags->all_obj[i]);
            b++;
        }
    }
    for (int j = a; j < flags->number_of_obj; ++j) {
        sort->dirs[a] = NULL;
    }
    for (int j = b; j < flags->number_of_obj; ++j) {
        sort->files[b] = NULL;
    }
    while (sort->dirs[c] != NULL) {
        sort->len_of_dirs_array++;
        c++;
    }
    while (sort->files[d] != NULL) {
        sort->len_of_files_array++;
        d++;
    }
}

static void add_inode_to_name_of_file(t_sorted_odj *sort) {
    char **array = (char **)malloc(sizeof(char *) * sort->len_of_files_array);
    DIR *d;
    struct dirent *directory;
    for (int i = 0; i < sort->len_of_files_array; ++i) {
        char *current_file;
        char *current_dir = trim(sort->files[i], &current_file);
        d = opendir(current_dir);
        while ((directory = readdir(d)) != NULL) {
            if (mx_strcmp(directory->d_name, current_file) == 0) {
                array[i] = mx_strnew(directory->d_namlen + mx_intlen(directory->d_ino) + 1);
                array[i] = mx_strcpy(array[i], mx_itoa(directory->d_ino));
                array[i] = mx_strcat(array[i], " ");
                array[i] = mx_strcat(array[i], sort->files[i]);
            }
        }
        closedir(d);
        mx_strdel(&current_dir);
        mx_strdel(&current_file);
    }
    for (int j = 0; j < sort->len_of_files_array; ++j) {
        mx_strdel(&sort->files[j]);
        sort->files[j] = mx_strdup(array[j]);
        mx_strdel(&array[j]);
    }
    mx_del_strarr(&array);
}
