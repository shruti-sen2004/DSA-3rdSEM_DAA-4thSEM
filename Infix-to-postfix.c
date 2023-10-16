#include<stdio.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/'|| x== '%')
        return 2;
    if(x =='^')
        return 3;
    return 0;
}

int main()
{
    char exp[100],x;
    int i=0;
    printf("ENTER THE INFIX EXPRESSION : ");
    gets(exp);
    printf("\n");
    
    printf("POSTFIX EXPRESSION IS: ");
    while(exp[i]!= '\0')
    {
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')')
        {
            while((x = pop()) != '(')
                printf("%c", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(exp[i]))
                printf("%c",pop());
            push(exp[i]);
        }
        i++;
    }
    
    while(top != -1)
    {
        printf("%c",pop());
    }return 0;
}
