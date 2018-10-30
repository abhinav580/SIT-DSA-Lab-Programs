#include<stdio.h>
#include<stdlib.h>
int fibo(int);
int a=0;
int b=1;
main()
{
	int n,i;
	printf("Enter no. of terms :: ");
	scanf("%d",&n);
//	printf("\t%d\t%d",a,b);
	for(i=0;i<n;i++)
		printf("\t%d",fibo(i));
}
int fibo(int n)
{	if(n==0 || n==1)
		return;	
	else 
		return (fibo(n-1) + fibo(n-2));
}
