#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    char name[128];
    bool isDir;
    struct node *p;
    struct node *c[100];
    int i;
} * head, *curr;

void ls()
{
    if (curr->i == 0)
    {
        printf("Empty directory\n");
        return;
    }
    int i=0;
    for ( i = 0; i < curr->i; i++)
    {
        if (curr->c[i]->isDir)
            printf("*%s*  ", curr->c[i]->name);
        else
            printf("%s  ", curr->c[i]->name);
    }
}

void add(bool d)
{
    printf("Enter the Name:\n");
    char fname[128];
    scanf("%s", fname);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, fname);
    temp->isDir = d;
    temp->p = curr;
    temp->i=0;

    curr->c[curr->i] = temp;
    curr->i = (curr->i) + 1;
}

void cd()
{
    printf("Enter directory name:\n");
    char dname[128];
    scanf("%s", dname);
    int i=0;
    for (i = 0; i < curr->i; i++)
    {
        if (!strcmp(curr->c[i]->name, dname) && curr->c[i]->isDir)
        {
            curr = curr->c[i];
            return;
        }
    }
    printf("Directory not present.\n");
}

void cdparent()
{
    if (curr->p == NULL)
    {
        printf("You are at the root directory\n");
        return;
    }
    curr = curr->p;
}

void del(bool d)
{
    printf("Enter name of file or directory to delete:\n");
    char name[128];
    scanf("%s", name);
    int i =0;
    for ( i = 0; i < curr->i; i++)
    {
        if (!strcmp(curr->c[i]->name, name) && ((d && curr->c[i]->isDir == true) || (!d && curr->c[i]->isDir == false)))
        {
            int t = i;
            while (t < (curr->i) - 1)
            {
                curr->c[t] = curr->c[t + 1];
                t++;
            }
            curr->i = (curr->i) - 1;
            printf("Successfully deleted.\n");
            return;
        }
    }
    printf("Not found\n");
}

void main()
{
    int in;
    head = (struct node *)malloc(sizeof(struct node));
    strcpy(head->name, "root");
    head->isDir = true;
    head->p = NULL;
    head->i = 0;
    curr = head;
    while (true)
    {
        printf("\n\nYou are in %s directory.\n1. show everything in this directory\n2. change directory\n3. go to parent directory\n4. add new file\n5. delete file\n6. create new directory\n7. delete directory\n8. exit\n", curr->name);
        scanf("%d", &in);
        switch (in)
        {
            case 1:
                ls();
                break;
            case 2:
                cd();
                break;
            case 3:
                cdparent();
                break;
            case 4:
                add(false);
                break;
            case 5:
                del(false);
                break;
            case 6:
                add(true);
                break;
            case 7:
                del(true);
                break;
            default:
                exit(0);
        }
    }
}
