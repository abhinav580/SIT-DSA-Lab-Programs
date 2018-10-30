#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *top=NULL;
void push();
void pop();
void display();
main()
{
	int i;
while(1)
{	
	printf("\n1.PUSH\n2.POP\n3.DISPLAY\n3.EXIT\nEnter Choice  : ");
	scanf("%d",&i);
	switch(i)
	{
		case 1:	push();
			break;
		case 2:	pop();
			break;
		case 3:	display();
			break;
		default: exit(0);
	}
}
}

void push()
{	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));	
	printf("\nEnter Element To Be Inserted  : ");
	scanf("%d",&temp->info);
	temp->link=top;
	top=temp;
}
void pop()
{
	struct node *temp;
	temp=top;
	if(top==NULL)
	{	printf("\nStack Empty !!\n");
		exit(0);
	}
	top=top->link;
	printf("\n %d Deleted !! \n",temp->info);
	free(temp);
}
void display()
{
	struct node *temp;
	temp=top;
	while(temp!=NULL)
	{
		printf("\n%d",temp->info);
		temp=temp->link;
	}
}

	
	
