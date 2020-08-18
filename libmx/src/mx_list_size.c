#include "libmx.h"

int mx_list_size(t_list *list) {

	t_list *clone = list;
	int result = 0;

	while(clone){
		clone = clone->next;
		result++;
	}

	return result;
}

