/*NAME- VIVEK RAJ
  ROLL-1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j,k,newadj[8][8]={0},visited[8]={0};         //declaring/initializing global variables
int minindex=0,distance=0;
int adj2[8][8]={0},adj3[8][8]={0};
int adj[8][8]={0,1366,1172,284,1137,1270,1885,520,       //initializing the weight matrix
               1366,0,1286,1560,971,325,528,1180,
                1172,1286,0,1100,383,973,1649,653,
                284,1560,1100,0,925,1415,2075,499,           //finding the distance between cities from map and constructing adjacency matrix
                1137,971,383,925,0,682,1392,423,
                1270,325,973,1415,682,0,713,973,
                1885,528,1649,2075,1392,713,0,1671,
                520,1180,653,499,423,973,1671,0};
char stadium[8][10]={"Chennai","Kolkata","Indore","Bengaluru","Nagpur","Ranchi","Guwahati","Hyderabad"};


int bfs(int v,int newadj[][8]){     //function to perform bfs
    int currmax=0;
    int black[8]={0};
    int q; //declaring int q to be used a current working vertex
    int front=0;
    int rear=0;
    int que[30]={0};   //declaring a array to be used as a queue
    black[v]=1;
    que[rear]=v;
    rear=rear+1;
    for(;rear!=front;){   //stopping condition- if the queue is empty
        q=que[front];
        printf("\n%s  ",stadium[q]);
        front=front+1;
        i=0;
        while(i<8){
            if(black[i]==0 && newadj[q][i]==1){
                que[rear]=i;
                rear=rear+1;
                black[i]=1;
            }
            if(newadj[q][i]==1)currmax+=1;
        i++;}

    }
    for(i=0;i<8;i++)black[i]=0;
     printf("\n");
}


int extractmin(int a){           //function to return the minimum distance next city
    int min=10000;
    for(i=0;i<8;i++){
        if(adj[a][i]<min && visited[i]!=1 && i!=a){min=adj[a][i];minindex=i;}}
    return minindex;

}

void print_matrix(int adj[][8]){    //function to print the adjacency matrix
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d        ",adj[i][j]);
        }
        printf("\n");}}

void cpymatrix(int newadj[][8],int adj2[][8]){       //function to copy one adj matrix to another
        int p, q;
    for(p=0;p<8;p++){
        for(q=0;q<8;q++){
            adj2[p][q]=newadj[p][q];
        }
    }

}

int main(){                  //MAIN FUNCTION
    int mindistance=10000000,index=0;
    int count=0;
   // print_matrix(adj);       //calling function print matrix

    for(k=0;k<8;k++){           //finding the efficient route
        visited[k]=1;
        j=k;
        while(count<8){
        extractmin(j);
        distance+=adj[j][minindex];
        visited[minindex]=1;
        newadj[j][minindex]=1;
        j=minindex;
        count++;}
        if(k==0)cpymatrix(newadj,adj3);
        for(j=0;j<8;j++)visited[j]=0;
       // bfs(k,newadj);printf("distance- %d\n",distance);
        if(distance<mindistance){
                mindistance=distance;
                cpymatrix(newadj,adj2);
                index=k;}
        for(i=0;i<8;i++){
            for(j=0;j<8;j++)newadj[i][j]=0;
        }

        count=0;
        distance=0;
        //print_matrix(newadj);
    }
     //  printf("\n%d\n",index);
      // printf("%d",mindistance);
       printf("Schedule should be as follows: ");        //printing the result
       bfs(0,adj3);


    return 0;}
