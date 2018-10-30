#include<stdio.h>
#include<stdlib.h>
int inter(int [],int,int,int);
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
	pos=inter(a,0,n-1,x);
	if(pos==-1)
	{
		printf("\nNot Found !!\n");
		exit(0);
	}
	printf("\nPosition is : %d",pos);
}
int inter(int a[],int low,int high,int x)
{
	int i,j;

	int mid;
	while(low<=high)
	{
		mid=low + (high-low)*((x-a[low])/(a[high]-a[low]));
		if(x==a[mid])
			return mid+1;
		if(x<a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
		
}				
