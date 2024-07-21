#ifndef __GRAPH_H
#define __GRAPH_H 1
#include "../includes/node.h"
typedef struct Graph *GraphPtr;

struct Graph
{
    int num_vertices;
    char **vertices;
    NodeListPtr list;
};
GraphPtr createGraph(int num_vertices);
void addEdge(GraphPtr graph, char *source, char *destination);
void printGraph(GraphPtr graph);
void freeGraph(GraphPtr graph);
int vertexExists(GraphPtr graph, char *vertex_id);
int strcicmp(const char *a, const char *b);

#endif // __GRAPH_H