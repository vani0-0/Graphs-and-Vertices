#include "../includes/node.h"

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "stdbool.h"

NodePtr createNode(char *vertex)
{
    NodePtr node = (NodePtr)malloc(sizeof(struct Node));
    node->data = (char *)malloc(sizeof(char) * strlen(vertex));
    strncpy(node->data, vertex, strlen(vertex));
    node->data[strlen(vertex)] = '\0';
    node->next = NULL;
    return node;
}