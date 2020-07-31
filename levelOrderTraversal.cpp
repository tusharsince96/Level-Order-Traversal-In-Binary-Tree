//level order traversal in a binary tree
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void inorder(struct node *root);
void level_trav(struct node *root);
void insert_queue(struct node *item);
int queue_empty();
struct node *del_queue();
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *newnode(int data)
{
	struct node *node=(struct node *)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void inorder(struct node *root)
{
	if(root==NULL)
	return;
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
main()
{
	struct node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	printf("In Order Traversal --> ");
	inorder(root);
	printf("\nLevel Order Traversal --> ");
	level_trav(root);
	
}

//Inorder Traaversal using Queue
struct node *queue[MAX];
int front=-1,rear=-1;
void insert_queue(struct node *item)
{
	if(rear==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)
	front=0;
	rear=rear+1;
	queue[rear]=item;
}

struct node *del_queue()
{
	struct node *item;
	if(front==-1 || front==rear+1)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	item=queue[front];
	front=front+1;
	return item;
	 
}

int queue_empty()
{
	if(front==-1 || front==rear+1)
	{
		return 1;
	}
	else 
	return 0;
}

void level_trav(struct node *root)
{
	struct node *ptr=root;
	if(ptr==NULL)
	{
		printf("Tree is Empty \n");
		return;
	}
	insert_queue(ptr);
	while(!queue_empty())
	{
		ptr=del_queue();
		printf("%d ",ptr->data);
		if(ptr->left!=NULL)
		insert_queue(ptr->left);
		if(ptr->right!=NULL)
		insert_queue(ptr->right);
		
	}
	printf("\n");
}

