#include<stdio.h>
#include<conio.h>
#include<process.h>
 
struct node
{
    int data;
    struct node *next;
}*start=NULL,*q,*t;
 
int main()
{
    int ch;
    void insert_end();
    void display();
    void delete_beg();
 
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n\n");
        printf("Enter your choice(1-4):");
        scanf("%d",&ch);
 
        switch(ch)
        {
            case 1:insert_end();break;
            case 2: delete_beg();break;
            case 3: display();break;
            case 4: exit(0);
                    default: printf("Wrong Choice!!");
        }
    }
    return 0;
}
 
void insert_end()
{
    int num;
    t=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&num);
    t->data=num;
    t->next=NULL;
 
    if(start==NULL)        //If list is empty
    {
        start=t;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
        q=q->next;
        q->next=t;
    }
}
 
void display()
{
    if(start==NULL)
    {
        printf("List is empty!!");
    }
    else
    {
        q=start;
        printf("The linked list is:\n");
        while(q!=NULL)
        {
            printf("%d->",q->data);
            q=q->next;
        }
    }
}
 
void delete_beg()
{
    if(start==NULL)
    {
        printf("The list is empty!!");
    }
    else
    {
        q=start;
        start=start->next;
        printf("Deleted element is %d",q->data);
        free(q);
    }
}
 
 
