#include<stdio.h>
#include<conio.h>
int a[10][10],n,indegree[10];
void find_indegree()
{
int i,j,sum;
for(j=0;j<n;j++)
{
 sum=0;
 for(i=0;i<n;i++)
 sum+=a[i][j];
indegree[j]=sum;
}
}
void topology()
{
int i,u,v,t[10],s[10],top=-1,k=0;
find_indegree();
for(i=0;i<n;i++)
{
 if(indegree[i]==0)s[++top]=i;
}
while(top!=-1)
{
 u=s[top--];
 t[k++]=u;
 for(v=0;v<n;v++)
 {
 if(a[u][v]==1)
 {
 indegree[v]--;
 if(indegree[v]==0)s[++top]=v;
 }
 }
}
printf("The topological sequence is:");
for(i=0;i<n;i++)
printf("\t%d",t[i]+1);
}
void main()
{
int i,j;
printf("Enter the no of Vertices: ");
scanf("%d",&n);
printf("Enter the adjacency matrix:\n");
for(i=0;i<n;i++)
{
 for(j=0;j<n;j++)
 scanf("%d",&a[i][j]);
}
topology();
//getch();
}
