#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *cur = NULL;

    if (head && *head && (*head)->next) {
        cur = *head;
        while (cur->next->next)
            cur = cur->next;
        free(cur->next);
        cur->next = NULL;
    } else if (head && *head) {
        free(*head);
        *head = NULL;
    }
}
