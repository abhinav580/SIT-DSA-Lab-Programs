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
struct node * reverse(struct node *head)
{	struct node *t,*tp,*tn;
	t=head;
	tp=NULL;
	tn=t->link;
	t->link=tp;
	while(tn!=NULL)
	{	tp=t;
		t=tn;
		tn=t->link;
		t->link=tp;
	}
	head=t;
	return head;
}
void print(struct node *head)
{
	struct node *loc=head;
	while(head!=NULL)
	{
		printf("\n%d\n",head->data);
		head=head->link;
	}
}

main()
{	int ch,n;
	struct node *head=NULL;
	printf("\nHow many Elements Do u want to enter  : ");
	scanf("%d",&n);
	head=create(head,n);
	printf("\nOriginal List\n\n");
	print(head);
	printf("\n\nReversed List\n");
	head=reverse(head);
	print(head);
}
	
