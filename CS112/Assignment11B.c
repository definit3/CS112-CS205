/*NAME- VIVEK RAJ
  ROLL 1601CS49*/

#include <stdio.h>
#include <stdlib.h>

int i,j,k,n;
int adj[1000][1000]={0},capacity[1000][1000]={0};

void print_matrix(int adjj[][1000]){    //function to print the adjacency matrix
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n+1;j++){
            printf("%d  ",adjj[i][j]);
        }
        printf("\n");}
    }

void buildadj(){
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(j-i<=3 && i!=j)adj[i][j]=1;
            else adj[i][j]=0;
            if(adj[i][j]==1)capacity[i][j]=i+j;
            //printf("%d  %d  -  %d\n",i,j,capacity[i][j]);
        }
        if(i<=n/4 && i>=1){adj[0][i]=1;capacity[0][i]=i;}
        if(i>=3*n/4 && i<=n){adj[i][n+1]=1;capacity[i][n+1]=i;}
    }

}



int bfs(int newadj[][n+2],int s,int t,int parent[]){     //function to perform bfs

    int black[1000]={0};
    for(i=0;i<1000;i++)black[i]=0;
    int q; //declaring int q to be used a current working vertex
    int front=0;
    int rear=0;
    int que[1000]={0};   //declaring a array to be used as a queue
    for(i=0;i<1000;i++){que[i]=0;}
    black[s]=1;
    parent[s]=-1;
    que[rear]=s;
    rear=rear+1;
    for(;rear!=front;){   //stopping condition- if the queue is empty
        q=que[front];
       // printf("\n%d  ",q);
        front=front+1;
        i=0;
        while(i<n+2){
            if(black[i]==0 && newadj[q][i]>0){
                que[rear]=i;
                rear=rear+1;
                parent[i]=q;
                black[i]=1;
            }
        i++;}

    }
     return(black[t]==1);
}

int min(int a,int b){
    if(a>b)return b;
    else return a;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int s, int t)
{
    int u, v;
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    int rGraph[n+2][n+2]; // Residual graph where rGraph[i][j] indicates
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)
    for (u = 0; u < n+2; u++)
        for (v = 0; v < n+2; v++)
             rGraph[u][v] = capacity[u][v];

    int parent[n+2];  // This array is filled by BFS and to store path

    int max_flow = 0;  // There is no flow initially

    // Augment the flow while there is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edges along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = 99999;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    // Return the overall flow
    return max_flow;
}




int main(){
    printf("Enter the value of n: ");
    scanf("%d",&n);
    buildadj();
    //print_matrix(adj);printf("\n");
    //print_matrix(capacity);
    int maxflow=fordFulkerson(0,n+1);
    printf("Maximum Possible flow from s to t : %d\n",maxflow);





return 0;}
