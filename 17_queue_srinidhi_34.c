//to implement queue in array 

#include<stdio.h>
int front = -1;
int rear = -1;
int n;

int Qfull(int arr[])
{
if(rear == n-1)
	return 1;
else
	return 0;
}
int Qempty(int arr[])
{
if(front < 0 || rear > front)
	return 1;
else
	return 0;
}
void enqueue(int arr[],int x)
{
if(Qfull(arr))
	printf("\n queue full\n");
else
	{
	if(front ==-1 && rear == -1)
		front++;
	rear++;
	arr[rear] = x;
	}
}
void dequeue(int arr[])
{if(Qempty(arr))
	printf("\n Queue empty");
else
	{
	printf("\n the deleted element is %d",arr[front]);
	front++;
	}
}

int main()
{int choice = -1,x;
printf("\n enter the limit\n");
scanf("%d", &n);
int arr[n];
while(choice != 0)
{
printf("\nMENU \n1)enqueue \n2)dequeue \nenter 0 to exit\n");
printf("enter the choice\n");
scanf("%d", &choice);
switch(choice)
{
	case 1 :printf("\nenter the  element\n"); 
		scanf("%d", &x);
		enqueue(arr,x);
		break;
	case 2 :dequeue(arr);
	
}

}

}
