#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX 20

int top=-1;

char P[MAX],Q[MAX],S[MAX];

void push(char);
char pop();
int priority(char);
void postfix();
int stackEmpty();

main()
{	printf("Enter Infix expression : ");
	gets(Q);
	postfix();
	printf("\nPostfix expression : %s",P);
}

void postfix()
{
	int i,j,k,len;
	char x,y;
	len = strlen(Q);
	Q[len] = ')';
	push('(');

	i=j=0;

	while(stackEmpty() == 0)
	{
		x = Q[i++];
		
		if(isalpha(x))
			P[j++] = x;
		else if(x == '(')
			push(x);
		else if(x == ')')
		{
			while(S[top] != '(')
			{
				y=pop();
				P[j++]=y;
			}
			y=pop();
		}
		else
		{
			k = priority(x);
			while(priority(S[top]) >= k)
			{
				y=pop();
				P[j++]=y;
			}
			push(x);
				
		}	
	}
	P[j] = '\0';
}

void push(char a)
{	
	top++;
	S[top]=a;
}
char pop()
{	char x;
	x=S[top];
	top--;
	return x;
}
int stackEmpty()
{
	if(top == -1)
		return 1;
	return 0;
}
int priority(char y)
{
	if(y=='+' || y=='-')
		return 1;
	else if(y=='*' || y=='/')
		return 2;
	else if(y=='^')
		return 3;
	else
		return 0;
}

