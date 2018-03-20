/*NAME- VIVEK RAJ
   ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int i,j,k,n,e;
float adj[30][30]={0},d;

void print_matrix(float adj[][30]){    //function to print the adjacency matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%.1f  ",adj[i][j]);
        }
        printf("\n");
    }}

int main(){

    printf("Enter the number of localities: ");
    scanf("%d",&n);
    printf("Enter the number of edges(pairs of localities which are connected): ");
    scanf("%d",&e);
    for(i=0;i<e;i++){
        printf("Enter the index of pairs of vertex which are connected: ");
        scanf("%d %d",&j,&k);
        printf("Enter the distance between %d and %d locality: ",j,k);
        scanf("%f",&d);
        adj[j][k]=d;
        printf("Enter the traffic between %d and %d locality(.5<=traffic<=2): ",j,k);
        scanf("%f",&d);
        adj[j][k]*=d;
        printf("\n");
    }
    printf("Time taken to reach between localities in matrix form: \n");
    print_matrix(adj);




return 0;}
