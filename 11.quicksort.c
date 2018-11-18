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
		{
			temp = arr[down];
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
	int arr[100],i,no;
	printf("Enter the limit:");
        scanf("%d",&no);
        printf("Enter the elements: ");
        for(i=0;i<no;i++)
                scanf("%d",&arr[i]);
	quicksort(arr,0,no);
	for(i=0;i<no;i++)
		printf("%d ",arr[i]);
}
