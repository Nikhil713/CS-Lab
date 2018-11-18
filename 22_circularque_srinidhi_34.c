//To implement cicular queue

#include<stdio.h>
int FRONT = -1;
int REAR = -1;
int n;

int CQempty(int arr[])
{
if(FRONT == -1)
	return 1;
else
	return 0;
}
int CQfull(int arr[])
{
if((FRONT == 0 && REAR == n-1) || FRONT == REAR+1)
	return 1;
else
	return 0;
}

void CQinsert(int arr[],int x)
{
if(CQfull(arr))
	printf("\n Overflow");
else
	{
	if(FRONT == -1)
		FRONT++;
	REAR = (REAR+1)%n;
	arr[REAR] = x;
	}
}

void CQdelete(int arr[])
{
if(CQempty(arr))
	printf("\n Underflow\n");
else
	{
	printf("\n the deleted element is %d",arr[FRONT]);
	if(FRONT == REAR)
		{FRONT = -1;
		REAR = -1;
		}
	else
		{FRONT = (FRONT+1)%n;
		}
	}
}
		

int main()
{
int choice = -1,x;
printf("\nenter the limit\n");
scanf("%d", &n);
int arr[n];
printf("\nMENU \n1)insert \n2)delete \nenter 0 to exit\n");
while(choice != 0)
{
	printf("\n enter the choice \n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1 : printf("\nenter the element\n");
			scanf("%d", &x);
			CQinsert(arr,x);			
			break;
		case 2 :  CQdelete(arr);
			break;
	}
}
}
