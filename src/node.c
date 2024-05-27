#include "node.h"

#include <stdio.h>

void node_create(void* data, Node* node, Node* prev)
{
    node->data = data;

    if (prev)
    {
        prev->next = node;
    }

    else
    {
        node->is_head = true;
    }
}