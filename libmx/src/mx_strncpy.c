#include "libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
   char *donor = (char *)src;
   for (int i = 0; i < len; i++) {
       dst[i] = donor[i];
   }
   return dst;
}

