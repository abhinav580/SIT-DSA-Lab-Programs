#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node *front=NULL,*rear=NULL;

void enqueue();
void dequeue();
void display();
main()
{
	int ch;
	while(1)
	{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter Your Choice  : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	enqueue();
				display();
				break;
			case 2:	dequeue();
				display();
				break;
			case 3:	display();
				break;
			case 4:	exit(0);
				break;
			default: printf("\nWrong Choice !!");
				break;
		}
	}
}
void enqueue()
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); 
	printf("\nEnter Value to be inserted  : ");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(rear==NULL)
	{	front = temp;
		rear=temp;
	}
	else
	{	rear->next=temp;
		rear=temp;
	}
}
void display()
{
	struct node *temp=front;
	printf("\n\n\n");
	while(temp != NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void dequeue()
{	struct node *temp;
	if(front==NULL)
		printf("\nEmpty !!!\n");
	else
	{
		temp=front;
		front=front->next;
		free(temp);
	}
	if(rear==temp)
		rear=NULL;
}

