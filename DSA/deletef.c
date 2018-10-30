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
struct node * delete(struct node *head)
{	struct node *t;
	t=head;
	t=t->link;
	free(head);
	return t;
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
	{	printf("\n1.DELETE\n2.PRINT\n3.EXIT\nEnter choice  : ");
		scanf("%d",&ch);
		if(ch==1)
			head=delete(head);
		else if(ch==2)
			print(head);
		else 
			break;
	}
}
	
