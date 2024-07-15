#ifndef __ADJACENCY_LIST
#define __ADJACENCY_LIST 0

typedef struct Node *NodePtr;
typedef struct Graph *GraphPtr;

NodePtr createNode(int);
GraphPtr createGraph(int);

#endif