#include<stdio.h>
void merge(int A[],int low,int mid, int high){
    int n1= mid-low+1;
    int n2= high- mid;
    int left[n1], right[n2];
    for(int i=0; i<n1; i++){
        left[i]= A[low +i];
    }
    for(int j=0; j<n2; j++){
        right[j]= A[mid+1+j];
    }
    //merging now
    int i=0,j=0,k=low;
    while((i<n1)&&(j<n2)){
        if(left[i]<=right[j]){
            A[k]= left[i];
            i++;
        }
        else{
            A[k]= right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k]= left[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]= right[j];
        j++;
        k++;
    }
}

void mergesort(int A[],int low, int high){
    if(low<high){
        int mid =(low+high)/2;
        mergesort(A,low,mid);
        mergesort(A,mid+1,high);
        merge(A,low,mid,high);
    }
}

void main()
{       
    int i,j,n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the numbers to be sorted using Quick Sort in the array below:-\n");
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);

    printf("Unsorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    mergesort(A,0,n-1);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
}