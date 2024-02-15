#include<stdio.h>
void main(){
    int p,c,i,n;
    printf("ENTER THE NO. OF ELEMENTS: ");
    scanf("%d",&n);
    int a[n+1];

    printf("\nENTER THE ELEMENTS- ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("\nENTER THE POSITION WHERE ELEMENT NEEDS TO BE ADDED- ");
    scanf("%d",&p);

    printf("\nENTER THE NEW ELEMENT- ");
    scanf("%d",&c);

    if(p>n){
        printf("INVALID INPUT!!");
    }

    for(i=n-1; i>=p;i--){
        a[i+1]=a[i];
    }
    a[p]=c;

    printf("\nEDITED ARRAY- ");
    for(i=0;i<=n;i++){
        printf("%d ",a[i]);
    }
}
