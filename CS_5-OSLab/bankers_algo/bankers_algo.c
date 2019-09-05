#include<stdio.h>

void safestate(int n,int m,int need[n][m],int allc[n][m],int avail[m]){
	int i,j,k,finish[n],work[m],ans[n];
	for(i=0;i<n;i++)
		finish[i] = 0;
	for(j=0;j<m;j++)
		work[i] = avail[i];
	int ind = 0,l;
	for(i = 0;i<n;i++){
		for(j= 0;j<n;j++){
			if(finish[i] == 0){
				int flag = 0;
				for(k=0;k<m;k++){
					if(need[j][k]>work[k]){
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					ans[ind++] = j;
					for(l=0;l<m;l++)
						work[l] += allc[j][l];
					finish[j] = 1;						
										
				}
			}
		}				
	}
	printf("Safe state\n");
	for(i = 0;i<n-1;i++){
		printf("P%d->",ans[i]);
	}
	printf("P%d",ans[n-1]);


}

int main(){
	int m,n,i,j;
	printf("Enter the max resources and process\n");
	scanf("%d %d", &m, &n);
	int max[n][m],allc[n][m],avail[m],need[n][m];
	for(i = 0;i<n;i++){
		printf("enter max resources for process %d \n",i+1);
		for(j = 0;j<m;j++){
			scanf("%d",&max[i][j]);
		}
		printf("\n");
	}
	for(i = 0;i<n;i++){
		printf("enter allocated resources for process %d \n",i+1);
		for(j = 0;j<m;j++){
			scanf("%d",&allc[i][j]);
		}
		printf("\n");
	}
	printf("available resources \n");
	for(i = 0;i<m;i++){
		scanf("%d", &avail[i]);
	}
	for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) 
            need[i][j] = max[i][j] - allc[i][j]; 
    	} 
	safestate(n,m,need,allc,avail);
}
