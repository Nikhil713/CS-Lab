/*
to implement stack from both sides of the array
*/

#include<stdio.h>
int n,TOP1,TOP2;

void PUSH1(int arr[],int x)
{
if(TOP1+1 == TOP2)
	{printf("\n stack full");
	}
else
	{TOP1++;
	arr[TOP1] = x;
	}
	
}
void PUSH2(int arr[],int x)
{
if(TOP1 == TOP2-1)
	{printf("\n stack full");
	}
else
	{TOP2--;
	arr[TOP2] = x;
	}

}

void POP1(int arr[])
{
if(TOP1 == -1)
	{printf("stack empty");
	}
else 
	{printf("element poped is %d",arr[TOP1]);
	TOP1--;
	}
}


void POP2(int arr[])
{
if(TOP2 == n)
	{printf("stack empty");
	}
else 
	{printf("element poped is %d",arr[TOP2]);
	TOP2++;
	}
}

void PEEK1(int arr[])
{
if(TOP1 == -1)
	printf("the stack is empty");
else
	{printf("top element is %d",arr[TOP1]);
	}
}
void PEEK2(int arr[])
{
if(TOP2 == n)
	printf("the stack is empty");
else
	{printf("top element is %d",arr[TOP2]);
	}
}
	
int main()
{
int choice = -1,x;
printf("\n enter the limit of array\n");
scanf("%d", &n);
int arr[n];
TOP1 = -1;
TOP2 = n;
printf("\n\tMENU\n\t1)PUSH Stack1\n\t2)PUSH Stack2\n\t3)POP Stack1\n\t4)POP stack2\n\t5)Peek stack1\n\t6)peeek stack2\n\tenter 0 to exit\n");
while(choice != 0)
{
	printf("\n enter the choice\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1 : printf("\nenter element to be pushed\n");
			scanf("%d", &x);
			PUSH1(arr,x);
			break;
		case 2 : printf("\nenter element to be pushed\n");
			scanf("%d", &x);
			PUSH2(arr,x);
			break;
		case 3 : POP1(arr);
			break;
		case 4 :POP2(arr);
			break;
		case 5 :PEEK1(arr);
			break;
		case 6 :PEEK2(arr);
			break;
	}
}

}
 
