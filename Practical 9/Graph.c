#include <stdio.h>
int graph [10][10];
int visited[10];
int n;
void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d",v);
    for(i=0 ;i<n;i++)
    {
        if(graph[v][i]==1 &&visited [i]==0)
        {
            DFS(i);
        }
    }
}
void BFS(int start)

{
    int queue[10];
    int front=0,rear=0;
    int visitedBFS[10]={0};
    int i,v;
    queue[rear++]=start;
   visitedBFS[start]=1;
    while(front<rear)
    {
        v=queue[front++];
        printf("%d",v);
        for(i=0;i<n;i++)
        {
            if(graph[v][i]==1 && visitedBFS[i]==0)
            {
                queue[rear++]=i;
                visitedBFS[i]=1;
            }
        }
    }
}
int main()
{
    int i,j,start;
    printf("enter number of buildings:");
    scanf("%d",&n);
    printf("enter adjecency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);

        }
    }

    printf("\nBFS traversal:");
    BFS(0);
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("\nDFS traversal:");
    DFS(0);
    return 0;
}