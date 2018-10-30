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
{	int k;
	int j,x,i,tmp;
	for(i=1;i<n;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>a[j+1])
			{	tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
				
	}
}
	
