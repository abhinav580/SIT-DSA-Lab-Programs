#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
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
	//	ptr->link=NULL;
		if(head==NULL)
		{	temp=ptr;
			head=ptr;
			ptr->next=head;
		}
		else
		{
			temp->next=ptr;
			ptr->next=head;
		}	
	
		temp=ptr;
	}
	return head;
}
void print(struct node *head)
{
	struct node *loc=head;
	do
	{
		printf("\n%d->",loc->data);
		loc=loc->next;
	}while(loc!=head);

}

struct node * insertb(struct node *head)
{       int x;
        struct node *t,*temp;
        printf("\nEnter value to be inserted  : ");
        scanf("%d",&x);
        t=(struct node *)malloc(sizeof(struct node));
        t->data=x;
        temp=head;
        while(temp->next!=head)
		temp=temp->next;
	temp->next=t;
	t->next=head;
	head=t;
return head;
}
void insertl(struct node *head)
{       int x;
        struct node *temp,*ptr;
        printf("\nEnter value to be inserted  : ");
        scanf("%d",&x);
        ptr=(struct node *)malloc(sizeof(struct node));
        ptr->data=x;
	temp=head;
        while(temp->next!=head)
                temp=temp->next;
        temp->next=ptr;
	ptr->next=head;
}

struct node * deletel(struct node *head)
{       struct node *t,*x;
        t=head;
	while(t->next!=head)
	{
		x=t;
		t=t->next;
	}
	x->next=t->next;
	free(t);
	return head;
}
struct node * deletef(struct node *head)
{       struct node *t;
        t=head;
        while(t->next!=head)
              t=t->next;
        t->next=head->next;
        free(head);
	head=t->next;
	return head;
}
main()
{	int ch,n;
	struct node *head=NULL;
	while(1)
	{
		printf("\n1.Create\n2.Insertbeg\n3.InsertLast\n4.Deletebeg\n5.Deletelast\n6.Print\n7.Exit");
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
			case 7:	exit(0);

		}
	}
}	


	
