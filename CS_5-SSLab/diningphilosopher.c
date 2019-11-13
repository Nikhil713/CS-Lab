#include<stdio.h>
#include<stdlib.h>

void pickup(int);
void putdown(int);
void test(int);
void initialisation();

enum {THINKING,HUNGRY,EATING} state[5];
int flag[5],n;

void main()
{
	int i,j,ch;

	initialisation();
	while(1)
	{
		printf(" \n Menu \n 1)Start Eat \n 2)Stop Eating \n 3)EXIT \n Enter Choice : ");
		scanf("%d",&ch);
		if(ch==3)
			exit(0);
		printf(" \n Which Philosopher do u want to interact with (1 to 5) : ");
		scanf("%d",&n);
		switch(ch)
		{
		case 1 :pickup(n-1);
			break;
		case 2 :putdown(n-1);
			break;
//		case 3 :exit(0);
		default:printf(" \n Wrong choice !!! \n");
		}
	}
}

void initialisation()
{
	for(int k=0;k<5;k++)
	{
		state[k]=THINKING;
		flag[k]=0;
	}
}

void pickup(int x)
{
	state[x]=HUNGRY;
	test(x);
	if(state[x]!=EATING)
		flag[x]=0;
	if(flag[x]==1)
		printf(" \n Philosopher %d is Eating \n",x+1);
	else
		printf(" \n Philosopher %d cannot eat now",x+1);
}

void putdown(int x)
{
	state[x]=THINKING;
	test((x+4)%5);
	test((x+1)%5);
	printf(" \n Philosopher %d is Thinking \n",x+1);
}

void test(int x)
{
	if((state[(x+4)%5]) != EATING && (state[x]==HUNGRY) && (state[(x+1)%5]) != EATING)
	{
		state[x]=EATING;
		flag[x]=1;
	}
}
