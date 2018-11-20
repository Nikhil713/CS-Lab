#include<stdio.h>			//Implement a circular linked list
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node *start=NULL;

void main()
{
	int i,x,ch,pos;
    	struct node *newnode,*p,*t,*q,*s;
  	do
  	{
   		printf(" \n\n---------------------------");
    		printf(" \n CIRCULAR LINKED LIST MENU");
    		printf(" \n---------------------------");
    		printf("\n 1.Insertion \n 2.Deletion \n 3.Searching \n 4.Display  \n 5.EXIT \n");
    		printf("\n Enter your choice : ");
    		scanf("%d",&ch);

    		switch(ch)
    		{
        		case 1 :printf(" \n Enter element to insert : ");       //At End
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
                    			p=newnode;
                    			t=newnode;
                    			p->link=start;
                		}
                		break;

        		case 2 :printf(" \n Enter value to delete : ");
                		scanf("%d",&x);
                		int delflag=0;
                		p=start;
                		s=start;
                		do
                		{
                    			if(p->data==x && start->link==NULL)     //Only start
                    			{
                        			delflag=1;
                        			start=NULL;
                        			break;
                    			}
                    			else
						if((p->data==x && s->link==p && p->link==start)  )     //Only 2 nodes & delete 2th node
                    				{
                        				delflag=1;
                        				p->link=NULL;
                   		                        s->link=NULL;
                        				break;
                    				}
                    				else
							if(p->data==x && p==start)          //Delete start
                    					{
                        					delflag=1;
                        					t->link=start->link;
                        					start=start->link;
                        					break;
                    					}
                    					else
								if((p->link==start && p->data==x))               //Delete last node
                    						{
                        						delflag=1;
                        						p->link=NULL;
                        						q=start;
                        						while(q->link!=p)
                            						q=q->link;
                        						q->link=start;
                        						break;
                   	 					}
                    						else
									if(p->data==x)                 //Any other node
                    							{
                        							delflag=1;
                        							q=start;
                        							while(q->link!=p)
                            								q=q->link;
                        							q->link=p->link;
                        							p->link=NULL;
                        							break;
                    							}
                    			p=p->link;

                		}while(p!=start);

                		if(delflag==0)
                    			printf(" \n Element Not Found !!!");
               			break;

        	case 3 :printf(" \n Enter element to find : ");
                	scanf("%d",&x);
                	p=start;
                	int findflag=0,count=0;
                	do
                	{
                    		count+=1;
                    		if(p->data==x)
                    		{
                        	findflag=1;
                        	printf(" \n Element %d found at %d-th Node from start",x,count);
                        	break;
                    		}
                    		p=p->link;
                	}while(p->link!=start);
                	if(findflag==0)
                    		printf(" \n Element not found !!!");
                	break;

        	case 4: p=start;
                	if(start==NULL)
                    		printf(" \n NO NODES");
                	else
				if(start->link==NULL)
                    			printf("  %d  ||-->",start->data);
                		else
                		{
                    			printf("\n");
                    			do
                    			{
                        			printf("  %d  ||-->",p->data);
                        			p=p->link;
                    			}while(p!=start);
                		}
                		break;

        	case 5 :break;
       	 	default:printf(" \n Wrong Choice");
    		}
  	}while(ch!=5);

}
