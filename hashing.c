#include<stdio.h>

void main()
{
        int a[10],n,c,k,i;


        printf("\nEnter the number of elements: ");
        scanf("%d",&n);

        for(i=0;i<10;i++)
           a[i] = 0;


        for(i=0;i<n;i++)
        {
                scanf("%d", &c);

                k = c % 10;

                if(a[k] == 0)
                        a[k] = c;
                else
                        for(;a[k]!=0 && k<10;k++);

                if(k >= 10)
                        for(k=0;a[k]!=0;k++);

                a[k] = c;
        }


        for(i=0;i<10;i++)
                printf("\n%d",a[i]);
}

