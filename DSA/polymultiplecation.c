#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial{
	int expo;
	int coeff;
	struct polynomial *next;
}poly;

poly * poly_create(poly *, int);
poly *insert(poly *, int, int);
poly * poly_mul(poly *, poly *, poly *);
void print_poly(poly *);

int main()
{
	int num1, num2, ch;
	poly *h1 = NULL, *h2 = NULL, *h3 = NULL;
	system("clear");
	printf("\nEnter the number of element you want to enter in 1st polynomial: ");
	scanf("%d", &num1);
	h1=poly_create(h1,num1);
	printf("\nEnter the number of element you want to enter in 2nd polynomial: ");
	scanf("%d", &num2);
	h2=poly_create(h2, num2);
	h3=poly_mul(h1, h2, h3);
	printf("\nMultiplication of : ( ");
	print_poly(h1);
	printf(" ) x ( ");
	print_poly(h2);
	printf(" ) = ( ");
	print_poly(h3);
	printf(" )\n");
	return(0);
}

poly * poly_create(poly *h, int n)
{
	poly *q, *temp;
	int c, e, i;
	if(h != NULL)
		return;
	for(i = 1; i<= n; i++)
	{
		
		printf("\nEnter the coefficient for term %d: ", i);
		scanf("%d", &c);
		printf("\nEnter the exponentfor term %d: ", i);
		scanf("%d", &e);
		q = (poly *)malloc(sizeof(poly));
		q->coeff=c;
		q->expo=e;
		q->next = NULL;
		if(h == NULL)
			h = q;
		else
		{
			temp->next = q;	
		}	
		temp = q;
	}
	return h;
}

poly * poly_mul(poly *h1, poly *h2, poly *h3)
{
	if(h1 == NULL || h2 == NULL)
	{
		printf("Multiplication is not possible.");
		return;
	}
	int c, e;
	poly *loc1 = h1, *loc2;
	while(loc1 != NULL)
	{
		loc2 = h2;
		while(loc2 != NULL)
		{
			c = loc1->coeff * loc2->coeff;
			e = loc1->expo + loc2->expo;
			h3 = insert(h3, c, e);
			loc2 = loc2->next;	
		}
		loc1 = loc1->next;
	}	
	
	return h3;
}

poly * insert(poly *head, int c, int e)
{
	poly *loc = head, *locp = NULL, *newnode;
	while(loc != NULL && (loc->expo > e))
	{
		locp = loc;
		loc = loc->next;
	}
	if(loc != NULL && (loc->expo == e))
	{
		loc->coeff = loc->coeff + c;
		return(head);
	}
	newnode = (poly *)malloc(sizeof(poly));
	newnode->coeff = c;
	newnode->expo = e;
	if(head == loc)
	{
		newnode->next = head;
		head = newnode;
	}
	else
	{
		newnode->next = locp->next;
		locp->next = newnode;
	}
	return(head);
}

void print_poly(poly *head)
{
	poly *loc = head;
	while(loc != NULL)
	{
		printf("%dx^%d + ",loc->coeff, loc->expo);
		loc = loc->next;
	}
	printf("\b\b");
	return;
}
