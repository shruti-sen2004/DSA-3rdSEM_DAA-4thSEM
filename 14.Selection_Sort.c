//SELECTION SORT 
#include<stdio.h>
int main(){
    int a[10],n,i,j,t,min;
    printf("HOW MANY NUMBERS DO YOU WANT TO SORT= ");
    scanf("%d",&n);
    printf("ENTER THE NUMBER: ");
    for(i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        min=i;
        for(j=1+i;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        t=a[min];
        a[min]=a[i];
        a[i]=t;
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