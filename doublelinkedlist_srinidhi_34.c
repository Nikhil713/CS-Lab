/*
Double Linked list to store the students roll no,name,marks

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int rollno,marks;
	char name[10];
	struct node *front;
  struct node *rear;
	}*START=NULL;

int ROLLNO,MARKS;
char NAME[10];

void insert_begin()
{
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	printf("\n enter the details\n");
	scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
	newnode->rollno=ROLLNO;
	newnode->marks=MARKS;
	strcpy(newnode->name,NAME);
	START->front=newnode;
	newnode->rear=START;
	newnode->front=NULL;
	START=newnode;
}

void insert_end(/* arguments */)
{
	/* code */
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	printf("\n enter the details\n");
	scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
	newnode->rollno=ROLLNO;
	newnode->marks=MARKS;
	strcpy(newnode->name,NAME);
	struct node *p;
	p=START;
	while(p->rear!=NULL)
		{
			p = p->rear;
		}
	newnode->rear = NULL;
	newnode->front = p;
	p->rear = newnode;
}

void insert_at_pos(int pos) {
	/* code */
	struct node *newnode;
	newnode=malloc(sizeof(struct node));
	printf("\n enter the details\n");
	scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
	newnode->rollno=ROLLNO;
	newnode->marks=MARKS;
	strcpy(newnode->name,NAME);
	struct node *p,*q;
	p = START;
	while(p->rollno!=pos)
	{
		p = p->rear;
	//	if(p->rear==NULL)
		//	break;
	}
	q=p->rear;
	p->rear=newnode;
	newnode->front=p;
	q->front=newnode;
	newnode->rear=q;

}

void delete(int pos) {
	/* code */
	struct node *p,*before,*after;
	p=START;
	while(p->rollno!=pos) {
		p=p->rear;
		/* code */
	}
	before=p->front;
	after=p->rear;
	before->rear=after;
	after->front=before;
}

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
		p=p->rear;
		}
}

int main()
{ struct node *p;
  int n,i;
  printf("enter the limit\n");
  scanf("%d", &n);
  for(i=0;i<n;i++)
      {
        if(START==NULL)
          {
            struct node *newnode;
            newnode=malloc(sizeof(struct node));
            printf("\n enter the details\n");
        		scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
        		newnode->rollno=ROLLNO;
        		newnode->marks=MARKS;
        		strcpy(newnode->name,NAME);
            newnode->front=NULL;
            newnode->rear=NULL;
            START=newnode;
            p=newnode;
          }
        else
            { struct node *newnode;
            newnode=malloc(sizeof(struct node));
            printf("\n enter the details\n");
        		scanf("%d %s %d", &ROLLNO, NAME, &MARKS);
        		newnode->rollno=ROLLNO;
        		newnode->marks=MARKS;
        		strcpy(newnode->name,NAME);
            p->rear=newnode;
            newnode->front=p;
            newnode->rear=NULL;
            p=newnode;

            }
      }
printf("\n Menu \n 1)insert at begin \n 2) insert at position \n 3)insert at end \n 4)delete at pos \n 5) display \n  \n Enter 0 to exit\n" );

int ch,pos;

do {
  printf("enter the choice\n" );
  scanf("%d",&ch);
  switch (ch) {
    case 1 : insert_begin();
              break;
    case 2 : printf("enter the position\n");
              scanf("%d", &pos );
              insert_at_pos(pos);
              break;
    case 3 : insert_end();
              break;
    case 4 : printf("enter the position\n" );
              scanf("%d", &pos );
              delete(pos);
              break;
   case 5 : display();
              break;
/*    case 6 : printf("enter the position\n", );
              scanf("%d", &pos );
              search(pos);
*/
  }
} while(ch!=0);



}
