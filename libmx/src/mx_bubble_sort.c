#include "libmx.h"

int mx_bubble_sort(char **arr, int size) {
	
	int counter = 0;
	char *temp;

	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			if (mx_strcmp(arr[j], arr[i]) < 0) {
				counter++;
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

	return counter;
}


