#include<stdio.h>				//Stack implementation using array
int empty();
void push(int [],int);
int pop(int []);
void disp(int []);

int top=-1,up=-1;
int stack[30];
int size=30;

void main()
{
    int n,x,ch;
  do
  {
    printf(" \n\n------------");
    printf(" \n STACK MENU ");
    printf(" \n------------");
    printf(" \n 1.Insert \n 2.Delete \n 3.Display \n 4.EXIT");
    printf(" \n Enter your choice : ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1 :printf(" \n Enter element to insert : ");
                scanf("%d",&x);
                push(stack,x);
                break;

        case 2 :n=pop(stack);
                if(n==-1)
                    printf(" \n Stack Empty");
                else
                    printf(" \n %d is Deleted",n);
                break;

        case 3 :disp(stack);
                break;

        case 4 :break;
        default:printf(" \n Wrong Choice !!!\n");
    }

  }while(ch!=4);
}

void push(int stack[30],int x)
{
    if(top==size-1)
        printf(" \n Stack OverFlow !!!");
    else
    {
        top=top+1;
        stack[top]=x;
    }
}

int empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int pop(int stack[30])
{
    if(empty()==1)
        return -1;
    else
    {
        int data;
        data=stack[top];
        stack[top]=0;
        top=top-1;
        return data;
    }
}

void disp(int stack[30])
{
    if(empty()==1)
        printf(" \n Stack is Empty!!!");
    else
    {
        int val,temp[30],i=0;
        while(top>(-1))
        {
            val=pop(stack);
            temp[i]=val;
            i=i+1;
            printf(" \n | %d |",val);
            printf(" \n |---|");
        }
        i=i-1;
        while(i>(-1))
        {
            push(stack,temp[i]);
            i-=1;
        }
    }
}
