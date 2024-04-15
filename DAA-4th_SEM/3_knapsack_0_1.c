#include <stdio.h>
#include <string.h>
int findMax(int n1, int n2){
   if(n1>n2) {
      return n1;
   } else {
      return n2;
   }
}
int knapsack(int W, int wt[], int val[], int n){
   int K[n+1][W+1];
   for(int i = 0; i<=n; i++) {
      for(int w = 0; w<=W; w++) {
         if(i == 0 || w == 0) {
            K[i][w] = 0;
         } else if(wt[i-1] <= w) {
            K[i][w] = findMax(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
         } else {
            K[i][w] = K[i-1][w];
         }
      }
   }
   return K[n][W];
}
int main(){
    int n,w,W;
    printf("ENTER THE TOTAL NO. OF PROFITS: ");
    scanf("%d",&n);
    printf("ENTER THE TOTAL NO. OF WEIGHTS: ");
    scanf("%d",&w);
   int profit[n] , wt[w];
   printf("ENTER THE PROFITS: ");
   for (int i=0; i<n;i++){
    scanf("%d",&profit[i]);
   }

   printf("ENTER THE WEIGHTS: ");
   for (int i=0; i<n;i++){
    scanf("%d",&wt[i]);
   }
   printf("ENTER THE TOTAL NO. OF SACK WEIGHT: ");
   scanf("%d",&W);
   int len = sizeof profit / sizeof profit[0];
   printf("Maximum Profit achieved with this knapsack: %d", knapsack(W, wt, profit, len));
}