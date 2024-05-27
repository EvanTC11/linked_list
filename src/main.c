#include "linked_list.h"
#include <stdio.h>

int main()
{
    Node* head = linked_list_create(&head);
    linked_list_append(head, (void*)"Hello World");

    printf("%ld\n", linked_list_get_size(head));
    printf("%s\n", (const char*)head->next->data);

    free(head);
    free(head->next);
    return 0;
}