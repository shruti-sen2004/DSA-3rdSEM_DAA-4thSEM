#include<stdio.h>

int binary_search_itr(int arr[],int n, int key){        //ITERATIVE BINARY SEARCH
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

int binary_search_rec(int arr[],int low, int high, int key){        //RECURSIVE BINARY SEARCH
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;
    if(arr[mid]==key){
        return mid+1;
    }
    else if(arr[mid]<key){
        return binary_search_rec(arr,mid+1,high,key);
    }
    else{
        return binary_search_rec(arr,low,mid-1,key);
    }
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

    int result_itr = binary_search_itr(arr,n,key);
    int result_rec = binary_search_rec(arr,0,n-1,key);
    (result_itr==-1)?printf("\nELEMENT NOT FOUND ITR"):printf("\nELEMENT FOUND ITERATIVELY AT INDEX %d",result_itr);
    (result_rec==-1)?printf("\nELEMENT NOT FOUND REC"):printf("\nELEMENT FOUND RECCURSIVELY AT INDEX %d",result_rec);
}
