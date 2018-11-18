/* Insertion sort 
   Time complexity-O(n^2)
   

*/


#include<stdio.h>
#define MAX 10

void insertion(int arr[])
{
int i,temp,j,var;
for(i=1;i<MAX;i++)	
	{temp=arr[i];
	j=i-1;
	while(j>=0 && arr[j]>temp)
		{arr[j+1]=arr[j];
		j-=1;
		}
	arr[j+1]=temp;
	}

for(i=0;i<MAX;i++)
	printf("%d \t",arr[i]);

}

		
	

int main()
{
int arr[MAX],i;
printf("Enter the elements\n ");
for(i=0;i<MAX;i++)
	scanf("%d",&arr[i]);
insertion(arr);
return 0;
}





