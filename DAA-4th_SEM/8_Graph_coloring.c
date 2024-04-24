#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];
int num_vertices;

void inputGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);
    int i;
    int j;

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < num_vertices; i++) {
        for (j = 0; j < num_vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int isSafe(int v, int c) {
	int i;
    for (i = 0; i < num_vertices; i++) {
        if (graph[v][i] && c == color[i])
            return 0;
    }
    return 1;
}

int graphColoringUtil(int v, int num_colors) {
    if (v == num_vertices)
        return 1;
        int c;
        

    for (c = 1; c <= num_colors; c++) {
        if (isSafe(v, c)) {
            color[v] = c;
            if (graphColoringUtil(v + 1, num_colors))
                return 1;
            color[v] = 0;
        }
    }
    return 0;
}

void graphColoring(int num_colors) {
    if (graphColoringUtil(0, num_colors)) {
        printf("The coloring of vertices is:\n");
        int i;
        for (i = 0; i < num_vertices; i++) {
            printf("Vertex %d -> Color %d\n", i + 1, color[i]);
        }
    } else {
        printf("Solution does not exist with %d colors.\n", num_colors);
    }
}

int main() {
    int num_colors;
    
    inputGraph();
    
    printf("Enter the number of colors: ");
    scanf("%d", &num_colors);
    
    graphColoring(num_colors);
    
    return 0;
}