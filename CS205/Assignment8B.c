/*NAME-VIVEK RAJ
   ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>

int i,j,k,l,n,x;     //initializing global variables
int black[30]={0};
int counter=0;

void print_matrix(int adj[][n]){    //function to print the adjacency matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }}


void removeleafnode(int adj[][n],int y){    //function to remove the leaf node of  the graph
    for(i=0;i<n;i++){
        adj[i][y]=0;
        adj[y][i]=0;
    }

}

void  cyclic(int adj[][n]){   //function to check which leaf node has to be removed for checking cyclicity
    int count=0,counter=0,flag=0;
    while(1){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adj[i][j]==1){count=1;break;}   //if the whole row is 0 then taking its index
            }
        if(count==0 && black[i]==0){flag=1;break;}
        else count=0;
    }

    if(flag==0){break;}
    else if(flag==1)
        {   black[i]=1;
            removeleafnode(adj,i);}   //removing that index node from the graph
    flag=0;

   }
}

void checkcyclic(int adj[][n]){   //function to check the cylicity
    int flag=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adj[i][j]==1){flag=1;break;}
        }
    }
    if(flag==0)printf("\nGraph is Acyclic! \n");
    else printf("\nGraph is Cyclic! \n");

}



int main(){            //MAIN FUNCTION

    printf("Enter the number of nodes: ");                      //TAKING THE NUMBER OF NODES FROM THE USER
    scanf("%d",&n);
    printf("Enter the 5 characters %d words: ",n);         //TAKING THE 5 CHARACTER WORDS FROM THE USER
    char words[n][6];
    for(i=0;i<n;i++){scanf("%s",words[i]);}
    //for(i=0;i<n;i++){printf("%s\n",words[i]);}
    int adj[n][n];                     //DECLARING A ADJ MATRIX
    for(i=0;i<n;i++){for(j=0;j<n;j++)adj[i][j]=0;}     //INITIALIZING THE ADJ MATRIX
    int count=0;
    int arr[5]={1000};
    int m=0;
    int counter=0;                             //FILLING UP THE ADJ MATRIX ACC TO GIVEN CONDITION
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

    cyclic(adj);   //CHECKING CYCLICITY
    checkcyclic(adj);

    //FINDING PATH BETWEEN NODES
    while(1){
    printf("\nEnter the value of i j: index of nodes to check for the path: ");
    scanf("%d %d",&i,&j);
    if(adj[i][j]==1)printf("Yes , there is a path from node index %d to %d\n",i,j);
    else printf("No, there is no path from node index %d to %d\n",i,j);
    printf("\n");
    print_matrix(adj);
    printf("\n");
    printf("Do you want to check path between another pair of nodes:(Enter 1 for yes , 0 to exit): ");
    int choice;
    scanf("%d",&choice);
    if(choice==0)return 0;
    else continue;}






return 0;}
