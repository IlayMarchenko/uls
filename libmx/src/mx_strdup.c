#include "libmx.h"

char *mx_strdup(const char *s1) {
	int length = mx_strlen(s1);
	char *result = mx_strnew(length);
	mx_strcpy(result, s1);

	return result;
}
