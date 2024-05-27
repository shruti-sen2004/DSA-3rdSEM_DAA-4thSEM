#include<stdio.h>

int max, min;
int arr[100];
void max_min(int i, int j){
    int max1, min1, mid;
    if (i==j){
        max1=min1=arr[i];
    }
    else{
        if(i==j-1){
            (arr[i]>arr[j])?(max=arr[i],min=arr[j]):(max=arr[j],min=arr[i]);
        }
        else{
            mid= i+j/2;
            max_min(i,mid);
            max1=max;
            min1=min;
            max_min(mid+1,j);
            (max<max1)?max=max1:(min=min1);
        }
    }
}

int main(){
    int n;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS OF THE ARRAY: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    max=arr[0];
    min=arr[0];
    max_min(0,n-1);
    printf("MAXIMUM ELEMENT: %d\n",max);
    printf("MINIMUM ELEMENT: %d\n",min);
}
