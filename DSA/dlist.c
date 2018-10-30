#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next,*prev;
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
		ptr->next=NULL;
		if(head==NULL)
		{	head=ptr;
			ptr->prev=NULL;
		}
		else
		{	temp->next=ptr;
			ptr->prev=temp;
		}
		temp=ptr;
	}
	return head;
}
void print(struct node *head)
{
	struct node *loc=head;
	while(loc!=NULL)
	{
		printf("\n%d ",loc->data);
		loc=loc->next;
	}
}

struct node * insertb(struct node *head)
{       struct node *t,*temp;	
        t=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter value to be inserted  : ");
        scanf("%d",&t->data);
	t->prev=NULL;
	head->prev=t;
	t->next=head;
        head=t;
        return head;
}
void insertl(struct node *head)
{       struct node *temp,*loc=head;
        printf("\nEnter value to be inserted  : ");
        temp=(struct node *)malloc(sizeof(struct node));	
        scanf("%d",&temp->data);
        while(loc->next!=NULL)
                loc=loc->next;
        temp->next=NULL;
	temp->prev=loc;
	loc->next=temp;
}

struct node * deletel(struct node *head)
{       struct node *t,*x;
        t=head;
	while(t->next!=NULL)
		t=t->next;
	x=t->prev;
	x->next=NULL;
	free(t);
	return head;
}

struct node * deletef(struct node *head)
{       struct node *t;
        t=head;
        head=head->next;
	free(t);
	return head;
}
void revtraverse(struct node *head)
{
	struct node *temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	while(temp->prev!=NULL)
	{
		printf("%d -> ",temp->data);
		temp=temp->prev;
	}
	printf("%d",temp->data);
}
main()
{	int ch,n;
	struct node *head=NULL;
	while(1)
	{
		printf("\n1.Create\n2.Insertbeg\n3.InsertLast\n4.Deletebeg\n5.Deletelast\n6.Print\n7.Reverse Print\n8.Exit\nEnter Your choice  : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:		
				printf("\nHow many Elements Do u want to enter  : ");
				scanf("%d",&n);
				head=create(head,n);
				break;
			case 2:	head=insertb(head);	print(head);
				break;
			case 3:	insertl(head);		print(head);
				break;
			case 4:	head=deletef(head);	print(head);
				break;
			case 5:	deletel(head);		print(head);
				break;
			case 6:	print(head);
				break;
			case 7:	revtraverse(head);
				break;
			case 8:	exit(0);

		}
	}
}	


	
