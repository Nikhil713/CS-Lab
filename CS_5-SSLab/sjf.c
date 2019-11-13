#include<stdio.h>

void main()
{
	int p[20], bt[20], wt[20], tat[20], i, k, n, temp;

	printf("\nEnter the number of processes\n");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("Enter Burst Time for Process %d\n", i);
		scanf("%d", &bt[i]);
	}

	for(i=0;i<n;i++)
		for(k=i+1;k<n;k++)
			if(bt[i]>bt[k])
			{
				temp=bt[i];
				bt[i]=bt[k];
				bt[k]=temp;

				temp=p[i];
				p[i]=p[k];
				p[k]=temp;
			}

	wt[0]  = 0;
	tat[0] = bt[0];

	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] +bt[i-1];
		tat[i] = tat[i-1] +bt[i];
	}

	printf("\nWAITING TIME");
	for(i=0;i<n;i++)
		printf("\nP%d \t\t %d", p[i], wt[i]);

	printf("\nTURN AROUND TIME");
	for(i=0; i<n; i++)
		printf("\nP%d \t\t %d",p[i], tat[i]);

	printf("\n");

}
