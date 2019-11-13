#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
	char dname[10],fname[10][10];
	int fcnt;
}dir;

void main()
{
	int i,ch;
	char f[30];

	dir.fcnt = 0;
	printf("\nEnter name of directory\n");
	scanf("%s", dir.dname);

	while(1)
	{

		printf("\n1. Create File\t2. Delete File\t3. Search File \t4. Display Files\t5. Exit\nEnter your choice\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("\nEnter the name of the file\n");
				scanf("%s",dir.fname[dir.fcnt]);
				dir.fcnt++;
				break;

			case 2: printf("\nEnter the name of the file\n");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f, dir.fname[i])==0)
					{
						printf("File %s is deleted ",f);
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						break;
					}
				}
				if(i==dir.fcnt)
					printf("File %s not found",f);
				else
					dir.fcnt--;
				break;

			case 3: printf("\nEnter the name of the file\n");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f, dir.fname[i])==0)
					{
						printf("File %s is found ", f);
						break;
					}
				}
				if(i == dir.fcnt)
					printf("File %s not found",f);
				break;
			case 4: if(dir.fcnt==0)
					printf("\nDirectory Empty");
				else
				{
					printf("\nThe Files are\n");
					for(i=0;i<dir.fcnt;i++)
						printf("\t%s",dir.fname[i]);
				}
				break;

			default: exit(0);
		}
	}
}
