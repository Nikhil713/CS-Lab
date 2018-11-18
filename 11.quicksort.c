/*
Quicksort algorithm

Average case--nlog(n)

*/

#include<stdio.h>

int partition(int arr[],int lb,int ub)
{
int pivot = arr[lb];
int down = lb;
int up = ub;
int temp;
while(down < up)
	{
	while(arr[down] <= pivot && down<ub)
		down++;
	while(arr[up] > pivot)
		up--;
	if(up > down)
		{temp = arr[down];
		arr[down] = arr[up];
		arr[up] = temp;
		}
	}
arr[lb] = arr[up];
arr[up] = pivot;
return up;
}

void quicksort(int arr[],int lb,int ub)
{
int j;
if(lb >= ub)
	return;
j=partition(arr,lb,ub);
quicksort(arr,lb,j-1);
quicksort(arr,j+1,ub);
}	




void main()
{
int arr[]={64,25,12,22,11};
int n=sizeof(arr)/sizeof(int);
quicksort(arr,0,n);
for(int i=0;i<n;i++)
	{printf("%d \n",arr[i]);
	}

}
