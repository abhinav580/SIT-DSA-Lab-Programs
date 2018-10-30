#include<stdio.h>
#include<stdlib.h>
int linear(int [],int,int);
main()
{
	int a[100],i,x,n,pos;	
	printf("\nEnter Size :: ");
	scanf("%d",&n);
	printf("\nEnter Elements  \n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nEnter Element to be searched \n");
	scanf("%d",&x);	
	pos=linear(a,x,n);
	if(pos==-1)
	{
		printf("\nNot Found !!\n");
		exit(0);
	}
	printf("\nPosition is : %d",pos);
}
int linear(int a[],int x,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(x==a[i])
			return i+1;
	}
return -1;
}
				
