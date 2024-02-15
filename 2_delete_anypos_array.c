#include<stdio.h>
void main(){
    int p,c,i,n;
    printf("ENTER THE NO. OF ELEMENTS: ");
    scanf("%d",&n);
    int a[n];

    printf("\nENTER THE ELEMENTS- ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("\nENTER THE POSITION WHERE ELEMENT NEEDS TO BE DELETED- ");
    scanf("%d",&p);

    if(p>n){
        printf("INVALID INPUT!!");
    }

    for(i=p;i<n-1;i++){
        a[i]=a[i+1];
    }

    printf("\nEDITED ARRAY- ");
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
}