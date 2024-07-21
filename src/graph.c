#include "../includes/graph.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 120

GraphPtr createGraph(int num_vertices)
{
    GraphPtr graph = (GraphPtr)malloc(sizeof(struct Graph));
    if (graph == NULL)
        return NULL;

    graph->num_vertices = num_vertices;

    graph->list = (NodeListPtr)malloc(num_vertices * sizeof(struct NodeList));
    if (graph->list == NULL)
    {
        free(graph);
        return NULL;
    }

    for (int i = 0; i < num_vertices; i++)
        graph->list[i].head = NULL;

    graph->vertices = (char **)malloc(num_vertices * sizeof(char *));
    if (graph->vertices == NULL)
    {
        free(graph->list);
        free(graph);
        return NULL;
    }

    for (int i = 0; i < num_vertices; i++)
    {
        graph->vertices[i] = (char *)malloc(100 * sizeof(char));
        if (graph->vertices[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(graph->vertices[j]);
            free(graph->vertices);
            free(graph->list);
            free(graph);
            return NULL;
        }
    }

    return graph;
}

void addEdge(GraphPtr graph, char *source, char *destination)
{
    NodePtr new_node = createNode(destination);
    int source_index = -1, destination_index = -1;

    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (strcmp(graph->vertices[i], source) == 0)
        {
            source_index = i;
            break;
        }
    }

    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (strcmp(graph->vertices[i], destination) == 0)
        {
            destination_index = i;
            break;
        }
    }

    if (source_index != -1 && destination_index != -1)
    {
        new_node->next = graph->list[source_index].head;
        graph->list[source_index].head = new_node;
        graph->list[source_index].count += 1;

        new_node = createNode(source);
        new_node->next = graph->list[destination_index].head;
        graph->list[destination_index].head = new_node;
        graph->list[destination_index].count += 1;
    }
}

void printGraph(GraphPtr graph)
{
    for (int v = 0; v < graph->num_vertices; v++)
    {
        NodePtr temp = graph->list[v].head;
        printf("\n List %s: %d", graph->vertices[v], graph->list[v].count);
        while (temp)
        {
            printf(" - %s", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void freeGraph(GraphPtr graph)
{
    for (int i = 0; i < graph->num_vertices; i++)
    {
        NodePtr node = graph->list[i].head;
        while (node != NULL)
        {
            NodePtr temp = node;
            node = node->next;
            free(temp);
        }
        free(graph->vertices[i]);
    }
    free(graph->vertices);
    free(graph->list);
    free(graph);
}

int strcicmp(const char *a, const char *b)
{
    for (;; a++, b++)
    {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}

int vertexExists(GraphPtr graph, char *vertex_id)
{
    if (graph == NULL || vertex_id == NULL)
    {
        return -1;
    }

    size_t vertex_id_len = strlen(vertex_id);
    char *lower_vertex_id = (char *)malloc(vertex_id_len + 1);
    if (lower_vertex_id == NULL)
    {
        return -1;
    }
    strncpy(lower_vertex_id, vertex_id, vertex_id_len + 1);

    for (int i = 0; i < graph->num_vertices; i++)
    {
        size_t vertex_len = strlen(graph->vertices[i]);
        char *lower_vertex = (char *)malloc(vertex_len + 1);
        if (lower_vertex == NULL)
        {
            free(lower_vertex_id);
            return -1;
        }
        strncpy(lower_vertex, graph->vertices[i], vertex_len + 1);

        if (strcicmp(lower_vertex_id, lower_vertex) == 0)
        {
            free(lower_vertex_id);
            free(lower_vertex);
            return i;
        }
        free(lower_vertex);
    }

    free(lower_vertex_id);
    return -1;
}