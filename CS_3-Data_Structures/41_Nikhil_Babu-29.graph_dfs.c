#include<stdio.h>			//Implementation of graph-DFS
int dfs(int);
int n,v[100],a[100][100];
void main()
{
	int i,j;
	printf("Enter the number of vertices");
	scanf("%d",&n);
	printf("Enter the adjacency matrix");// Assume vertices are V1 V2...Vn
	printf("\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<n;i++)
		v[i]=0;
        dfs(0);
}
int dfs(int i)
{
	int j;
	printf("\n V %d",i);
	v[i]=1;
	for(j=0;j<n;j++)
		if(!v[j]&&a[i][j]==1)
			dfs(j);
}

