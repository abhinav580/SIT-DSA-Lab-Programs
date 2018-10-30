#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int Q[MAX];
int front=-1,rear=-1;
void enqueue();
void dequeue();
int full();
int empty();
void display();
main()
{	
	int ch;
	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.Print\n4.Exit\nEnter Your Choice :: ");
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
			case 4: exit(0);
				break;
		}
	}
}

int full()
{	if((front==0 && rear==MAX-1) || (front==rear+1))
		return -1;
	else
		return 0;
}
int empty()
{	if(front==-1 && rear==-1)
		return -1;
	else 
		return 0;
}
void enqueue()
{	if(full()==-1)
		return;
	if(empty())
	{
		front =0;
		rear=0;
	}
	else if(rear==MAX-1)
		rear=0;
	else 
		rear++;
	
	printf("Enter The value to be inserted  : ");
	scanf("%d",&Q[rear]);
}
void display()
{	int i;
	if(front>rear)
	{
		for(i=front; i<=rear; i++)
			printf("%d->",Q[i]);
		for(i=0;i<=rear; i++)
			printf("%d->",Q[i]);
	}
	else
	{
		for(i=front;i<=rear;i++)
			printf("%d->",Q[i]);

	}
}
void dequeue()
{	int i;
	if(empty())
	{	printf("\nUnderflow !! \n");
		return;
	}
	if(front==rear)
	{	front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
		front=0;
	else 
		front++;	
}	
