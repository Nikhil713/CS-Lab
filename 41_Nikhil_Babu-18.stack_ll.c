#include<stdio.h>					//Implementation of stack using linked list
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *top=NULL;

void main()
{
    int x,ch;
    struct node *p,*newnode;
  do
  {
    printf(" \n\n------------");
    printf(" \n STACK MENU ");
    printf(" \n------------");
    printf(" \n 1.Insert \n 2.Delete \n 3.Display \n 4.EXIT \n Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 :
                printf(" \n Enter value : ");
                scanf("%d",&x);
                newnode=malloc(sizeof(struct node));
                newnode->data=x;
                newnode->link=NULL;
                if(top==NULL)
                {
                    top=newnode;
                }
                else
                {
                    newnode->link=top;
                    top=newnode;
                }
                break;
        case 2 :if(top==NULL)
                    printf(" \n No Nodes to Delete...\n");
                else
                {
                    printf(" \n %d is Deleted \n",top->data);
                    top=top->link;
                }
                break;
        case 3 :if(top==NULL)
                    printf(" \n No Nodes ! \n ");
                else
                {
                    p=top;
                    printf("\n");
                    while(p!=NULL)
                    {
                        printf(" %d  |>> ",p->data);
                        p=p->link;
                    }
                }
        case 4 :break;
        default:printf(" \n Wrong Choice !!! \n ");
    }


  }while(ch!=4);
}
