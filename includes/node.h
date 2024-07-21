#ifndef __NODE_H
#define __NODE_H 1

typedef struct Node *NodePtr;
typedef struct NodeList *NodeListPtr;

struct NodeList
{
    NodePtr head;
    int count;
};

struct Node
{
    char *data;
    struct Node *next;
};

NodePtr createNode(char *vertex);

#endif // __NODE_H