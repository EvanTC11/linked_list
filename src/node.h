#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    struct Node* next;
    void* data; 

    bool is_head;
} Node;

void node_create(void* data, Node* node, Node* prev);

#endif