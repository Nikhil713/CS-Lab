/*
BUBBLE SORT -

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

*/

#include<stdio.h>
#define MAX 100


void bubble(int arr[],int n)
{
int i,j,temp;
for(i=0;i<n-1;i++)
	{for(j=0;j<n-i-1;j++)
		{if(arr[j]>arr[j+1])
			{temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			}
		}
	}
}

void main()
{int arr[MAX],n,i;
printf("Enter no of elements\n");
scanf("%d",&n);
printf("enter the elements\n");
for (i=0;i<n;i++)
	scanf("%d", &arr[i]);
bubble(arr,n);
for(i=0;i<n;i++)
	printf("%d \n",arr[i]);

}
