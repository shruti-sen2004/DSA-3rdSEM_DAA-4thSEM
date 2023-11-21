#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void Postorder(struct node* node)
{
	if (node == NULL)
		return;
    
	Postorder(node->left);
	Postorder(node->right);
    printf("%d ", node->data);
}


int main()
{
	struct node* root = newNode(7);
	root->left = newNode(2);
	root->right = newNode(1);
	root->left->left = newNode(0);
	root->left->right = newNode(4);

	// Function call
	printf("Postorder traversal of binary tree is \n");
	Postorder(root);

	getchar();
	return 0;
}
