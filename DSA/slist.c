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
//	printf("\n1.CREATE\n2.DISPLAY\n3.EXIT");
//	scanf("%d",&ch);
//	if(ch==1)
	head=create(head,n);
	print(head);
	
}
	
