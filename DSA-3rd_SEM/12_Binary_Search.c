#include<stdio.h>

int binary_search(int arr[],int n, int key){
    int low=0;
    int high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]== key){
            return mid+1;
        }
        else if(arr[mid]<key){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("ENTER THE SIZE OF THE ARRAY: ");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER THE ELEMENTS OF THE ARRAY: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    int key;
    printf("ENTER THE ELEMENT TO BE SEARCHED: ");
    scanf("%d",&key);

    int result = binary_search(arr,n,key);
    (result==-1)?printf("ELEMENT NOT FOUND"):printf("ELEMENT FOUND AT INDEX %d",result);
}
