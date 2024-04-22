#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define MAX_VERTICES 100
#define MAX_EDGES 100


void bellmanFord(int graph[MAX_EDGES][3], int V, int E, int source) {
	int i, j;
    int distance[MAX_VERTICES];
    for (i = 0; i < V; i++)
        distance[i] = INT_MAX;
    distance[source] = 0; 

    
    for (i = 1; i <= V - 1; i++) {
        for (j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (distance[u] != INT_MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
        }
    }

   
    for (i = 0; i < E; i++) {
        int u = graph[i][0];
        int v = graph[i][1];
        int weight = graph[i][2];
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

   
    printf("Vertex   Distance from Source\n");
    for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, distance[i]);
}

int main() {
    int V = 6;
    int E = 9; 
    int graph[MAX_EDGES][3] = {{0, 1, 6}, {0, 2, 4}, {0, 3, 5}, {1, 4, -1}, {2, 1, -2}, {2, 4, 3}, {3, 2, -2}, {3, 5, -1}, {4, 5, 3}};
    int source = 0; 

    bellmanFord(graph, V, E, source);

    return 0;
}
