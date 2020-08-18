#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {

   char *str = (char *)haystack;
   char *sub_str = (char *)needle;
   int str_len = mx_strlen(haystack);
   int sub_str_len = mx_strlen(needle);
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
               free(temp_str);
               return str;
           }
           else {
               i = temp;
           }
       }
   }
    free(temp_str);
    return NULL;
}

