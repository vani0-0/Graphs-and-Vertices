#include "../includes/adjacency_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Node
{
    char *vertex;
    struct Node *next;
};

struct Graph
{
    int num_vertices;
    NodePtr *list;
};

NodePtr createNode(char *vertex)
{
    NodePtr node = malloc(sizeof(struct Node));
    if (node == NULL)
    {
        printf("Memory allocation error\n");
        return NULL;
    }

    node->vertex = malloc((strlen(vertex) + 1) * sizeof(char));
    if (node->vertex == NULL)
    {
        printf("Memory allocation error\n");
        free(node);
        return NULL;
    }

    strcpy(node->vertex, vertex);
    node->next = NULL;
    return node;
}

void addEdge(GraphPtr graphPtr, char *source, char *destination)
{
    NodePtr desNode = createNode(destination);
    desNode->next = graphPtr->list[];

    NodePtr srcNode = createNode(source);
    if (srcNode != NULL && desNode != NULL)
    {
        desNode->next = graphPtr->list[graphPtr->num_vertices];
        graphPtr->list[graphPtr->num_vertices] = desNode;

        srcNode->next = graphPtr->list[graphPtr->num_vertices];
        graphPtr->list[graphPtr->num_vertices] = srcNode;

        graphPtr->num_vertices++;
    }
}

GraphPtr createGraph(int num_vertices)
{
    GraphPtr graph = malloc(sizeof(struct Graph));
    if (graph == NULL)
    {
        printf("Memory allocation error\n");
        return NULL;
    }

    graph->num_vertices = num_vertices;

    graph->list = malloc(num_vertices * sizeof(NodePtr));
    if (graph->list == NULL)
    {
        printf("Memory allocation error\n");
        free(graph);
        return NULL;
    }

    for (int i = 0; i < num_vertices; i++)
        graph->list[i] = NULL;

    return graph;
}

void printGraph(GraphPtr graph)
{
    if (graph == NULL)
    {
        printf("Graph is NULL\n");
        return;
    }

    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (graph->list[i] != NULL)
        {
            printf("Adjacency list of vertex %d (%s): ", i, graph->list[i]->vertex);
            NodePtr current = graph->list[i];
            while (current != NULL)
            {
                printf("%s -> ", current->vertex);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}
