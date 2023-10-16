#include<stdio.h>
int top = -1;
int size= 3;
int stack[3];

void push(int value){
	if(top == size-1){
	printf("STACK OVERFLOW!\n");
	}else{
		stack[++top] = value;
		printf("%d has been pushed into the stack\n",value);
	}
}

void pop(){
	if(top == -1){
		printf("STACK UNDERFLOW!\n");
	}else{
		printf("Poped Element is: %d\n",peek());
		top--;
	}
}

int peek(){
	if(top == -1){
		printf("stack is empty!!\n");
		return -1;
	}else{
		return(stack[top]);
	}
}

void display(){
	int i;
	if(top == -1){
		printf("stack is empty!!\n");
	}
	printf("Current Stack: ");
	for(i = top; i>=0; i--){
		printf("%d ",stack[i]);
	}
	printf("\n");
}

int main(){
	int choice, value, x;
	printf("1. PUSH \n2. POP \n3. DISPLAY \n4. EXIT \n");
	
	
	while(x != 1){
		printf("\nenter your choice: ");
	    scanf("%d", &choice);
	
	switch(choice){
		case 1: printf("enter the value to be pushed: ");
		        scanf("%d", &value);
		        push(value);
		        
		        break;
		        
		case 2: pop();
		        break;
		        
		case 3: display();
				break;
		case 4: x = 1;
				break;
		
		default: printf("INVALID CHOICE!!");		        
	}
}	
	return 0;
}
