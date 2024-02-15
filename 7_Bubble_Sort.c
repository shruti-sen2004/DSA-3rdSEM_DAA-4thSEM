// BUBBLE SORTING
#include<stdio.h>
int main(){
    int a[10],n,i,j,t;
    printf("HOW MANY NUMBERS DO YOU WANT TO SORT= ");
    scanf("%d",&n);
    printf("ENTER THE NUMBER: ");
    for(i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]> a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    printf("ASCENDING ORDER=\n");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
}
printf("\nDESCENDING ORDER=\n");
    for(i=n-1;i>=0;i--){
        printf("%d ",a[i]);
}
}