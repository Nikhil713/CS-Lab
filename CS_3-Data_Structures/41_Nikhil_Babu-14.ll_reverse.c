#include<stdio.h>
#include<stdlib.h>			//Reverse a singly linked list


struct node
{
	int data;
    	struct node *link;
};

struct node *start=NULL;


void main()
{
	struct node *p,*newnode,*q,*t,*start1,*P;
    	int i,x;
    	printf("\n Input elements of linked list(0 to exit) :\n");
    	while(x!=0)
    	{
        	scanf("%d",&x);
        	newnode=malloc(sizeof(struct node));
        	newnode->data=x;
        	newnode->link=NULL;

	        if(start==NULL)
        	{
        		start=newnode;
            		p=start;
        	}
        	else
        	{
            		p->link=newnode;
            		p=p->link;
        	}
    	}

    	printf("\n");
    	p=start;
    	while(p->link!=NULL)
    	{
        	printf("  %d  |->",p->data);
        	p=p->link;
    	}

 	int flag=0;
        while(start->link!=NULL)
    	{
        	p=start;
        	while(p->link!=NULL)
        	{
        		t=p;
            		p=p->link;
        	}
        	if(flag==0)
        	{
            		flag=1;
            		t->link=NULL;
            		p->link=start;
            		start1=p;
            		q=p;
               	}
        	else
        	{
            		q->link=NULL;
            		t->link=NULL;
            		p->link=start;
            		q->link=p;
            		q=q->link;
        	}


    	}
    	printf("\n\n");
    	P=start1->link;
    	while(P!=NULL)
    	{
        	printf("  %d  |->",P->data);
        	P=P->link;
    	}
    	printf("\n");
}
