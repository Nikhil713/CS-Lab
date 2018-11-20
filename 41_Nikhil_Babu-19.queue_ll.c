#include<stdio.h>			//Implementation of queue using linked list
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front=NULL;
struct node *rear=NULL;

void main()
{
    int x,ch;
    struct node *p,*newnode;
  do
  {
    printf(" \n\n------------");
    printf(" \n QUEUE MENU ");
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
                if(front==NULL)
                {
                    front=newnode;
                    rear=front;
                }
                else
                {
                    rear->link=newnode;
                    rear=newnode;
                }
                break;
        case 2 :if(front==NULL)
                    printf(" \n No Nodes to Delete...\n");
                else if(front==rear)
                {
                    printf(" \n %d is Deleted \n",front->data);
                    front=NULL;
                    rear=NULL;
                }
                else
                {
                    printf(" \n %d is Deleted \n",front->data);
                    front=front->link;
                }
                break;
        case 3 :if(front==NULL)
                    printf(" \n No Nodes ! \n ");
                else
                {
                    p=front;
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
