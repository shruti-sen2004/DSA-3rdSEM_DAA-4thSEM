#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int G[MAX][MAX], color[MAX], n;

void nextValue(int k){
    int j;
    while(1){
        color[k] = (color[k] + 1) % (n+1);
        if(color[k] == 0)
            return;
        for(j = 0; j < n; j++){
            if(G[k][j] != 0 && color[k] == color[j])
                break;
        }
        if(j == n)
            return;
    }
}

int flag = 1;

void graphColoring(int k){
    int i;
    while(flag){
        nextValue(k);
        
        if(color[k] == 0)
            return;
        if(k == n-1){
            for(i = 0; i < n; i++){
                printf("NODE %d: COLOR %d\n",i+1,color[i]);
            }
            printf("\n");
            flag= 0;
        }
        else{
            graphColoring(k+1);
        }
    }
}

int main(){
    int i, j;
    printf("ENTER THE NUMBER OF VERTICES: ");
    scanf("%d",&n);
    printf("\nENTER THE ADJACENCY MATRIX:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&G[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        color[i] = 0;
    }
    printf("\nDesired graph coloring\n");graphColoring(0);
    return 0;
}
