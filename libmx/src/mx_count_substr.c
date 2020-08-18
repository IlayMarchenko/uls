#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	
	char *string = (char *)str;
	char *sub_string = (char *)sub;
	int len_str;
	int len_sub;
	int current_index;
	int result = 0;
	bool loop = true;

	len_str = mx_strlen(string);
	len_sub = mx_strlen(sub_string);

	while (loop) {
		current_index = mx_get_substr_index(string, sub_string);
		if (current_index >= 0) {
			result++;
			for (int j = 0; j < current_index + 1; j++) {
				string++;
			}
		}
		else {
			loop = false;
		}
	}
	return result;
}

