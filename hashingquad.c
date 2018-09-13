#include<stdio.h>

void main()
{
        int a[10],n,c,k,i,j,b;


        printf("\nEnter the number of elements: ");
        scanf("%d",&n);

        for(i=0;i<10;i++)
           a[i] = 0;


        for(i=0;i<n;i++)
        {
		j=1;
                scanf("%d", &c);

                k = c % 10;
		b = k;

                if(a[k] == 0)
                        a[k] = c;
                else

X:
		        for(;a[k]!=0 && k<10;)
			{
				k = b + (j*j);
				j++;
			}

			for(;k>=10;)
			{
				k = k - 10;
	           		goto X;
			}

                a[k] = c;
        }


        for(i=0;i<10;i++)
                printf("\n%d | %d",i,a[i]);
}

