#include "../includes/graph.h"
#include "../includes/traversals.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STR 124

void trim_newline(char *str)
{
    str[strcspn(str, "\n")] = 0;
}

int main()
{

    FILE *fptr;
    char file_name[MAX_STR];

    printf("Input filename: ");
    fgets(file_name, MAX_STR, stdin);
    file_name[strcspn(file_name, "\n")] = 0;
    fptr = fopen(file_name, "r");

    if (fptr == NULL)
    {
        printf("\033[31m%s not found.\033[0m", file_name);
        return 1;
    }

    char line[MAX_STR];
    int number_of_vertices = 0;

    if (fscanf(fptr, "%s", line) != EOF)
    {
        number_of_vertices = atoi(line);
    }
    GraphPtr graph = createGraph(number_of_vertices);
    char source[MAX_STR], destination[MAX_STR];
    int count = 0;
    while (fscanf(fptr, "%s", line) != EOF)
    {
        if (strcmp(line, "-1") == 0)
        {
            if (source[0] != 0)
                source[0] = 0;
        }
        else
        {
            if (source[0] == 0)
            {
                strcpy(source, line);
                strncpy(graph->vertices[count], source, strlen(source) + 1);
                count++;
            }
            else
            {
                strcpy(destination, line);
                // printf("Destination: %s\n", destination);
                // TODO: In progress here
                addEdge(graph, source, destination);
            }
        }
    }
    printGraph(graph);

    freeGraph(graph);
    fclose(fptr);

    char vertex_id[MAX_STR];
    printf("Input start vertex for traversal: ");
    fgets(vertex_id, MAX_STR, stdin);
    trim_newline(vertex_id);

    int index = vertexExists(graph, vertex_id);

    if (index == -1)
    {
        printf("\033[31mVertex %s not found.\033[0m\n", vertex_id);
        freeGraph(graph);
        return 1;
    }

    BFS(graph, vertex_id, index);

    return 0;
}
