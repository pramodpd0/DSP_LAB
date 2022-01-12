/* Graph creation using adjacency matrix and
   BFS, DFS traversal
*/


#include<stdio.h>
#include<stdlib.h>

// creating graph structure: V ,E is number of vertices and edges respectively, 
// and 2-D array for adjacency matrix
struct graph
{
    int V;
    int E;
    int** arr;
};
typedef struct graph graph;

/* helper function Queue -----------------------------------*/
typedef struct Queue
{
    int size;
    int f;
    int r;
    int* arr;
}queue;

queue create_queue(int v)
{
    queue q;
    q.size = v;
    q.f=-1; 
    q.r=-1; 
    q.arr = (int*)malloc(sizeof(int)*q.size);
    return q;

}

int is_full(queue* q)
{
    if(q->r == q->size-1)
    {
        return 1;
    }
    return 0;
}

int is_empty(queue* q)
{
    if(q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue* q, int val)
{
    if(is_full(q))
    {
        printf("Queue is full \n");
    }

    else
    {
        q->r++;
        q->arr[q->r]= val;
    }
}


int dequeue(queue*q)
{
    int x;
    if(is_empty(q))
    {
        printf("Queue is Empty \n");
    }
    else
    {
        q->f++;
        x = q->arr[q->f];
    }
    return x;
    
}
/*-------------------------------------------------------------------------------*/

int* visited; 

// function graph creation using adjacency matrix 
graph* create_graph(int vertices)
{
    int i,j,s,d;
    graph* G= (struct graph*)malloc(sizeof(graph));

    G->V=vertices;

    // allocating memory to 2-D array for adjacency matrix
    G->arr= (int**)malloc(G->V * sizeof(int*));
    for(i=0;i<G->V;i++)
    {
        G->arr[i]= (int*)malloc(G->V * sizeof(int));
    }

    // initializing   array
    for(i=0;i<G->V;i++)
    {
       
        for(j=0;j<G->V;j++)
        {
            G->arr[i][j]=0;
        }
    }

    // Enter number of edges  
    printf("Enter number of Edges\n");
    scanf("%d",&G->E);

    //Insert starting vertex and ending vertex for every edges and update value "1" in matrix
    printf("Enter node pair of edges :\n");
    for(i=0;i<G->E;i++)
    {
        scanf("%d%d",&s,&d);
        G->arr[s][d]=1;
        G->arr[d][s]=1;
    }

    // printing adjacency matrix of graph
    for(i=0;i<G->V;i++)
    {
        printf("\n");
        for(j=0;j<G->V;j++)
        {
            printf("%d ",G->arr[i][j]);
        }
        
    }

    return G;
}

// function for depth first search traversal of graph
void dfs(graph* G, int start)
{
    int j;
    printf(" %d ",start);
    visited[start]=1;
    for(j=0;j<G->V;j++)
    {
        if((G->arr[start][j]==1) && visited[j]==0)
        {
            dfs(G,j);
        }

    }
    
}

// function for breadth first search traversal of graph
void bfs(graph* G, int start, queue q)
{
    int j;

    printf("%d ",start);
    visited[start]=1;
    enqueue(&q,start);

    while(!is_empty(&q))
    {
        int u=dequeue(&q);
        for(j=0;j<G->V;j++)
        {
            if(G->arr[u][j]==1 && visited[j]==0)
            {
                printf("%d ",j);
                visited[j]=1;
                enqueue(&q, j);
            }
        }

    }


}

// Driver program for bfs dfs traversal
int main()
{
    int i=0;
    int v,s,d;
    printf("Enter number of vertices\n");
    scanf("%d",&v);

    graph* G= create_graph(v);

    queue q= create_queue(v);
   
    visited=(int*)malloc(G->V * sizeof(int));
   
    for(i=0;i<G->V;i++)
    {
        visited[i]=0;
      
    }
    printf("\nDepth First Traversal of this graph:\n"); 
    dfs(G,0);

    for(i=0;i<G->V;i++)
    {
        visited[i]=0;
      
    }
    printf("\nBreadth First Traversal of this graph:\n"); 
    bfs(G,0,q);


    return 0;
}

