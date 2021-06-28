#include <stdio.h>
int a,b,u,v,n,i,j,ne=1;
int visited[8]={0},min,mincost=0;
int cost[][8]={
	{9999,9999,9999,9999,9999,9999,9999,9999},
	{9999,9999,1,9999,4,9999,9999,9999},
	{9999,1,9999,2,6,4,9999,9999},
	{9999,9999,2,9999,9999,5,6,9999},
	{9999,4,6,9999,9999,3,9999,4},
	{9999,9999,4,5,3,9999,8,7},
	{9999,9999,9999,6,9999,8,9999,3},
	{9999,9999,9999,9999,4,7,3,9999}
};

void prismMST()
{
	visited[1]=1;
	printf("The edges of tMinimun cost spanning tree are\n ");
	while(ne<n)
	{
		for(i=1,min=9999;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(cost[i][j]<min)
				{
					if (visited[i]!=0)
					{
						min=cost[i][j];
						a=u=i;
						b=v=j;
					}
				}
			}
		}
		if (visited[u]==0 || visited[v]==0)
		{
			printf("\nEdge %d :(%d %d) cost: %2d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=9999;
	}
	printf("\n\n Minimum cost= %d \n", mincost);
}
int main ()
{
/*	printf("\n Enter number of nodes:\n");
	scanf("%d",&n);
	printf("\n Enter the matrix: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=9999;
		}
	}*/
	n=7;
	prismMST();

}