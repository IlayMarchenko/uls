#include "libmx.h"

void mx_push_front(t_list **list, void *data){

	t_list * new_first_node = (t_list*)malloc(sizeof(t_list));

	new_first_node->data = data;

	new_first_node->next = (*list);

	(*list) = new_first_node;

}

