#include "linked_list.h"

Node* linked_list_create(size_t size)
{
    Node* head = (Node*)malloc(sizeof(Node) * size);
    head->is_head = true;

    Node* current = head;
    Node* next = NULL;

    for (size_t i = 0; i < size; i++)
    {
        current = (head + i);
        next = (current + 1);

        if (i < size - 1)
        {
            current->next = next;
        }

        else
        {
            current->next = NULL;
        }

        current->data = NULL;
        current->allocated = true;
    }

    (head + size - 1)->next = NULL;
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
    // size_t size = linked_list_get_size(head);
    Node* ptr = head;
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->is_head = false;
    new->next = NULL;
    new->allocated = true;

    ptr->next = new; 
}

Node* linked_list_at_index(Node* head, size_t index)
{
    if (index > linked_list_get_size(head))
    {
        return NULL;
    }

    if (index == 0)
    {
        return head;
    }

    Node* ptr = head;
    for (size_t i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }

    return ptr;
}

void linked_list_free(Node* head)
{
    Node* ptr = head;
    Node* next = NULL;

    while (ptr)
    {
        if (!ptr->is_head)
        {
            next = ptr->next;
            free(ptr);
        }

        ptr = next;
    }

    free(head);
}