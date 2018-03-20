/*NAME- VIVEK RAJ
  ROLL 1601CS49*/

#include <stdio.h>
#include <stdlib.h>

int i,j,k,n;          //declaring auxiliary global variables
int adj[1000][1000]={0},capacity[1000][1000]={0};       //declaring adjacency and cost matrix global variables and initializing it

void print_matrix(int adjj[][1000]){    //function to print the adjacency matrix
    for(i=0;i<=n+1;i++){
        for(j=0;j<=n+1;j++){
            printf("%d  ",adjj[i][j]);
        }
        printf("\n");}
    }

void buildadj(){   //function to build adjacency and cost matrix
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



int bfs(int newadj[][n+2],int s,int t,int parent[]){     //function to perform BFS

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

int min(int a,int b){     //function to return the min value from two integers
    if(a>b)return b;
    else return a;
}

void cpymatrix(int g[][n+2]){   //function to copy one matrix to another
    int u,v;
    for (u = 0; u < n+2; u++)
        for (v = 0; v < n+2; v++)
             g[u][v] = capacity[u][v];
}

int MaxFlow(int s, int t)                           //function to find the maximum flow using ford-fulkerson algorithm
{
    int u, v;
    int auxGraph[n+2][n+2];
    cpymatrix(auxGraph);
    int parent[n+2];
    int maximumTraffic = 0;

    for (;bfs(auxGraph, s, t, parent)==1;)              //running the loop till no more augmented path is left
    {

        int path_flow = 99999;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, auxGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            auxGraph[u][v] -= path_flow;
            auxGraph[v][u] += path_flow;
        }


        maximumTraffic += path_flow;
    }


    return maximumTraffic;   //returning maximum flow
}




int main(){
    printf("Enter the value of n: ");     //taking the value of n from the user
    scanf("%d",&n);
    buildadj();          //building adjacency matrix and cost matrix
    int maxflow=MaxFlow(0,n+1);    //calling function max flow
    printf("Maximum Possible flow from s to t : %d\n",maxflow);   //printing max flow



return 0;}
