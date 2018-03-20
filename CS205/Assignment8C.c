/*NAME- VIVEK RAJ
  ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>

int n,m,i,j,k;
int black[30]={0};
int max=0,currmax=0;

int bfs(int v,int adj[][30]){     //function to perform bfs
    currmax=0;
    int q; //declaring int q to be used a current working vertex
    int front=0;
    int rear=0;
    int que[30]={0};   //declaring a array to be used as a queue
    black[v]=1;
    que[rear]=v;
    rear=rear+1;
    for(;rear!=front;){   //stopping condition- if the queue is empty
        q=que[front];
        front=front+1;
        i=0;
        while(i<n){
            if(black[i]==0 && adj[q][i]==1){
                que[rear]=i;
                rear=rear+1;
                black[i]=1;
            }
            if(adj[q][i]==1)currmax+=1;
        i++;}

    }

}

void print_matrix(int adj[][30]){   //function to print the adjacency matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }

}

int main(){
    printf("Enter the number of vertices: ");   //taking no of vertices from the user
    scanf("%d",&n);
    printf("Enter the number of edges: ");   //taking no of edges from the user
    scanf("%d",&m);
    int adj[30][30];
    for(i=0;i<n;i++){for(j=0;j<n;j++){adj[i][j]=0;}}
    printf("Enter the index pairs of vertices between which there is an edge(e.g. 0 1): ");   //taking connected pairs of vertices from the user
    int x,y;
    for(i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        adj[x][y]=1;adj[y][x]=1;
    }
    //print_matrix(adj);
    printf("\n");
    for(j=0;j<n;j++){
        if(black[j]==0){bfs(j,adj);if(max<currmax){max=currmax;}}
    }

    printf("Maximum no edges in any connected components : %d\n",max/2);  //printing max connected edges




return 0;}
