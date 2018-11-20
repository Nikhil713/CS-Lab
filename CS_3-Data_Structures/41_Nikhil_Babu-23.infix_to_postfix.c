#include<stdio.h>				//Program to convert infix to postfix expression
#include<ctype.h>
#include<string.h>

int empty();
void push(char);
char pop();
char peek();
int precedence(char,char);
void convert();


int top=-1;
int stack[30];
int size=30;

void main()
{
    char postfix[30],topsymb,symb,n,expr[30];
    int i,j=0,k=0;
    printf(" \n Enter expression [Newline to exit] :");
    gets(expr);
    while(expr[k]!='\0')
    {
        symb=expr[k];
        if(isalpha(symb))
        {
            postfix[j]=symb;
            j+=1;
        }
        else
        {
            while( (empty()!=1) && (i=precedence(peek(),symb)) )
            {
                topsymb=pop();
                postfix[j]=topsymb;
                j+=1;
            }
            if(empty() || symb!=')')
                push(symb);
            else
                topsymb=pop();
        }
        k+=1;
    }
    while(empty()!=1)
    {
        topsymb=pop();
        postfix[j]=topsymb;
        j+=1;
    }

    printf(" \n\n Postfix Expression : ");
    for(int i=0;i<j;i++)
        printf("%c",postfix[i]);
}

void push(char x)
{
    if(top==size-1)
        printf(" \n Stack OverFlow !!!");
    else
    {
        top=top+1;
        stack[top]=x;
    }
}

int empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

char pop()
{
    if(empty()!=1)
    {
        char data;
        data=stack[top];
        stack[top]=0;
        top=top-1;
        return data;
    }
}

char peek()
{
    return(stack[top]);
}

int precedence(char x,char y)
{
    if(x==y)
        return 1;
    else if( ((x=='*')||(x=='/')||(x=='^')) && ((y=='+')||(y=='-')) )
        return 1;
    else if( ((x=='+')||(x=='-')) && ((y=='*')||(y=='/')||(y=='^')) )
        return 1;
    else if( ((x=='*')||(x=='/')||(x=='^')) && ((y=='*')||(y=='/')||(y=='^')) )
        return 1;
    else if( ((x=='+')||(x=='-')) && ((y=='+')||(y=='-')) )
        return 1;

    else if(x=='(')
        return 0;
    else if(x!=')' && y=='(')
        return 0;
    else if(x!='(' && y==')')
        return 1;
}
