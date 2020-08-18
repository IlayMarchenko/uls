#include "libmx.h"

int mx_get_substr_index (const char *str, const char *sub) {
  if (!str || !sub || str == NULL || sub == NULL) {
      return -2;
  }
  if (mx_strstr(str, sub) == NULL) {
       return -1;
   }
   char *str1 = (char *)str;
   char *sub_str = (char *)sub;
   int str_len = mx_strlen(str);
   int sub_str_len = mx_strlen(sub);
   char *temp_str = mx_strnew(sub_str_len);
   int temp = 0;

   for (int i = 0; i < str_len; i++) {
       if (str1[i] == sub_str[0]) {
           temp = i;
           for (int j = 0; j < sub_str_len; j++) {
               temp_str[j] = str[i];
               i++;
           }
           if (mx_memcmp(temp_str, sub_str, sub_str_len) == 0) {
               free(temp_str);
               return temp;
           }
           else {
               i = temp;
           }
       }
   }
   free(temp_str);
   return -2;
}




