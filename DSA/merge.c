#include<stdio.h>
#include<stdlib.h>
void sort(int [],int,int);
void merge(int [],int,int,int);
main()
{	int a[100],i,l,u;
	int n;
	printf("\nEnter Size  : ");
	scanf("%d",&n);
	printf("\n::::Enter Elements:::\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement %d : ",i+1);
		scanf("%d",&a[i]);
	}
	sort(a,0,n-1);
	for(i=0;i<n;i++)
                printf("\nElement %d : %d ",i+1,a[i]);
}
void sort(int a[],int p,int r)
{	
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		sort(a,p,q);
		sort(a,q+1,r);
		merge(a,p,q+1,r);
	}
}
void merge(int a[],int ls,int rs,int re)
{
	int l,k,i,j,le,temp[100];
	i=ls;
	j=rs;
	le=rs-1;
	k=0;
	while(i<=le && j<=re)
	{
		if(a[i]<=a[j])
		{	temp[k++]=a[i];
			i++;
		}
		else
		{
			temp[k++]=a[j];
			j++;
		}
	}
	while(i<=le)
	{
		temp[k++]=a[i];
		i++;
	}
	while(j<=re)
	{
		temp[k++]=a[j];
		j++;
	}
	for(l=0;l<k;l++)
		a[ls+l]=temp[l];
}
	
