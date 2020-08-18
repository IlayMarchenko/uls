#include "libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
	int size = n;
	char *res = (char *)dst;
	char *donor = (char *)src;

	for (int i = 0; i < size; i++) {
		res[i] = donor[i];
	}
	return res;
}

