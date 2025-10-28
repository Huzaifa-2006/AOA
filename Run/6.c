#include <stdio.h>

#define V 4
#define INF 99999  // Infinity value for unreachable paths

void printSolution(int dist[V][V]) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V];

    // Step 1: Initialize the solution matrix same as the input graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    // Step 2: Update the matrix using each vertex as an intermediate point
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Step 3: Print the result
    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0,   3,  INF, 5},
        {2,   0,  INF, 4},
        {INF, 1,   0, INF},
        {INF, INF, 2,   0}
    };

    floydWarshall(graph);
    return 0;
}

