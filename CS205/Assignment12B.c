/*NAME- VIVEK RAJ
  ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j,k,l,n,N=71,adj[100][100]={0},capacity[100][100]={0};   //declaring few auxiliary variables
char city[72][30]={             //assigning the city names in the array company
"mumbai", "delhi","bangalore", "hyderabad", "ahmedabad", "chennai", "kolkata", "surat",
"pune", "jaipur", "lucknow", "kanpur", "nagpur", "visakhapatnam", "indore", "thane", "bhopal", "patna",
"vadodara", "ghaziabad", "ludhiana", "coimbatore", "agra", "madurai", "nashik", "faridabad", "meerut",
"rajkot", "varanasi", "srinagar", "aurangabad", "dhanbad"," amritsar", "navimumbai", "allahabad",
"ranchi", "howrah", "jabalpur", "gwalior", "vijayawada", "jodhpur", "raipur", "kota", "guwahati",
"chandigarh", "thiruvananthapuram", "solapur", "tiruchirappalli", "bareilly", "moradabad", "mysore",
"tiruppur", "gurgaon", "aligarh", "jalandhar", "bhubaneswar", "salem", "warangal", "guntur", "bhiwandi",
"saharanpur", "gorakhpur", "bikaner", "amravati", "noida", "jamshedpur", "bhilai", "cuttack", "firozabad",
"kochi", "goa"};


void print_matrix(int a[][100]){    //function to print the adjacency matrix
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
    }}

void adjbuild(){          //function to build the adjacency matrix needed
    int count=0;
    int m=0;
	int arr[100]={0};
	for(k=0;k<N;k++){
        count=0;
        for(i=0;i<N;i++){
            if(k!=i){
            for(l=0;l<strlen(city[k]);l++)
            {
                for(j=0;j<strlen(city[i]);j++){

                    if(city[i][j]==city[k][l] && arr[j]==0){count+=1;arr[j]=1;break;}
				}

			}
				if(count>=1 && (strlen(city[k])-strlen(city[i]))==1){adj[i][k]=1;capacity[i][k]=2*count;}
				count=0;
				for(m=0;m<100;m++)arr[m]=0;
		}
        }
	}

}

void add_adj_constraint(){       //building adj matrix
    int counter=0;
    for(i=0;i<N;i++){
        if(i!=70){
        for(j=0;j<N;j++){
            if(adj[j][i]>0){counter=1;break;}
        }
        if(counter==0){adj[70][i]=1;capacity[70][i]=20;}
        counter=0;
    }}
    counter=0;
    for(i=0;i<N;i++){
        if(i!=45){
        for(j=0;j<N;j++){
            if(adj[i][j]>0){counter=1;break;}
        }
        if(counter==0){adj[i][45]=1;capacity[i][45]=20;}
        counter=0;
    }}
}

int flowfind(int newadj[][N],int s,int t,int parent[]){

    int black[1000]={0};
    for(i=0;i<1000;i++)black[i]=0;
    int q; //declaring int q to be used a current working vertex
    int front=0;
    int rear=0;
    int queue[1000]={0};   //declaring a array to be used as a queue
    for(i=0;i<1000;i++){queue[i]=0;}
    black[s]=1;
    parent[s]=-1;
    queue[rear]=s;
    rear=rear+1;
    for(;rear!=front;){   //stopping condition- if the queue is empty
        q=queue[front];
       //printf("\n%d  ",q);
        front=front+1;
        i=0;
        while(i<N){
            if(black[i]==0 && newadj[q][i]>0){
                queue[rear]=i;
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
             g[u][v] = capacity[u][v];
}

int MaxFlow(int s, int t)                           //function to find the maximum flow
{
    int u, v;
    int auxGraph[N][N];
    cpymatrix(auxGraph);
    int parent[N];
    for(i=0;i<N;i++)parent[i]=-1;
    int maximumTraffic = 0;

    for (;flowfind(auxGraph, s, t, parent)==1;)
    {
        int m;

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
        for(i=0;i<N;i++)parent[i]=-1;
    }
    return maximumTraffic;   //returning maximum flow
}




int main(){
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){adj[i][j]=0;capacity[i][j]=0;}      //initializing adjacency matrix and cost matrix to 0
    }
    adjbuild();         //building the adjacency and cost matrix by required constraint
    add_adj_constraint();     //modifying the adjacency and cost matrix for handling exceptional case of Goa and Thiruvananthapuram
    // print_matrix(adj);   //UNCOMMENT THIS TO PRINT ADJACENCY MATRIX
   // print_matrix(capacity);    //UNCOMMENT THIS TO PRINT COST MATRIX
    int s=70,t=45;
    printf("\nMaximum Flow: %d\n",MaxFlow(s,t));



return 0;}




