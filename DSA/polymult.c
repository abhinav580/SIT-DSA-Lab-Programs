#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef,exp;
	struct node *link;
};

struct node *add(struct node *,struct node *,struct node *);
struct node *multiply(struct node *,struct node *, struct node *);
struct node *insert(struct node *,int,int);
void traverse(struct node *);
struct node *create(struct node *,int);

main()
{	struct node *head1=NULL,*head2=NULL,*head3=NULL;
	int ch,n;
	printf("\nPOLYNOMIAL 1::\n");
	printf("\nEnter No. of Terms  : ");
	scanf("%d",&n);
	head1=create(head1,n);
	printf("\nPOLYNOMIAL 2::\n");
        printf("\nEnter No. of Terms  : ");
        scanf("%d",&n);
        head2=create(head2,n);
	
	head3=multiply(head1,head2,head3);

	traverse(head1);
	printf("\n");
	traverse(head2);
	printf("\nAFTER MULTIPLICATION\n");
	traverse(head3);

}

struct node* create(struct node *head, int n)
{       struct node *ptr,*temp;
        int i;
	for(i=1;i<=n;i++)
	{
       		ptr=(struct node *)malloc(sizeof(struct node));
		printf("\n:::Enter coefficient and Expo of %d term :::\n",i);
		printf("\nEnter Coeff : ");
		scanf("%d",&ptr->coef);
		printf("\nEnter Expo  : ");
		scanf("%d",&ptr->exp);
		ptr->link=NULL;

        	if(head==NULL)
               		head=ptr;
        	else
        		temp->link=ptr;
		temp = ptr;
		
	}
	return head;
}
void traverse(struct node *head)
{
        struct node *loc=head;
        while(loc!=NULL)
        {
                printf("%dx^%d + ",loc->coef,loc->exp);
                loc=loc->link;
        }
}
struct node *add(struct node *h1, struct node *h2, struct node *h3)
{	
	struct node *t1=h1,*t2=h2;
 	int s = 0;	
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->exp == t2->exp)
		{
			s = t1->coef + t2->coef;
			if(s != 0)
				h3 = insert(h3,s,t1->exp);
			t1 = t1->link;
			t2 = t2->link;
		}
		else if(t1->exp > t2->exp)
		{
			h3 = insert(h3,t1->coef,t1->exp);
			t1 = t1->link;
		}
		else
		{
			h3 = insert(h3,t2->coef,t2->exp);
			t2 = t2->link;
		}
		
	}
	while(t1 != NULL)
 	{
		h3 = insert(h3,t1->coef,t1->exp);
		t1 = t1->link;
	}
	while(t2 != NULL)
 	{
		h3 = insert(h3,t2->coef,t2->exp);
		t2 = t2->link;
	}

	return h3;
}
struct node *insert(struct node *head,int c,int e)
{
        struct node *t,*ptr;
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->coef = c;
        ptr->exp = e;
        ptr->link = NULL;

        if(head == NULL)
                head = ptr;
        else
        {
                t=head;
                while(t->link != NULL)
                        t = t->link;
                t->link = ptr;
        }
        return(head);
}

struct node *multiply(struct node *h1,struct node *h2,struct node *h4)
{	struct node *t1,*t2,*t3,*ptr,*cur;
	t1=h1;
	t2=h2;
	if(h1==NULL)
		return h2;
	if(h2==NULL)
		return h1;
	while(t1!=NULL)
	{
		while(t2!=NULL)
		{
			ptr=(struct node *)malloc(sizeof(struct node));
			ptr->link=NULL;
			ptr->coef=t1->coef * t2->coef;
			ptr->exp = t1->exp + t2->exp;
			cur=h4;
			//h4=NULL;	
			h4=add(cur,ptr,h4);
			t2=t2->link;
		}
	t2=h2;
	t1=t1->link;
	}
	return h4;
}
