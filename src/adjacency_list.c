#include "../includes/adjacency_list.h"

struct Node
{
    int vertex;
    NodePtr next;
};

struct Graph
{
    int num_vertext;
    NodePtr *list;
};