/*NAME- VIVEK RAJ
  ROLL= 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char locality[100][15]={"Kullu","Manali","Kumaon","Darjeeling","Sikkim","Nainital","Shimla","Mussoorie","Almora","Chamba","Badrinath","Ranikhet",
                        "Gulmarg","Dalhousie","Lansdowne","Auli"
,"Gangtok","Along", "Bomdila", "Itanagar", "Khonsa", "Roing", "Tawang", "Ziro", "Haflong", "Hamren",
"Jatinga", "Maibang", "Umrangso", "Chirmiri", "Mainpat", "Baijnath", "Barog", "Chail", "Chitkul",
"Churdhar", "Dharamkot", "Dharamshala", "Haripurdhar", "Jogindernagar", "Kalpa", "Kangra", "Kasauli",
"Keylong", "Khajjiar", "Kiarighat", "Kotla", "Kufri", "Mashobra", "Palampur", "Rajgarh",
"Rewalsar", "Sangla", "Sarahan", "Solan", "Sundar", "Triund"};
int adj[100][100]={0},slopematrix[100][100]={0},costmatrix[100][100]={-1};
int i,j,k,n=57,p,q,r;
int distance[100],pred[100];
int visited[100],count,mindistance,nextvertex;

void print_matrix(int matrix[][100]){    //function to print the adjacency matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",matrix[i][j]);
        }
        printf("\n");}
    }

void print_locality(){          //function to print the name of the localities
 for(i=0;i<n;i++){
        printf("%s  ",locality[i]);
        printf("\n");}
    }


void findslope(){           //function to find the slope of the road
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            slopematrix[i][j]=strlen(locality[i])-strlen(locality[j]);
        }
    }
}

void findneighbourcond(){        //function to find the neighbour locality
    int count=0;
    int l1=strlen(locality[i]),l2=strlen(locality[j]);
    int arr[15]={0};
    for(p=0;p<l1;p++)
        for(q=0;q<l2;q++)
            if(locality[i][p]==locality[j][q] && arr[q]!=1){
                    arr[q]=1;count+=1;break;}
    if((slopematrix[i][j]==1||slopematrix[i][j]==-1)&&count>=1)adj[i][j]=1;
    else if((slopematrix[i][j]==2||slopematrix[i][j]==-2)&&count>=2)adj[i][j]=1;
    count=0;
}

void findneighbour(){           //function to find the neighbour locality
    int count=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j){
            if(slopematrix[i][j]==0)adj[i][j]=1;
            else if(slopematrix[i][j]==1||slopematrix[i][j]==-1||slopematrix[i][j]==2||slopematrix[i][j]==-2)
                {
                    findneighbourcond();
                }
                count=0;}}
    }
}

int min(int a, int b){     //function to find the minimum of two numbers
    if(a>b)return b;
    else return a;
}
int max(int a, int b){     //function to find the maximum of two numbers
    if(a>b)return a;
    else return b;
}

void finddistance(){    //function to find the distance between  neighbouring localities
    int mm=0,nn=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)costmatrix[i][j]=0;
            else if(adj[i][j]>0){
                mm=min(strlen(locality[i]),strlen(locality[j]));
                nn=max(strlen(locality[i]),strlen(locality[j]));
                for(k=0;k<mm;k++){
                    costmatrix[i][j]+=abs(locality[i][k]-locality[j][k]);}
                if(nn==strlen(locality[i])){
                    for(k;k<nn;k++)costmatrix[i][j]+=locality[i][k];}
                else if(nn==strlen(locality[j])){
                    for(k;k<nn;k++)costmatrix[i][j]+=locality[j][k];}
            }
            else costmatrix[i][j]=99999;
        }
    }
}

void dijkaux(){        //function to find the shortest path between home and office using dijkstra
     while(count<n-1)
    {
        mindistance=99999;
        i=0;
        while(i<n){
            if(distance[i]<mindistance&&visited[i]==0)
            {
                mindistance=distance[i];
                nextvertex=i;
            } i++;}

            visited[nextvertex]=1;
            i=0;
            while(i<n){
                if(visited[i]==0)
                    if(mindistance+costmatrix[nextvertex][i]<distance[i])
                    {
                        distance[i]=mindistance+costmatrix[nextvertex][i];
                        pred[i]=nextvertex;
                    }i++;}
        count++;
    }

}


void dijkstra(int home,int office)        //function to find the shortest path between home and office using dijkstra
{
    printf("Home: %s\n",locality[home]);
    printf("Office: %s\n",locality[office]);

    for(i=0;i<n;i++)
    {
        distance[i]=costmatrix[home][i];
        pred[i]=home;
        visited[i]=0;
    }

    distance[home]=0;
    visited[home]=1;
    count=1;

    dijkaux();

    if(distance[office]==99999){printf("No path exists!\n");return ;}
    printf("\nShortest distance: %d",distance[office]);


    i=office;
   // printf("\nPath = %s ",locality[i]);
    j=office;
    int path[n],i=0;
    do
    {   j=pred[j];
        if(j!=home){path[i]=j;i++;}
        //printf("<- %s",locality[j]);
    }while(j!=home);
    printf("\n");
    printf("Path = %s -> ",locality[home]);
    for(j=i-1;j>=0;j--){printf("%s -> ",locality[path[j]]);}
    printf("%s ",locality[office]);


}

void removenegative(){    //function to remove the negative slope from adj matrix
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(slopematrix[i][j]<0){
                adj[i][j]=0;
            }
}



int main(){
    //print_locality();
    findslope();                                 //Finding the slope of the roads
    findneighbour();                             //finding the locality neighbours
    //print_matrix(slopematrix);
    //printf("\n");print_matrix(adj);
    removenegative();                             //Removing the negative slopes
    //printf("\n");print_matrix(adj);
    finddistance();                                //Finding the distance between neighbours
    //printf("\n");print_matrix(costmatrix);
    dijkstra(3,9);                                 //Applying dijkstra



return 0;}
