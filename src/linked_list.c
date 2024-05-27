#include "linked_list.h"

Node* linked_list_create()
{
    Node* head = (Node*)malloc(sizeof(Node) * 10);

    head->data = NULL;
    head->is_head = true;
    head->next = NULL;

    return head;
}

size_t linked_list_get_size(Node* head)
{
    size_t size = 1;
    Node* nextNode = head;
    while(nextNode->next)
    {
        nextNode = nextNode->next;
        size++;
    }

    return size;
}

void linked_list_append(Node* head, void* data)
{
    size_t size = linked_list_get_size(head);
    if (size == 10)
        return;

    Node* new = (head + size);
    new->data = data;
    new->is_head = false;
    new->next = NULL;
}