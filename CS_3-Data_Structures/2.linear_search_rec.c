#include<stdio.h>
#define MAX 100

int arr[MAX],value;


void search(int i,int n)
{
	if(i==n)
	{
		if(arr[i]==value)
			printf("The position of element is %d \n",i);
		else
			printf("No such value\n");
	}
	else
	{
		if(arr[i]==value)
			printf("The position of element is %d \n",i+1);
		else
			search(i+1,n);
	}
}

void main()
{
	int n,i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);
	printf("\nEnter the elements :");
	for(i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the value to be searched: ");
	scanf("%d",&value);
	i=0;
	search(i,n);
}
