/*
Program to reverse a singly linked list

Name : Srinidhi Krishna
ROLLNO: 34
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
  int DATA;
  struct node *link;
}*START=NULL;

int DATA;

void reverse() {
  /* code */
  struct node *cur,*prev,*next;
  prev = NULL;
  cur = START;
  next = NULL;
  while(cur != NULL)
    {   next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
  START = prev;
}

void display()
{
  struct node *p;
  p = START;
  printf("DATA \n");
  while(p != NULL)
	 {
	    DATA = p->DATA;
	     printf("%d -> ",DATA);
	      p = p->link;
	 }
   printf("NULL");
 }


int main()
{
  int i,n;
  struct node *p;
  printf("enter the limit \n");
  scanf("%d", &n);
  for(i=1;i<=n;i++)
  	{ if(START == NULL)
      {struct node *newnode;
      newnode = malloc(sizeof(struct node));
      printf("\n enter the DATA\n");
      scanf("%d",&DATA);
      newnode->DATA = DATA;
      newnode->link = NULL;
      START = newnode;
      p = newnode;
    }
  else
      {struct node *newnode;
        newnode=malloc(sizeof(struct node));
        printf("\n enter the DATA\n");
        scanf("%d",&DATA);
        newnode->DATA = DATA;
        newnode->link = NULL;
        p->link = newnode;
        p = newnode;
      }

  	}
printf("\nThe linked list before reversing\n");
display();
reverse();
printf("\nThe linked list after reversing\n");
display();
}
