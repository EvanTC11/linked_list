#include "linked_list.h"
#include <stdio.h>

int main()
{
    Node* head = linked_list_create(67);
    printf("Size: %ld\n", linked_list_get_size(head));

    linked_list_free(head);
    return 0;
}
