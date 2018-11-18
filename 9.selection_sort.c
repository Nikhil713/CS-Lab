/*
SELECTION SORT-
Time Complexity: O(n2) as there are two nested loops.


 */


#include<stdio.h>

void selectionsort(int arr[],int n)
{
int i,j,min,temp;
for(i=0;i<n;i++)
	{min=i;
	for(j=i+1;j<n;j++)
		{if(arr[j]<arr[min])
			min=j;
		}
	temp=arr[min];
	arr[min]=arr[i];
	arr[i]=temp;
	}

}

void main()
{
int arr[]={64,25,12,22,11};
int n=sizeof(arr)/sizeof(int);
selectionsort(arr,n);
printf("The sorted array\n");
for(int i=0;i<n;i++)
	{printf("%d \n",arr[i]);
	}

}
