#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int empty=0,full=0,n=0,mutex=1;
int pro_cnt=0,con_cnt=0;

int wait(int);
int signal(int);

void main()
{

  int choice;
  void producer();
  void consumer();

  printf("Enter the buffer size : ");
  scanf("%d",&n);
  empty=n;
  printf("Enter your choice :-\n");
  printf("1.Produce\t2.Consume\t3.Exit\n");
  while(1)
  {
    printf("Your choice : ");
    scanf("%d",&choice);
    printf("\n");
    switch(choice)
    {
    	 case 1:
		{
			if((mutex==1)&&(empty!=0))
                 		producer();
                	else
                  		printf("Buffer is full!!!!\n");
                	break;
               }
      	case 2:
		{
		 	if((mutex==1)&&(full!=0))
                  		consumer();
                	else
                  		printf("Buffer is empty!!!!!\n");
                	break;
              }
      default:
		exit(0);
		break;
    }

    printf("Number of produced items : %d \nNumber of consumed items : %d \n",pro_cnt,con_cnt);
  }
}

//Producer Function
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    pro_cnt++;
    printf("Produced Item.. \n");
    mutex=signal(mutex);
}

//Consumer Function
void consumer()
{
  mutex=wait(mutex);
  full=wait(full);
  empty=signal(empty);
  con_cnt++;
  printf("Consumed Item.. \n");
  mutex=signal(mutex);
}

//Wait
int wait(int semaphore)
{
      return(--semaphore);
}

//Signal
int signal(int semaphore)
{
      return(++semaphore);
}

