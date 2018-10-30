#include<stdio.h>
#include<stdlib.h>
void sort(int [],int);
main()
{	int a[100],n,i;
	printf("\nEnter Size  : ");
	scanf("%d",&n);
	printf("\n::::Enter Elements:::\n");
	for(i=0;i<n;i++)
	{
		printf("\nElement %d : ",i+1);
		scanf("%d",&a[i]);
	}

	sort(a,n);

	for(i=0;i<n;i++)
                printf("\nElement %d : %d ",i+1,a[i]);
}
void sort(int a[],int n)
{
	int j,i,tmp,x,k;
	for(i=0;i<n-1;i++)
	{	
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
	
