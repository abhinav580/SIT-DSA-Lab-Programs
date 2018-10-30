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
	int swap=1,j,i,tmp;
	for(i=0;i<n,swap==1;i++)
	{	swap=0;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{	tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
				swap=1;
			}
		}
	}
}
	
