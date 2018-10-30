#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int S[MAX];
int top=-1;
int push(int);
int pop();
void display();
main()
{
	int i,val;
	while(1)
	{
		printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\nEnter Your Choice  : ");
		scanf("%d",&i);
		if(i==1)
		{	printf("\nEnter Element to be Inserted : ");
			scanf("%d",&val);
			push(val);
		}
		else if(i==2)
		{
			val=pop();
			if(val!=-1000)
				printf("\n%d popped",val);
		}
		else if(i==3)
			display();
		else
			break;
	}
}
int empty()
{
	if(top==-1)
		return 1;
	else return 0;
}
int full()
{
	if(top==MAX-1)
		return 1;
	else 
		return 0;
}
int push(int val)
{	if(full()==1)
		printf("\nStack Full !!\n");
	else
	{	top++;
		S[top]=val;
	}
	return 0;
}
int pop()
{	
	int item;
	if(empty()==1)
	{	
		printf("\nStack Empty !!\n");
		return -1000;
	}
	item=S[top];
	top--;
	return item;
}
void display()
{	int i;
	if(empty()==1)
	{	
		printf("\nStack Empty !!\n");
		return ;
	}
	for(i=top;i>=0;i--)
		printf("\n%d\n",S[i]);
}
