#include "libmx.h"

char *mx_strnew(const int size) {
	
	int size_for_new = size + 1;
	char *new_str = NULL;
	new_str = (char *)malloc(sizeof(char)*size_for_new);

	for (int i = 0; i < size_for_new; ++i) {
		new_str[i] = '\0';
	}

	return new_str;
}

