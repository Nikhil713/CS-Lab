#include<stdio.h>

void selectionsort(int arr[],int n)
{
	int i,j,min,temp;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			min=j;
		}
	temp=arr[min];
	arr[min]=arr[i];
	arr[i]=temp;
	}

}

void main()
{
	int arr[100],no,i;
	printf("Enter the limit:");
	scanf("%d",&no);
	printf("Enter the array elements:");
	for(i=0;i<no;i++)
		scanf("%d",&arr[i]);
	selectionsort(arr,no);
	printf("The sorted array\n");
	for(i=0;i<no;i++)
	{
		printf("%d ",arr[i]);
	}

}
