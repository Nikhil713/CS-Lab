#include <stdio.h>

void main()
{
	int p[20],bt[20],pri[20], wt[20],tat[20],i, k, n, temp;



	printf("Enter the number of processes \n ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		p[i] = i;
		printf("Enter the Burst Time & Priority of Process %d \n",i);
		scanf("%d %d",&bt[i], &pri[i]);
	}

	for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(pri[i] > pri[k])
			{
				temp=p[i];
				p[i]=p[k];
				p[k]=temp;

				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;

				temp=pri[i];
				pri[i]=pri[k];
				pri[k]=temp;
			}

	wt[0] = 0;
	tat[0] = bt[0];

	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
	}

	printf("WAITING TIME");

	for(i=0;i<n;i++)
		printf("\nP%d \t %d",p[i],wt[i]);

	printf("\nTURN AROUND TIME");

	for(i=0;i<n;i++)
                printf("\nP%d \t %d",p[i],tat[i]);

	printf("\n");
}
