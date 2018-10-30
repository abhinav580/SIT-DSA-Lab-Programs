#include<stdio.h>
#include<stdlib.h>
int binary(int [],int,int);
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
	pos=binary(a,x,n);
	if(pos==-1)
	{
		printf("\nNot Found !!\n");
		exit(0);
	}
	printf("\nPosition is : %d",pos);
}
int binary(int a[],int x,int n)
{
	int i,j;
	int beg=0,end=n-1;
	int mid=n/2;
	while(beg<=end && a[mid]!=x)
	{
		if(x<a[mid])
			end=mid-1;
		else
			beg=mid+1;
		mid=(beg+end)/2;
	}
	if(a[mid]==x)
		return mid+1;
	else 
		return -1;
}				
