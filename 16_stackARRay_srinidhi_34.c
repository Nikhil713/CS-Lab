/*
Write a program to implement stack using array

Srinidhi Krishna
34
*/


#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int TOP = -1;

void push(int ARR[],int element)
{
  if(TOP == MAX-1)
    {
      printf("stack full \n");
    }
  else
    {
      TOP++;
      ARR[TOP] = element;
    }
}

void empty(int ARR[])
{
  if(TOP == -1)
    {
      printf("\n STACK IS EMPTY \n");
    }
  else
    {
      printf("\n stack not empty\n");
    }
}

void peek(int ARR[]) {
  if(TOP == -1)
    {
      printf("\n stack empty\n");
    }
  else
    {
      printf("%d\n",ARR[TOP]);
    }
}

void pop(int ARR[])
{
  if(TOP == -1)
    {
      printf("\n the stack is empty \n");
    }
  else
    {
      TOP--;
    }
}


int main(){
  int ARR[MAX];
  int ch=-1,element;
  while(ch != 0)
    {printf("\nMENU \n1)push \n2)pop \n3)empty \n4)peek \n0 to exit \nenter the choice ");
    scanf("%d",&ch);
    switch (ch) {
      case 1 :printf("\nenter the element to be pushed\n");
              scanf("%d", &element);
              push(ARR,element);
              break;
      case 2 : pop(ARR);
              break;
      case 3 : empty(ARR);
              break;
      case 4 : peek(ARR);
              break;
    }

    }

  return 0;
}
