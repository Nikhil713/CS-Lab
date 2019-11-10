#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 11

char l[10];
struct symb
{
    int add;
    char label[10];
}sy[11];

void search()
{
    FILE *fp1;
    char la[10];
    int set=0,s;
    int j,i;
    printf("\nEnter the Label:");
    scanf("%s",la);
    fp1=fopen("symbol.txt","r");
    for(i=0;i<MAX;i++)
    {
        fscanf(fp1,"%d%d",&j,&sy[i].add);
        if(sy[i].add!=0)
            fscanf(fp1,"%s",sy[i].label);
    }
    for(i=0;i<MAX;i++)
    {
        if(sy[i].add!=0)
        {
            if(strcmp(sy[i].label,la)==0)
            {
                set=1;
                s=sy[i].add;
            }
        }
    }
    if(set==1)
        printf("\nThe Label --%s-- is present in the Symbol Table at Address:%d",la,s);
    else
        printf("\nThe Label is Not Present in the Symbol Table!!");
}

void display(int a[MAX])
{
    FILE *fp;
    int i;
    fp=fopen("symbol.txt","w");
    printf("\nThe Symbol Table");
    printf("\n*****************");
    printf("\nHash Values\tAddress\tLabel");
    for(i=0;i<MAX;i++)
    {
        printf("\n%d\t %d\t %s",i,sy[i].add,sy[i].label);
        fprintf(fp,"\n%d %d %s",i,sy[i].add,sy[i].label);
    }
    fclose(fp);
}

int create(int num)
{
    int key;
    key=num%11;
    return key;
}

void lprob(int a[MAX],int key,int num)
{
    int flag,i,count=0;
    flag=0;
    if(a[key]==0)
    {
        a[key]=num;
        sy[key].add=num;
        strcpy(sy[key].label,l);
    }
    else
    {
        i=0;
        while(i<MAX)
        {
            if(a[i]!=0)
                count++;
            i++;
        }
        if(count==MAX)
        {
            printf("\nHash table is Full!!");
            display(a);
            exit(1);
        }
        for(i=key+1;i<MAX;i++)
            if(a[i]==0)
            {
                a[i]=num;
                flag=1;
                sy[key].add=num;
                strcpy(sy[key].label,l);
                break;
            }
        for(i=0;i<key && flag==0;i++)
            if(a[i]==0)
            {
                a[i]=num;
                flag=1;
                sy[key].add=num;
                strcpy(sy[key].label,l);
                break;
            }
      }
}

void main()
{
    int a[MAX],num,key,i,ch;
    char ans='y';
    for(i=0;i<MAX;i++)
        a[i]=0;
    do
    {
        printf("\nSymbol Table Menu\n1.Create a Symbol Table\n2.Search in the Symbol Table\n3.Exit\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: while(ans=='y')
                    {
                        printf("\nEnter the Address:");
                        scanf("%d",&num);
                        key=create(num);
                        printf("\nEnter The Label:");
                        scanf("%s",l);
                        lprob(a,key,num);
                        printf("\nDo you want to Continue(y/n)?");
                        scanf(" %c",&ans);
                    }
                    display(a);
                    break;
            case 2: search();
                    break;
        case 3: exit(0);
        }
    }while(ch<=3);
}

