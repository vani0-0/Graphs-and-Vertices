#include "../includes/traversals.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getVertexIndex(GraphPtr graph, char *vertex)
{

    for (int i = 0; i < graph->num_vertices; i++)
    {
        if (strcicmp(graph->vertices[i], vertex) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Helper function to print a path
void printPath(char *path[], int pathLength)
{
    for (int i = 0; i < pathLength; i++)
    {
        printf("%s ", path[i]);
    }
    printf("\n");
}

void BFS(GraphPtr graph, char *startVertex, int startIndex)
{
    if (startIndex == -1)
    {
        printf("Vertex %s not found in the graph.\n", startVertex);
        return;
    }
    bool *visited = (bool *)malloc(graph->num_vertices * sizeof(bool));
    for (int i = 0; i < graph->num_vertices; i++)
    {
        visited[i] = false;
    }
    NodePtr *queue = (NodePtr *)malloc(graph->num_vertices * sizeof(NodePtr));
    int front = 0, rear = 0;

    // Enqueue the start vertex
    visited[startIndex] = true;
    queue[rear++] = createNode(startVertex);
    while (front != rear)
    {
        NodePtr currentNode = queue[front++];
        int currentIndex = getVertexIndex(graph, currentNode->data);
        printf("%s ", currentNode->data);

        NodePtr temp = graph->list[currentIndex].head;
        while (temp)
        {
            int neighborIndex = getVertexIndex(graph, temp->data);
            if (!visited[neighborIndex])
            {
                visited[neighborIndex] = true;
                queue[rear++] = createNode(temp->data);
            }
            temp = temp->next;
        }
    }

    printf("\n");
    free(visited);
    free(queue);
}
void DFS(GraphPtr graph, char *startVertex) {}