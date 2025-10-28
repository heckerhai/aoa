#include <stdio.h>

#define V 4
#define INF 99999

// Function to print the final shortest distance matrix
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

// Floyd–Warshall algorithm implementation
void floydWarshall(int dist[V][V]) {
    for (int k = 0; k < V; k++) {           // ----- INTERMEDIATE NODE -----
        for (int i = 0; i < V; i++) {       // ----- SOURCE NODE -----
            for (int j = 0; j < V; j++) {   // ----- DESTINATION NODE -----
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}

// Main function
int main() {
    int graph[V][V] = {
        { 0,   9,  -4, INF },
        { 6,   0, INF,   2 },
        { INF, 5,   0, INF },
        { INF, INF, 1,   0 }
    };

    floydWarshall(graph);
    return 0;
}
