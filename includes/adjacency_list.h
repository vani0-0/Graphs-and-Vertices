#ifndef __ADJACENCY_LIST
#define __ADJACENCY_LIST 0

#define MAX_VERTEX 124
typedef struct Node *NodePtr;
typedef struct Graph *GraphPtr;

NodePtr createNode(char *vertex);
GraphPtr createGraph();
void addEdge(GraphPtr graphPtr, char *source, char *destination);
void printGraph(GraphPtr graphPtr);

#endif