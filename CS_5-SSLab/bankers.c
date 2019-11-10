#include <stdio.h>

int current[10][10], maximum_claim[10][10], available[10];
int allocation[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int maxres[10], running[10], safe = 0;
int counter = 0, n, m, i, j, exec, resources, processes, k = 1;

void main()
{
	printf("\nEnter number of processes: ");
    	scanf("%d", &processes);

    	for (i = 0; i < processes; i++)
	{
        	running[i] = 1;
        	counter++;
    	}

    	printf("\nEnter number of resources: ");
    	scanf("%d", &resources);


    	printf("\nEnter the maximum available resources:\n");
    	for (i = 0; i < resources; i++)
	        scanf("%d", &maxres[i]);


   	printf("\nEnter Allocated Resources:");
    	for (i = 0; i < processes; i++)
	{
		printf("\nProcess %d \n", i+1);
	        for(j = 0; j < resources; j++)
  			scanf("%d", &current[i][j]);
	}


    	printf("\nEnter Maximum Resouces for each process:\n");
    	for (i = 0; i < processes; i++)
	{
		printf("\nProcess %d \n", i+1);
        	for(j = 0; j < resources; j++)
            		scanf("%d", &maximum_claim[i][j]);
	}

	printf("\nThe Available Resource is: ");
    	for (i = 0; i < resources; i++)
	        printf("\t%d", maxres[i]);


    	printf("\nThe Allocated Resource Table:\n");
    	for (i = 0; i < processes; i++)
	{
	        for (j = 0; j < resources; j++)
            		printf("%d   ", current[i][j]);
		printf("\n");
    	}


    	printf("\nThe Maximum resource available:\n");
    	for (i = 0; i < processes; i++)
	{
        	for (j = 0; j < resources; j++)
		        printf("%d   ", maximum_claim[i][j]);
        	printf("\n");
    	}



    int f[processes], ans[processes], ind = 0;

    n = processes;
    m = resources;
    for(k = 0; k < n; k++)
        f[k] = 0;

    int need[n][m];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
		need[i][j] = maximum_claim[i][j] - current[i][j];


    int y = 0;
    for (k = 0; k < 10; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
         {
                int flag = 0;
                for (j = 0; j < m; j++)
		{
                    if (need[i][j] > maxres[j])
	            {
                         flag = 1;
                         break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        maxres[y] += current[i][y];
                    f[i] = 1;

                }
            }
        }
    }



   for(i=0; i<n; i++)
	if(f[i] == 0)
		break;

   if(i == n)
   {
    	printf("Following is the SAFE Sequence\n");
   	 for (i = 0; i < n - 1; i++)
        	printf(" P%d ->", ans[i]);
	    printf(" P%d \n", ans[n - 1]);
   }

   else
	printf("\nNOT SAFE STATE\n");

}
