#include<stdio.h>

void insertion(int arr[],int no)
{
	int i,temp,j,var;
	for(i=1;i<no;i++)
	{
		temp=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1]=arr[j];
			j-=1;
		}
		arr[j+1]=temp;
	}
	for(i=0;i<no;i++)
		printf("%d ",arr[i]);

}


void main()
{
	int arr[100],no,i;
	printf("Enter the limit:");
	scanf("%d",&no);
	printf("Enter the elements: ");
	for(i=0;i<no;i++)
		scanf("%d",&arr[i]);
	insertion(arr,no);
}





