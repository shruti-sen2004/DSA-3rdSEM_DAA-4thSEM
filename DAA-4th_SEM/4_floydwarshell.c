#include<stdio.h>


int min(int a, int b){
    return (a<b)?a:b;
}

void floyd_warshall(int graph[100][100], int n){
    int dist[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    printf("THE SHORTEST PATHS BETWEEN EVERY PAIR OF VERTICES ARE: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%2d ",dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("ENTER THE NUMBER OF VERTICES: ");
    scanf("%d",&n);
    int graph[100][100];
    printf("ENTER THE ADJACENCY MATRIX: \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&graph[i][j]);
        }
    }
    floyd_warshall(graph,n);
}
