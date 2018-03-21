#include <stdio.h>
#include <stdlib.h>

int i,j,k,l,n,x;
int black[30]={0};

void print_matrix(int adj[][n]){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }

}

void dfs(int vertex,int adj[][n]){
    printf("%d ",vertex);
    black[vertex]=1;
    for(i=0;i<n;i++)
        {   if(adj[vertex][i]==1 && black[i]==1)x=1;
            if(black[i]!=1&&adj[vertex][i]==1)dfs(i,adj);}


}

int main(){

    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the 5 characters words: ");
    char words[n][6];
    for(i=0;i<n;i++){scanf("%s",words[i]);}
    //for(i=0;i<n;i++){printf("%s\n",words[i]);}
    int adj[n][n];
    for(i=0;i<n;i++){for(j=0;j<n;j++)adj[i][j]=0;}
    int count=0;
    int arr[5]={1000};
    int m=0;
    int counter=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
            for(k=1;k<5;k++){
                for(l=0;l<5;l++){
                if(words[i][k]==words[j][l]){
                        for(x=0;x<m;x++){if(arr[x]==l)counter=1;}
                        if(counter!=1){arr[m]=l;m++;count+=1;break;}
                        else counter=0;}
                }
            }
            if(count==4)adj[i][j]=1;
            count=0;m=0;for(x=0;x<5;x++)arr[x]=10000;
        }
    }}
    x=0;
    dfs(0,adj);
    if(x==1)printf("\nGRAPH IS CYCLIC! ");
    else printf("\nGraph is Acyclic! ");

    while(1){
    printf("\nEnter the value of i j: index of nodes to check for the path: ");
    scanf("%d %d",&i,&j);
    if(adj[i][j]==1)printf("Yes , there is a path from node index %d to %d\n",i,j);
    else printf("No, there is no path from node index %d to %d\n",i,j);
    printf("\n");
    print_matrix(adj);
    printf("\n");
    printf("Do you want to find  path between another pair of nodes:(Enter 1 for yes , 0 to exit): ");
    int choice;
    scanf("%d",&choice);
    if(choice==0)return 0;
    else continue;}






return 0;}
