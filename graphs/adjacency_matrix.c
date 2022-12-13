#include <stdio.h>

int no_vertices;

void printGraph(int adj[][no_vertices])
{
    for (int i = 0; i < no_vertices; i++)
    {
        for (int j = 0; j < no_vertices; j++)
        {
            printf(" %d  ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int s, d;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &no_vertices);
    int adj[no_vertices][no_vertices];

    for (int i = 0; i < no_vertices; i++)
        for (int j = 0; j < no_vertices; j++)
            adj[i][j] = 0;
    
    while (s!=-1 && d!=-1)
    {
        printf (
            "Enter the Edge fromnode (0 to %d) to node (0 to %d): ", 
            no_vertices, no_vertices
        );
        scanf("%d%d", &s, &d);
        adj[s][d] = 1;
        adj[d][s] = 1;
    }

    printGraph(adj);

    return 0;
}