#include<stdio.h>
int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}
 
int main(){
    int n,x;
    printf("ENETER THE NUMBER OF ELEMENTS: ");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER THE ELEMENTS: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int size = sizeof(arr)/sizeof(int);
    printf("ENTER THE ELEMENT TO BE FOUND: ");
    scanf("%d",&x);
    int searchIndex = binarySearch(arr, size, x);

    // PRINT SECTION
    if (searchIndex == -1){
        printf("ELEMENT IS NOT PRESENT!!");
    }
    else{    
        printf("The element %d was found at index %d \n", x, searchIndex);
    }
    return 0;
}
