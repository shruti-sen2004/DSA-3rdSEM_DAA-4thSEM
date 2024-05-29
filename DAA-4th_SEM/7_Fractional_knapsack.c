//fractinal knapsack

#include <stdio.h>
#include <stdlib.h>

void swap(float *x, float *y){
    float temp = *x;
    *x = *y;
    *y = temp;
}

void fractional_knapsack(int n, int weight[], int profit[], int capacity){
    float ratio[n];
    for(int i = 0; i < n; i++){
        ratio[i] = (float)profit[i]/weight[i];
    }

    for(int i = 0; i < n; i++){                        //SORTING THE ITEMS IN DESCENDING ORDER OF PROFIT/WEIGHT
        for(int j = n-1; j > i; j--){
            if(ratio[j] > ratio[j-1]){
                swap(&ratio[j], &ratio[j-1]);
                swap(&weight[j], &weight[j-1]);
                swap(&profit[j], &profit[j-1]);
            }
        }
    }
    int current_weight = 0;
    float final_profit = 0.0;
    for(int i = 0; i < n; i++){
        if(current_weight + weight[i] <= capacity){    //IF THE ITEM CAN BE ADDED COMPLETELY
            current_weight += weight[i];
            final_profit += profit[i];
        }
        else{
            int remaining = capacity - current_weight;  //IF THE ITEM CANNOT BE ADDED COMPLETELY
            final_profit += profit[i] * ((float)remaining/weight[i]);
            break;
        }
    }
    printf("MAXIMUM PROFIT: %.2f\n",final_profit);
}

int main(){
    int n;
    printf("ENTER THE NUMBER OF ITEMS: ");
    scanf("%d",&n);
    int weight[n], profit[n];
    printf("ENTER THE WEIGHT OF THE ITEMS: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&weight[i]);
    }
    printf("ENTER THE PROFIT OF THE ITEMS: ");
    for(int i = 0; i < n; i++){
        scanf("%d",&profit[i]);
    }
    int capacity;
    printf("ENTER THE CAPACITY OF THE KNAPSACK: ");
    scanf("%d",&capacity);
    fractional_knapsack(n,weight,profit,capacity);
    return 0;
}
