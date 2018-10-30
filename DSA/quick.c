#include<stdio.h>
#include<stdlib.h>
void quick(int [],int,int);
int part(int [],int,int);
void exchange(int *,int *);
main()
{
	int A[50],B[50],i,p,r,n;
	printf("Enter size : ");
	scanf("%d",&n);	
	printf("\nEnter Elements : \n\n");
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	p=0;
	r=n-1;
	quick(A,p,r);
	printf("\n\nSorted Array \n\n");
	for(i=0;i<n;i++)
        	printf("%d   ",A[i]);
}
void quick(int A[],int p,int r)
{	int q;
	if(p<r)
	{
		q=part(A,p,r);
		quick(A,p,q-1);
		quick(A,q+1,r);
	}
}
int part(int A[],int p,int r)
{	int x,i,j;
	x=A[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(A[j]<=x)
		{
			i++;
			exchange(&A[i],&A[j]);
		}
	}
	exchange(&A[i+1] , &A[r]);
	return (i+1);
}

void exchange(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
