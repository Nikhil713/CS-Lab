#include<stdio.h>			//Implemenatation of circular queue using array

void enq(int[],int *,int *,int);
void deq(int[],int *,int *);
void disp(int[],int *,int *);

int size=10;
int cq[10];
int front=-1,rear=-1;

void main()
{
    int x,n,ch;

    do
    {
         printf(" \n\n---------------");
         printf(" \n QUEUE MENU :- ");
         printf(" \n---------------");
         printf(" \n 1.Insert \n 2.Delete \n 3.Display \n 4.EXIT \n Enter your choice : ");
         scanf("%d",&ch);

         switch(ch)
         {
            case 1 :printf(" \n Enter Element to insert : ");
                    scanf("%d",&x);
                    enq(cq,&front,&rear,x);
                    break;
            case 2 :deq(cq,&front,&rear);
                    break;
            case 3 :printf(" \n Circular Queue is :- \n ");
                    disp(cq,&front,&rear);
                    break;
            case 4 :break;
            default:printf(" \n Wrong Choice !!!\n ");
         }
    }while(ch!=4);

}

void enq(int cq[],int *front,int *rear,int x)
{
    if( (*front==0 && *rear==(size-1)) || (*front==*rear+1) )
        printf(" \n OVERFLOW !!! \n ");
    else
    {
        if(*front==-1)
        {
            *front=0;
            *rear=0;
            cq[*rear]=x;
            //printf(" \n insert at empty");
        }
        else if(*rear==size-1)
        {
            *rear=0;
            cq[*rear]=x;
        }
        else
        {
            *rear+=1;
            cq[*rear]=x;
        }


    }
}

void deq(int cq[],int *front,int *rear)
{
    if(*front==-1)
        printf(" \n UNDERFLOW !!! \n ");
    else
    {
        int data;
        data=cq[*front];
        if(*front==*rear)
        {
            *front=-1;
            *rear=-1;
        }
        else if(*front==size-1)
            *front=0;
        else
            *front+=1;

        printf(" \n %d is Deleted \n ",data);
    }
}

void disp(int cq[],int *front,int *rear)
{
    if(*front==-1)
        printf(" \n No Elements to display !!! \n ");
    else
    {
        int i;
        printf(" \n ");
        if(*front==*rear)
        {
            printf(" (f=%d r=%d)   %d -> \n ",*front,*rear,cq[*front]);

        }
        else if(*front<*rear)
        {
            i=*front;
            printf(" (f=%d r=%d)   ",*front,*rear);
            while(i<=*rear)
            {
                printf(" %d -> ",cq[i]);
                i+=1;
            }
        }
        else
        {
            i=*front;
            printf(" (f=%d r=%d)   ",*front,*rear);
            while(i<size)
            {
                printf("%d -> ",cq[i]);
                i+=1;
            }
            printf(">>>>> ");
            i=0;
            while(i<*rear+1)
            {
                printf("%d -> ",cq[i]);
                i+=1;
            }
        }
    }
}
