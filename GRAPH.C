#include<stdio.h>
#include<conio.h>
#define INF 999

void floydwarshall(int n,int graph[5][5])
{
int k,i,j,dist[5][5];
for(i=0;i<n;i++){
for(j=0;j<n;j++)
{
dist[i][j]=graph[i][j];
}
}
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(dist[i][k]+dist[k][j]<dist[i][j])
{
dist[i][j]=dist[i][k]+dist[k][j];
}
}
}
}
printf("\nThe shortest distance matrix:\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(dist[i][j]==INF)
printf("%7s","INF");

else
printf("%7d",dist[i][j]);

}
printf("\n");
}
}

int main()
{
int n,i,j;
int graph[5][5];
clrscr();
printf("enter the number of vertices: ");
scanf("%d",&n);
printf("Enter the adjacency matrix(enter %d for infinity):\n",INF);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&graph[i][j]);
}
}
floydwarshall(n,graph);
getch();
return 0;
}
