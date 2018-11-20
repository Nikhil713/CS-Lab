#include<stdio.h>				//Binary Search Iteration

void main()
{
	int arr[20],i,n,x,flag=1,first,last,mid;
        printf(" \nEnter the size : ");
        scanf("%d",&n);
        printf("Please enter the elements in sorted order: ");
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        printf(" \nEnter the element to search: ");
        scanf("%d",&x);
	first=0;
	last=n-1;
	while(first<=last)
	{
		mid=(first+last)/2;
		if(x==arr[mid])
		{
			flag=0;
			break;
		}
		else
			if(x<arr[mid])
				last=mid-1;
			else
				first=mid+1;
	}
	if(flag==1)
		printf("\nElement not found \n");
	else
		printf("Element found at %d \n",mid+1);
}

