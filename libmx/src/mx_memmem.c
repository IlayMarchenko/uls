#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {

	char *str = (char *)big;
	char *sub_str = (char *)little;
	int str_len = (int)big_len;
	int sub_str_len = (int)little_len;
	char *temp_str = mx_strnew(sub_str_len);
	int temp = 0;

	for (int i = 0; i < str_len; i++) {
		if (str[i] == sub_str[0]) {
			temp = i;
			for (int j = 0; j < sub_str_len; j++) {
				temp_str[j] = str[i];
				i++;
			}
			if (mx_memcmp(temp_str, sub_str, sub_str_len) == 0) {
				for (int a = 0; a < temp; a++) {
					str++;
				}
				return str;
			}
			else {
				i = temp;
			}
		}
	}

	return NULL;
}

