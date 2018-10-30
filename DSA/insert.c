#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *link;
};
struct node* create(struct node *head, int n)
{	struct node *ptr,*temp;
	int i,val;
	if(head!=NULL)
	{	printf("\nAlready Exist \n");
		return head;
	}
	for(i=1;i<=n;i++)
	{	printf("\nEnter Value  : ");
		scanf("%d",&val);
	ptr=(struct node *)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->link=NULL;
	if(head==NULL)
		head=ptr;
	else
		temp->link=ptr;
	temp=ptr;
	}
return head;
}
struct node * insert(struct node *head)
{	int x;
	struct node *t;
	printf("\nEnter value to be inserted  : ");
	scanf("%d",&x);
	t=(struct node *)malloc(sizeof(struct node));
	t->data=x;
	t->link=head;
	head=t;
return head;
}
void print(struct node *head)
{
	struct node *loc=head;
	while(head!=NULL)
	{
		printf("\n%d",head->data);
		head=head->link;
	}
}

main()
{	int ch,n;
	struct node *head=NULL;
	printf("\nHow many Elements Do u want to enter  : ");
	scanf("%d",&n);
	head=create(head,n);
	while(1)
	{	printf("\n1.INSERT\n2.PRINT\n3.EXIT\nEnter choice  : ");
		scanf("%d",&ch);
		if(ch==1)
			head=insert(head);
		else if(ch==2)
			print(head);
		else 
			break;
	}
}
	
