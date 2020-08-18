#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    char *temp_str = NULL;
    char buff[buf_size + 1];
    int index_of_delim;
    int x = 0;
    int i = 1;
    static char *static_str = NULL;
    int len_of_static = 0;

    bool find_delim = false;
    buff[buf_size] = '\0';
    temp_str = (char *)malloc(sizeof(char) * (buf_size + 1) * i);
    temp_str[buf_size] = '\0';

    // check static variable
    if (static_str != NULL){
        // try to find needed element
        index_of_delim = mx_get_char_index(static_str, delim);
        len_of_static = mx_strlen(static_str);

        // allocate memory for temporary variable
        temp_str = (char *)mx_realloc(temp_str, sizeof(char) * (buf_size) * i + len_of_static);

        // import data from static variable to temporary
        mx_strcat(temp_str, static_str);

        // check if we have needed element into static string and if yes, return data to string lineptr and number of elements there. Update data in static string
        if (index_of_delim >= 0) {
            free(*lineptr);
        	(*lineptr) = mx_strnew(index_of_delim + 1);
            for (int j = 0; j < index_of_delim; j++) {
                (*lineptr)[j] = static_str[j];
            }
            if (static_str != NULL) {
                free(static_str);
                static_str = mx_strnew(buf_size + 1);
            }
            for (int k = index_of_delim; temp_str[k]; k++) {
                static_str[x] = temp_str[k + 1];
                x++;
            }
            free(temp_str);
            return index_of_delim;
        }
    }

    // refresh static string to import new data value here
    free(static_str);
    static_str = mx_strnew(buf_size + 1);

    // loop finding needed element, update static string, return data into lineptr and find number of element which we passed into this string.
    while(!find_delim) {
        // reallocate more memory every time when we need it
        temp_str = (char *)mx_realloc(temp_str, sizeof(char) * (buf_size) * i + len_of_static);

        // read new data into buffer if it is possible and return -1 if not
        if (read(fd, buff, buf_size)) {}
        else {
            return -1;
        }

        // concatenates 2 strings : temporary and buffer
        mx_strcat(temp_str, buff);
        index_of_delim = mx_get_char_index(temp_str, delim);

        // check if we have needed element into temporary string and if yes, return data to string lineptr and number of elements there. Update data in static string
        if (index_of_delim >= 0) {
            free(*lineptr);
        	(*lineptr) = mx_strnew(index_of_delim + 1);
            for (int j = 0; j < index_of_delim; j++) {
                (*lineptr)[j] = temp_str[j];
            }
            if (static_str != NULL) {
                free(static_str);
                static_str = mx_strnew(buf_size + 1);
            }
            for (int k = index_of_delim; temp_str[k]; k++) {
                static_str[x] = temp_str[k + 1];
                x++;
            }
            find_delim = true;
        }
        else {
            i++;
        }
    }
    free(temp_str);
    return index_of_delim;
}

//int main() {
//	int fd = open("../fragment", O_RDONLY);
//	char *str = NULL;
//
//    str = mx_strnew(170);
//
//    // 1
//	int res = mx_read_line(&str, 30, 'f', fd);
//	printf("res is %d\n", res);
//	printf("%s\n", str);
//
//	// 2
//    res = mx_read_line(&str, 35, 't', fd);
//    printf("res is %d\n", res);
//    printf("%s\n", str);
//
//    // 3
//
//    res = mx_read_line(&str, 30, '.', fd);
//    printf("res is %d\n", res);
//    printf("%s\n", str);
//
//
//	close(fd);
//
//    system("leaks untitled");
//
//	return 0;
//}

