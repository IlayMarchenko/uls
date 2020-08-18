#include "libmx.h"

void mx_pop_front(t_list **head) {
    t_list *next_node = NULL;
    if (head && *head) {
        next_node = (*head)->next;
        free(*head);
        *head = next_node;
    }
}
