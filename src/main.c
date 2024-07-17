#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../includes/adjacency_list.h"

#define MAX_STR 124

// Start
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
        printf("%s not found.", file_name);
        return 1;
    }

    char line[MAX_STR];
    int number_of_vertices = 0;
    GraphPtr graph;

    if (fscanf(fptr, "%s", line) != EOF)
    {
        number_of_vertices = atoi(line);
        graph = createGraph(number_of_vertices);
    }

    char source[MAX_STR], destination[MAX_STR];
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
                // printf("Source: %s\n", source);
            }
            else
            {
                strcpy(destination, line);
                // printf("Destination: %s\n", destination);
                addEdge(graph, source, destination);
            }
        }
    }

    printGraph(graph);
    fclose(fptr);
    return 0;
}
