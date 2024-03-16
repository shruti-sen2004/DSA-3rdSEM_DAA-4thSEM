#include <stdio.h>

void insert(int a[],int n,int val,int pos){
    int i;
    if(pos>n){
        printf("INSERTION IN NOT POSSIBLE!!");
    }
    for(i=n-1; i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=val;
}

void display(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void delete(int a[],int n, int val,int pos){
    int i;
    if(pos>n){
        printf("INVALID INPUT!!");
    }

    for(i=pos;i<n-1;i++){
        a[i]=a[i+1];
    }
}

int main(){
    int n,i,x,c,val,pos;
    printf("HOW MANY ELEMENTS: ");
    scanf("%d",&n);
    int arr[n];
    printf("ENTER THE ELEMENTS: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("CHOOSE:\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT");
    while(x !=1){
        printf("\nENTER A CHOICE: ");
        scanf("%d",&c);

        switch(c){
            case 1:
                printf("ENTER THE ELEMENT: "); 
                scanf("%d",&val);
                printf("ENTER THE POSITION: "); 
                scanf("%d",&pos);
                insert(arr,n,val,pos);
                n++; break;
            case 2: 
                printf("ENTER THE POSITION: ");
                scanf("%d",&pos);
                delete(arr,n,val,pos);
                n--; break;
            case 3: display(arr,n); break;
            case 4: x=1; printf("Exiting.....");break;
            default: printf("ENTER CORRECT CHOICE!!");
        }
    }
}

