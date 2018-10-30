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
void count(struct node *head)
{	int i=0;
	struct node *loc=head;
	while(loc!=NULL)
	{	i++;
		loc=loc->link;
	}
	printf("\n\n:: No. Of Elements = %d.\n",i);
}

main()
{	int ch,n;
	struct node *head=NULL;
	printf("\nHow many Elements Do u want to enter  : ");
	scanf("%d",&n);
	head=create(head,n);
	count(head);
		
}
	
