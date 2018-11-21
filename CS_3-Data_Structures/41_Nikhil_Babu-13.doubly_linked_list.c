#include<stdio.h>
#include<stdlib.h>
struct node
{
	int item;
	struct node *link;
};

struct node *start=NULL;
void create(struct node *p);
void display();
void reverse(struct node *p);

int main()
{
	int c;
	char a;
	do
	{
		printf("\nMENU\n");
		printf("\n1.CREATION OF A NODE");
		printf("\n2.DISPLAY");
		printf("\n3.REVERSAL OF THE LIST");
		printf("ENTER YOUR CHOICE (1/2/3):");
		scanf("%d",&c);
		if(c==1)
		{
			create(start);
			printf("\nITEM INSERTED INTO THE LIST");
		}
		if(c==2)
		{
			printf("\nTHE LINK LIST IS:\n");
			display();
		}
		if(c==3)
		{
			reverse(start);
			printf("\n-----REVERSED LIST -----\n");
			display();
		}
		printf("\nDO YOU WANT TO CONTINUE:");
		scanf("%s",&a);
	}while(a=='y');
}

void create(struct node *p)
{
	int d;struct node *t;
	struct node *newnode;
	t=p;
	printf("ENTER THE ITEM :");
	scanf("%d",&d);
	newnode=malloc(sizeof(struct node));
	newnode->item=d;
	newnode->link=NULL;
	if(p==NULL)
		start=newnode;
	else
	{
		while(t->link!=NULL)
			t=t->link;
		t->link=newnode;
	}
}

void display()
{
	struct node *p;
	p=start;
	while(p!=NULL)
	{
		printf("%d\n",p->item);
		p=p->link;
	}
}

void reverse(struct node *p)
{
	struct node * temp,*prev,*t;
	t=p;
	prev=p;
	temp=p;
	int c=1;
	while(temp->link!=NULL)
	{
		while(t->link!=NULL)
		{
			prev=t;
			t=t->link;
		}
		t->link=prev;
		prev->link=NULL;
		if(c==1)
		{
			t=p;
			prev=p;
		}
	}
start=t;
c++;
}
