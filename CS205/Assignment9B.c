/*NAME- VIVEK RAJ
   ROLL - 1601CS49*/

#include <stdio.h>
#include <stdlib.h>

int i,j,k,v,e,m,n,count;
float r;
float adj[50][50]={0},cost[50][50]={0};          //declaring global variables


void print_matrix(){   //function to print the adjacency matrix
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            printf("%.1f  ",adj[i][j]);
        }
        printf("\n");}}

void costcalc(){                 //function to initialize a matrix
    for(i=0;i < v;i++)
		for(j=0;j < v;j++)
			if(adj[i][j]==0)
				cost[i][j]=10000;
			else
				cost[i][j]=adj[i][j];
}




int dijkstra()       //function to find the required information
{
	float distance[30], pred[30];
	int visited[30]={0};
	float minlength; int postV;

	costcalc();


    i=0;
	while(i< v)
	{
		distance[i]=cost[m][i];
		pred[i]=m;
		i++;
	}
	//distance[m]=0;
	visited[m]=1;
	for(count=1;count < v-1;count++){
		minlength=10000;
		i=0;
		while(i < v){
			if(distance[i] < minlength&& visited[i]==0)
			{
				minlength=distance[i];
				postV=i;
			}i++;}
		visited[postV]=1;
		for(i=0;i < v;i++)
			if(visited[i]==0)
				if(minlength+cost[postV][i] < distance[i])
				{
					distance[i]=minlength+cost[postV][i];
					pred[i]=postV;
				}
	}
            int arr[30]={0};
			j=n;
			arr[0]=n;i=1;
			do
			{
				j=pred[j];
				arr[i]=j;i++;
				//printf(" <-%d", j);
			}
			while(j!=m);
            printf("\nMost reliable path between %d and %d:  ",m,n);
			for(j=i-1;j>=0;j--){printf("%d",arr[j]);if(j!=0)printf("-> ");}
                printf("\n");
}

int main(){

    printf("Enter the number of vertices: ");           //taking no of vertices from the user
    scanf("%d",&v);
    printf("Enter the number of edges: ");              //taking no of edges from the user
    scanf("%d",&e);
    for(i=0;i<e;i++){
        printf("Enter the pairs of vertices index between which there is an edge(e.g. 0 1): ");
        scanf("%d %d",&j,&k);
        printf("Enter the value of r of this edge(0 <= r(u,v) <= 1):  ");
        scanf("%f",&r);
        adj[j][k]=1-r;}
    printf("\nEnter the index of two vertices between which path has to be found: ");
    scanf("%d %d",&m,&n);      //taking the index of vertices between which path has to be found
    dijkstra();


return 0;}
