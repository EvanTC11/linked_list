#ifndef LINKED_LIST_H 
#define LINKED_LIST_H

#include "node.h"

Node* linked_list_create(size_t size);
size_t linked_list_get_size(Node* head);
void linked_list_append(Node* head, void* data);
Node* linked_list_at_index(Node* head, size_t index);
void linked_list_free(Node* head);

#endif
