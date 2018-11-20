#include<stdio.h>				//Binary Search -Recursive

int first,last,mid,arr[20],x;

void main()
{
	int  binary(int[],int);
	int i,n,index;
        printf(" \nEnter the size : ");
        scanf("%d",&n);
        printf("Please enter the elements in sorted order \n");
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        printf(" \nEnter the element to search : ");
        scanf("%d",&x);
	first=0;
	last=n-1;
	index=binary(arr,x);
	if(index<0)
		printf(" \nElement not found \n ");
	else
		printf(" \nElement found at position %d \n ",index+1);
}

int binary(int arr[],int ele)
{

                mid=(first+last)/2;
                if(x==arr[mid])
                	return mid;
         	else
			if(first>last)
				return -1;
	        	else
				if(x<arr[mid])
	                	{
					last=mid-1;
					return binary(arr,x);
				}
                		else
                		{
					first=mid+1;
					return binary(arr,x);
        			}

}



