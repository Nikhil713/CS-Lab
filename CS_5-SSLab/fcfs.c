#include<stdio.h>
void main()
{
	int bt[20], wt[20], tat[20], i, n;

	printf("\nEnter the number of processes\n");
	scanf("%d", &n);

	for(i=0;i<n;i++)
	{
		printf("\nEnter Burst Time for Process %d \n ", i);
		scanf("%d", &bt[i]);
	}

	wt[0]  = 0;
	tat[0] =  bt[0];

	for(i=1;i<n;i++)
	{
		wt[i] = wt[i-1] +bt[i-1];
		tat[i] = tat[i-1] +bt[i];
	}

	printf("\nWAITING TIME");
	for(i=0;i<n;i++)
		printf("\nP%d \t\t %d", i, wt[i]);

	printf("\nTURN AROUND TIME");
	for(i=0; i<n; i++)
		printf("\nP%d \t\t %d", i, tat[i]);

	printf("\n");

}

