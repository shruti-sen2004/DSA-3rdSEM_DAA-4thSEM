#include <stdio.h> 
  
int search(int arr[], int N, int x) 
{ 
    for (int i = 0; i < N; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
// Driver code 
int main(void) 
{   int n,x;
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d",&n);
    int arr[n]; 
    printf("ENTER THE ELEMENTS: \n");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("ENTER THE NUMBER TO BE SEARCHED: ");
    scanf("%d",&x); 
    int N = sizeof(arr) / sizeof(arr[0]); 
  
    // Function call 
    int result = search(arr, N, x); 
    (result == -1) 
        ? printf("Element is not present in array") 
        : printf("Element is present at index %d", result); 
    return 0; 
}