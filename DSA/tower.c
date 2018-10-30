#include<stdio.h>
#include<stdlib.h>
void tower(int,char,char,char);
main()
{
	int n;
	printf("\nEnter No. of Block  : ");
	scanf("%d",&n);
	tower(n,'S','A','D');
}
void tower(int n,char S,char A,char D)
{
	if(n>=1)
	{
		tower(n-1,S,D,A);
		printf("%c to %c\n",S,D);
		tower(n-1,A,S,D);
	}
}
