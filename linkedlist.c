/*
Linked list to store the students roll no,name,marks

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int rollno,marks;
	char name[10];
	struct node *link;
	}*START=NULL;

int ROLLNO,MARKS;
char NAME[10];

void display()
{
struct node *p;
p=START;
printf("rollno \t name \t marks \n");
while(p!=NULL)
	{
	ROLLNO=p->rollno;
	MARKS=p->marks;
	strcpy(NAME,p->name);
	printf("%d \t %s \t %d \n",ROLLNO,NAME,MARKS);
	p=p->link;
	}
}

void insert_begin()
{
struct node *newnode;
newnode=malloc(sizeof(struct node));
printf("\n enter the details\n");
scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
newnode->rollno=ROLLNO;
newnode->marks=MARKS;
strcpy(newnode->name,NAME);
newnode->link=START;
START=newnode;
}

void insert_end()
{
struct node *p;
p=START;
while(p->link!=NULL)
	{p=p->link;
	}
struct node *newnode;
newnode=malloc(sizeof(struct node));
printf("\n enter the details\n");
scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
newnode->rollno=ROLLNO;
newnode->marks=MARKS;
strcpy(newnode->name,NAME);
p->link=newnode;
newnode->link=NULL;
}


int main()
{
int i,n;
printf("enter the limit \n");
scanf("%d", &n);
for(i=1;i<=n;i++)
	{if(START==NULL)
		{struct node *newnode;
		newnode=malloc(sizeof(struct node));
		printf("\n enter the details\n");
		scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
		newnode->rollno=ROLLNO;
		newnode->marks=MARKS;
		strcpy(newnode->name,NAME);
		newnode->link=NULL;
		START=newnode;
		}
	else
		{struct node *newnode;
		newnode=malloc(sizeof(struct node));
		printf("\n enter the details\n");
		scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
		newnode->rollno=ROLLNO;
		newnode->marks=MARKS;
		strcpy(newnode->name,NAME);
		newnode->link=NULL;
		START->link=newnode;
		}
	}
display();
insert_begin();
display();
insert_end();
display();
}
