/*
Implementation of SJF scheduling algorithm
*/
#include<stdio.h>

int main()
{
	  int bt[20],wt[20],tat[20],i,n;
	  float wtavg,tatavg;
	  printf("enter number of process\n"); 
	  scanf("%d",&n); 
	  for(i= 0;i<n;i++){
		printf("enter the process %d burst time",i);
		scanf("%d",&bt[i]);
		}
	
	wtavg = wt[0] = 0;
	tatavg = tat[0] = bt[0];
	for(i = 1;i<n;i++){
		wt[i] = wt[i-1] + bt[i-1];
		tat[i] = tat[i-1] + bt[i];
		tatavg += tat[i];
		wtavg += wt[i];				
	} 	
	printf("\n Process \t Burst Time \t Waiting Time \t Turn around time");
	for(i=0;i<n;i++){
		printf("\n P%d \t\t %d \t\t %d \t\t %d",i,bt[i],wt[i],tat[i]);
		
	}
	printf("\nAverage waiting time : %f",wtavg/n);
	printf("\n Average turn around time : %f",tatavg/n);
	
}	
	
	
