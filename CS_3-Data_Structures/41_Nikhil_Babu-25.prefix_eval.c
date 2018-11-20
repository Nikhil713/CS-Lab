#include<stdio.h>
#include<stdlib.h>				//Program to evaluate a prefix expression
#include<ctype.h>
#include<string.h>
#include<math.h>

int empty();
void push(int);
char pop();

int top=-1;
int stack[30];
int size=30;

void main()
{
    char post[30],op;
    char opnd2,opnd1,symb;
    int k=0,val,p,q;
    printf(" \n Enter the Postfix Expression : ");
    gets(post);
    while(post[k]!='\0')
        k=k+1;
    k-=1;
    while(k>-1)
    {
        symb=post[k];
        if(isdigit(symb))
        {
            //printf("%d",symb);
            int newsymb=(symb-48);
            //printf("%d ",newsymb);
            push(newsymb);
        }
        else
        {
            opnd1=(pop());
            opnd2=(pop());
            p=opnd1;
            q=opnd2;

            printf(" \n P=%d Q=%d",p,q);
            switch(symb)
            {
                case'+':val=p+q;
                        break;
                case'-':val=p-q;
                        break;
                case'*':val=p*q;
                        break;
                case'/':val=p/q;
                        break;
                case'^':val=pow(p,q);
                        break;
                default:printf(" \n ENTER From +,-,*,/,^ ...ERROR !!! ");
                        break;
            }
            //val=((int)opnd1)(symb)((int)opnd2);
            push(val);
        }
        k-=1;
    }
    printf(" \n Result = %d \n ",pop());
}

void push(int x)
{
    if(top==size-1)
        printf(" \n OVERFLOW !!!");
    else
    {
        top+=1;
        stack[top]=x;
        //printf("%d",stack[top]);
    }
}

char pop()
{
    if(top!=-1)
    {
        char data;
        data=stack[top];
        top=top-1;
        return data;
    }
}
