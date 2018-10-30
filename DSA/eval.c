#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


#define MAX 20

int top=-1;

char P[MAX],Q[MAX];
int S[MAX];

void push(int);
int pop();
int stackEmpty();
int operation(char);
void evaluate();

main()
{	printf("Enter Postfix expression : ");
	gets(P);
	evaluate();
}

void evaluate()
{
	int len,i,result;
	char x;
	len = strlen(P);
	P[len] = ')';
	i = 0;
	while(P[i] != ')')
	{
		x = P[i];
		if(isdigit(x))
			push(x-48);
		else
		{
			result = operation(x);
			push(result);
		}
		i++;
	}
	printf("\nResult: %d",pop());
}

int operation(char x)
{
	int a,b;
	a=pop();
	b=pop();
	switch(x)
	{
		case '+':
			return(b+a);
		case '-':
			return(b-a);
		case '*':
			return(b*a);

			return(b/a);
		case '^':
			return(pow(b,a));
	}
	return 0;
}

void push(int a)
{	
	top++;
	S[top]=a;
}
int pop()
{	int x;
	x=S[top];
	top--;
	return x;
}
