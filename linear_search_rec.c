#include<stdio.h>
#define MAX 100

int arr[MAX],value;


void search(int i,int n)
{
if(i==n)
	{if(arr[i]==value)
		printf("The position of element is %d \n",i);
	else
		printf("No such value\n");
	}
else
	{if(arr[i]==value)
		printf("The position of element is %d \n",i);
	else
		search(i+1,n);
	}
}

void main()
{int n,i;
printf("enter the number of elements\n");
scanf("%d", &n);
printf("\n enter the elements\n");
for(i=0;i<n;i++)
{
scanf("%d", &arr[i]);
}
printf("enter the value to be searched\n");
scanf("%d",&value);

i=0;
search(i,n);

}
