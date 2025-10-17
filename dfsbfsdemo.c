#include<stdio.h>
# define MAX 15

void dfs(int vertex,int visited[MAX],int adjacency[MAX][MAX],int vertexcount)
{
    printf("vertex %d ",vertex);
    visited[vertex]=1;
    for(int i=0;i<vertexcount;i++)
    {
        if(adjacency[vertex][i]==1 && !visited[i])
        {
            dfs(i,visited,adjacency,vertexcount);
        }
    }

}

void bfs(int startvertex,int visited[MAX],int adjacency[MAX][MAX],int vertexcount)
{
    int queue[vertexcount];
    int front=-1,rear=-1;
    int vertex;

    queue[++rear]=startvertex;
    visited[startvertex]=1;

    while(front!=rear)
    {
      vertex=queue[++front];
      printf("vertex %d ",vertex);
      for(int i=0;i<vertexcount;i++)
      {
        if(adjacency[vertex][i]==1 && visited[i]==0)
        {
            queue[++rear]=i;
            visited[i]=1;
        }
      }
    }
}

int main()
{
   int visited[MAX]={0};
   int adjacency[MAX][MAX];
   int vertexcount,choice;

    printf("enter the number of vertices: \n");
    scanf("%d",&vertexcount);

    printf("enter adjacencymatrix :\n");

    for(int i=0;i<vertexcount;i++)
    {
        for(int j=0;j<vertexcount;j++)
        {
            scanf("%d",&adjacency[i][j]);
        }
    }
    do{
        printf(" \n MENU  \n");
        printf("1. dfs\n");
        printf("2.bfs \n");
        printf("3. exit()\n");
        printf("enter your choice: \n");
        scanf("%d",&choice);
        
        for(int i=0;i<vertexcount;i++)
        {
            visited[i]=0;
        }

        switch(choice)
        {
           case 1:
           for(int i=0;i<vertexcount;i++)
           {
            if(visited[i]==0)
            {
                dfs(i,visited,adjacency,vertexcount);
            }
           }
           break;

           case 2:
           for(int i=0;i<vertexcount;i++)
           {
            if(visited[i]==0)
            {
                bfs(i,visited,adjacency,vertexcount);
            }
           }
           break;
        }
    }while(choice!=3);

    return 0;



}