#include<stdio.h>			//Polynomial addition with linked list
#include<stdlib.h>

struct node
{
    int coeff;
    int power;
    struct node *link;
};

struct node *start1=NULL;
struct node *start2=NULL;
struct node *start3=NULL;

void main()
{
    int C,p;
    struct node *a,*b,*c;
    struct node *newnode;
    printf(" \n General Polynomial Expression : a(0)X^(n) + a(1)X^(n-1) + a(2)X^(n-2) + ..... + a(n-1)X + a(n) = 0 \n");
    printf(" \n POLYNOMIAL 1 \n");
    printf(" \n Enter Coefficient and Power of n terms [Coeff power](0 for BOTH to exit)\n");
    do
    {
        scanf("%d %d",&C,&p);
        newnode=malloc(sizeof(struct node));
        newnode->coeff=C;
        newnode->power=p;
        newnode->link=NULL;
        if(start1==NULL)
        {
            start1=newnode;
            a=start1;
        }
        else
        {
            a->link=newnode;
            a=a->link;
        }
    }while(C!=0);


    printf(" \n POLYNOMIAL 2 \n");
    printf(" \n Enter Coefficient and Power of n terms [Coeff power](0 for BOTH to exit)\n");
    do
    {
        scanf("%d %d",&C,&p);
        newnode=malloc(sizeof(struct node));
        newnode->coeff=C;
        newnode->power=p;
        newnode->link=NULL;
        if(start2==NULL)
        {
            start2=newnode;
            b=start2;
        }
        else
        {
            b->link=newnode;
            b=b->link;
        }
    }while(C!=0);

    //ADDITION
    a=start1;
    b=start2;
    while(a->link!=NULL && b->link!=NULL)
    {
        if(a->power==b->power)
        {
            newnode=malloc(sizeof(struct node));
            newnode->coeff=a->coeff+b->coeff;
            newnode->power=a->power;
            newnode->link=NULL;
            if(start3==NULL)
            {
                start3=newnode;
                c=start3;
            }
            else
            {
                c->link=newnode;
                c=c->link;
            }
            a=a->link;
            b=b->link;
        }
        else if(a->power>b->power)
        {
            newnode=malloc(sizeof(struct node));
            newnode->coeff=a->coeff;
            newnode->power=a->power;
            newnode->link=NULL;
            if(start3==NULL)
            {
                start3=newnode;
                c=start3;
            }
            else
            {
                c->link=newnode;
                c=c->link;
            }
            a=a->link;
        }
        else if(a->power<b->power)
        {
            newnode=malloc(sizeof(struct node));
            newnode->coeff=b->coeff;
            newnode->power=b->power;
            newnode->link=NULL;
            if(start3==NULL)
            {
                start3=newnode;
                c=start3;
            }
            else
            {
                c->link=newnode;
                c=c->link;
            }
            b=b->link;
        }
    }

    while(a->link!=NULL)
    {
        newnode=malloc(sizeof(struct node));
        newnode->coeff=a->coeff;
        newnode->power=a->power;
        newnode->link=NULL;
        if(start3==NULL)
        {
            start3=newnode;
            c=start3;
        }
        else
        {
            c->link=newnode;
            c=c->link;
        }
        a=a->link;
    }

    while(b->link!=NULL)
    {
        newnode=malloc(sizeof(struct node));
        newnode->coeff=b->coeff;
        newnode->power=b->power;
        newnode->link=NULL;
        if(start3==NULL)
        {
            start3=newnode;
            c=start3;
        }
        else
        {
            c->link=newnode;
            c=c->link;
        }
        b=b->link;
    }

    //Display
    c=start3;
    if(start3==NULL)
        printf(" \n NO NODES AFTER ADDITION !!!\n");
    else
    {
        printf(" \n After Adding : ");
        while(c!=NULL)
        {
            printf(" %dX^%d +",c->coeff,c->power);
            c=c->link;
        }
        printf("\b = 0\n");
    }
}
