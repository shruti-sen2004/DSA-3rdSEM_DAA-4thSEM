#include <stdio.h>
#include <stdlib.h>

#define INFINITY 9999
#define MAX 10

void bellmanford(int G[MAX][MAX], int n, int startnode);

int main(){
    int G[MAX][MAX], i, j, n, u;
    printf("ENTER THE NUMBER OF VERTICES: ");
    scanf("%d",&n);
    printf("\nENTER THE ADJACENCY MATRIX:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&G[i][j]);
        }
    }
    printf("\nENTER THE STARTING NODE: ");
    scanf("%d",&u);
    bellmanford(G,n,u);
    return 0;
}

void bellmanford(int G[MAX][MAX], int n, int startnode){
    int distance[MAX], pred[MAX];
    for(int i = 0; i < n; i++){              //INITIALIZE DISTANCE AND PRED ARRAY
        distance[i] = INFINITY;
        pred[i] = startnode;
    }
    distance[startnode] = 0;
    for(int i = 0; i < n-1; i++){            //RELAX ALL EDGES N-1 TIMES
        for(int u = 0; u < n; u++){
            for(int v = 0; v < n; v++){
                if(G[u][v] != 0){
                    if(distance[u] + G[u][v] < distance[v]){
                        distance[v] = distance[u] + G[u][v];
                        pred[v] = u;
                    }
                }
            }
        }
    }
    for(int u = 0; u < n; u++){              //CHECK FOR NEGATIVE CYCLE
        for(int v = 0; v < n; v++){
            if(G[u][v] != 0){
                if(distance[u] + G[u][v] < distance[v]){
                    printf("NEGATIVE CYCLE DETECTED\n");
                    return;
                }
            }
        }
    }
    printf("DISTANCE FROM NODE %d TO OTHER NODES:\n",startnode);
    for(int i = 0; i < n; i++){
        printf("NODE %d: %d\n",i,distance[i]);
    }
}
