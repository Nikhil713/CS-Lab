#include<stdio.h>

void main()
{
	int num[100],no,i,elem,flag=0;
	printf("Enter the limit of array:");
	scanf("%d",&no);
	printf("\nEnter array elements:");
	for(i=0;i<no;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("\nEnter the element to search for:");
	scanf("%d",&elem);
	for(i=0;i<no;i++)
	{
		if(num[i]==elem)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("\nThe element was found at position %d\n",i+1);
	}
	else
		printf("\nNot found\n");
}
