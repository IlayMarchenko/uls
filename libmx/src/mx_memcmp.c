#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	
	int size  = (int)n;
	char *str1 = (char *)s1;
	char *str2 = (char *)s2;

	for (int i = 0; i < size; i++) {
		if (str1[i] != str2[i]) {
			return str1[i] - str2[i];
		}
	}
	return 0;
}

