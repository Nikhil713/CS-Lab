#include<stdio.h>
#include<string.h>

void main()
{
        int ph[20],n,l,k,i,j,num;
        char a[20][10],c[10];


        printf("\nEnter the number of elements: ");
        scanf("%d",&n);

        for(i=0;i<20;i++)
	{
        	strcpy(a[i],"BLANK");
		ph[i] = 0;
	}

        for(j=0;j<n;j++)
        {
		printf("\nEnter the name : ");
                scanf("%s",c);
                l = strlen(c);
		k = 0;

		for(i=0;i<l;i++)
			k = k +( (i+1) * (int)c[i] );
		k = k%20;

		int cnt=0;
                for(;strcmp(a[k%20],"BLANK")!=0 && cnt<20 ;k++,cnt++);

		if(cnt>=20)
			printf("\nFULL\n");

                strcpy(a[k],c);

		printf("\nEnter the phone number : ");
		scanf("%d",&num);
		ph[k] = num;

        }


        for(i=0;i<20;i++)
                printf("%d |  %s | %d \n",i,a[i],ph[i]);

	printf("\n Enter the name : ");
	scanf("%s",c);

	for(i=0;i<20;i++)
		if(strcmp(a[i],c)==0)
			printf("\n %d",ph[i]);
}




