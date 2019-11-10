
#include<stdio.h>

void main()
{

	int i,j,n,bu[10],wa[10],tat[10],t,ct[10],max, temp = 0;

	printf("Enter the no of processes\n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter Burst Time for process %d\n", i+1);
		scanf("%d",&bu[i]);
		ct[i]=bu[i];
	}

	printf("\nEnter the size of time slice\n");
	scanf("%d",&t);

	max=bu[0];

	for(i=1; i<n; i++)
		if(max<bu[i])
			max=bu[i];

	for(j=0; j<(max/t)+1; j++)
		for(i=0; i<n; i++)
			if(bu[i] != 0)
				if(bu[i] <= t)
				{
					tat[i] = temp + bu[i];
					temp = temp + bu[i];
					bu[i] =0;
				}
				else
				{
					bu[i] = bu[i] - t;
					temp = temp + t;
				}

	for(i=0; i<n; i++)
		wa[i]=tat[i]-ct[i];

	printf("\nWAITING TIME");
	for(i=0;i<n;i++)
		printf("\nP%d \t %d",i+1,wa[i]);

	printf("\nTURN AROUND TIME");
	for(i=0; i<n; i++)
		printf("\nP%d \t %d", i+1,tat[i]);

	printf("\n");
}
