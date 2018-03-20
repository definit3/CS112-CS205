/*NAME- VIVEK RAJ
  ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j,k,l,n,N,adj[200][200]={0};   //declaring few auxiliary variables
char company[20][30]={             //assigning the company names in the array company
"microsoft", "google","adobe", "mentorgraphics", "synopsis", "ibm",
"wipro", "tcs", "cts", "goldman", "infosys",
"cadence", "texasinstrument", "drdo", "hal", "isro", "capgemini", "ushacomm",
"ericson"};
char student[100][30];


void print_matrix(){    //function to print the adjacency matrix
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }}

void adjbuild(){          //function to build the adjacency matrix needed
    int count=0;
    int m=0;
	int arr[100]={0};
	for(k=0;k<n;k++){
        count=0;
        for(i=0;i<19;i++){
            for(l=0;l<strlen(student[k]);l++)
            {
                for(j=0;j<strlen(company[i]);j++){

                    if(company[i][j]==student[k][l] && arr[j]==0){count+=1;arr[j]=1;break;}
				}

			}
			//printf("COUNT: %d\n",count);
				if(count>=2)adj[k+1][n+1+i]=1;
				count=0;
				for(m=0;m<100;m++)arr[m]=0;
		}
	}


}

int bfs(int newadj[][N],int s,int t,int parent[]){     //function to perform BFS

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
       //printf("\n%d  ",q);
        front=front+1;
        i=0;
        while(i<N){
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

void cpymatrix(int g[][N]){   //function to copy one matrix to another
    int u,v;
    for (u = 0; u < N; u++)
        for (v = 0; v < N; v++)
             g[u][v] = adj[u][v];
}

int MaxFlow(int s, int t)                           //function to find the maximum flow using ford-fulkerson algorithm
{
    int u, v;
    int auxGraph[N][N];
    cpymatrix(auxGraph);
    int parent[N];
    for(i=0;i<N;i++)parent[i]=-1;
    int maximumTraffic = 0;

    for (;bfs(auxGraph, s, t, parent)==1;)              //running the loop till no more augmented path is left
    {
        int m;
        //printf("Parent: ");
        //for(m=0;m<N;m++)printf("%d ",parent[m]);
        //printf("\n");

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
        if(parent[t]!=-1&&parent[parent[t]]!=-1)
        printf("\nCompany \"%s\" will hire \"%s.\"",company[parent[t]-1-n],student[parent[parent[t]]-1]);
        for(i=0;i<N;i++)parent[i]=-1;
    }
    return maximumTraffic;   //returning maximum flow
}



int main(){                     //MAIN FUNCTION
	printf("Enter the number of students: ");
	scanf("%d",&n);                                                     //TAKING NUMBER OF STUDENTS FROM THE USER
	printf("Enter the names in small letter only! \n");

	for(i=0;i<n;i++){
        printf("Enter the names of the student %d: ",i+1);         //TAKING THE NAMES OF THE STUDENTS FROM THE USER
		scanf("%s",student[i]);
	}

	N=21+n;
	for(i=1;i<=n;i++)adj[0][i]=1;
	for(i=n+1;i<N-1;i++)adj[i][N-1]=1;     //CONNECTING SOURCE TO STUDENTS AND SINK TO COMPANY
	adjbuild();
	//print_matrix();

	int maxflow=MaxFlow(0,N-1);    //calling function max flow
    printf("\nMaximum number of placements: %d\n",maxflow);   //printing max flow



return 0;}
