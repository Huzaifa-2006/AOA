#include <stdio.h>

#define MAX 20  // Maximum number of vertices

int adj[MAX][MAX];   // Adjacency matrix to represent the graph
int visited[MAX];    // Array to keep track of visited vertices
int n;               // Number of vertices in the graph

// Recursive function for Depth First Search
void DFS(int v) 
{
    int i;

    // Mark the current vertex as visited and print it
    visited[v] = 1;
    printf("%d ", v);

    // Visit all adjacent unvisited vertices
    for(i = 1; i <= n; i++) 
    {
        // If there's an edge from v to i and i is not visited
        if(adj[v][i] == 1 && visited[i] == 0) 
        {
            DFS(i);  // Recur for the adjacent vertex
        }
    }
}

int main() 
{
    int i, j, start;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    printf("Enter adjacency matrix of the graph:\n");
    for(i = 1; i <= n; i++) 
    {
        for(j = 1; j <= n; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize all vertices as unvisited
    for(i = 1; i <= n; i++) 
    {
        visited[i] = 0;
    }

    // Input starting vertex for DFS
    printf("Enter starting vertex (1 - %d): ", n);
    scanf("%d", &start);

    // Perform DFS traversal
    printf("DFS Traversal starting from vertex %d: ", start);
    DFS(start);

    return 0;
}

