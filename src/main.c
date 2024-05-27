#include "linked_list.h"
#include <stdio.h>

int main()
{
    Node* head = linked_list_create(&head);
    linked_list_append(head, (void*)"Hello World");

    for (int i = 0; i < 1000; i++)
    {
        linked_list_append(head, (void*)&i);
    }



    printf("%ld\n", linked_list_get_size(head));
    printf("%s\n", (const char*)linked_list_at_index(head, 1)->data);

    printf("%d\n", *(int*)linked_list_at_index(head, 283)->data);

    linked_list_free(head);
    return 0;
}