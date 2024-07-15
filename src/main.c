#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR 124

// Start
int main()
{
    FILE *fptr;
    char file_name[MAX_STR];
    // vertex_id[MAX_STR];

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
    int index = 0;

    while (fscanf(fptr, "%s", line) != EOF)
    {
        if (index == 0)
            number_of_vertices = atoi(line);
        else
        {
                }
        index++;
    }

    fclose(fptr);
    // printf("Input start vertext for the traversal: ");
    // fgets(vertex_id, MAX_STR, stdin);
    // printf("Vertext ID: ");
    // puts(vertex_id);

    // *Todo: Output filename "TRAVERSALS.txt"
    // ? A list of vertex IDs with the corresponding degree for each vertex. Using the graph in Figure 1 as an example, the output will be (shown in blue text color):
    // ? A list of vertex IDs that correspond to a BFS traversal from a specified start vertex.
    // ? A list of vertex IDs that correspond to a DFS traversal from a specified start vertex (note: same start vertex as in BFS traversal).
    return 0;
}
