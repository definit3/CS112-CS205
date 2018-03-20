/*NAME-VIVEK RAJ
  ASSIGNMENT6B.C
  1601CS49*/

#include <stdio.h>
#include <stdlib.h>

int i,j,k=0;

int min(int x,int y,int z){    //function to find the minimum value of three integers
    if(x<=y&&x<=z)return x;
    if(y<=x&&y<=z)return y;
    if(z<=x&&z<=y)return z;
}

int wayup1(int room[][20],int temproom[][20],int r1,int c1){   //function to add the cost of all cells of row 0
    temproom[0][0]=room[0][0];
    i=1;
    while(i<=r1){
        temproom[i][0]=temproom[i-1][0]+room[i][0];
        i++;
    }
}

int wayup2(int room[][20],int temproom[][20],int r1,int c1){   //function to add the cost of all cells of column 0
    i=1;
    while(i<=c1){
        temproom[0][i]=temproom[0][i-1]+room[0][i];
        i++;
    }
}

int costfinder(int room[][20],int temproom[][20],int r1,int c1){  //function to find the cost to reach the required room
    wayup1(room,temproom,r1,c1);   //calling function wayup1
    wayup2(room,temproom,r1,c1);   //calling function wayup2
    i=1;
    while(i<=r1){
        for(j=1;j<=c1;j++){
            temproom[i][j]=min(temproom[i-1][j-1],temproom[i-1][j],temproom[i][j-1])+room[i][j];
        }i++; }
    return temproom[r1][c1];    //returning the required cost
}

int path_finder(int room[][20],int path[]){   //function to find the path traversed
    int x;
    if(j==0){x=room[i-1][j];path[k]=0;k++;i=i-1;}
    else if(i==0){x=room[i][j-1];path[k]=2;k++;j=j-1;}
    else if (1){
        x=min(room[i-1][j-1],room[i-1][j],room[i][j-1]);
        if(x==room[i-1][j-1]){path[k]=1;k++;i=i-1;j=j-1;}
        else if(x==room[i-1][j]){path[k]=0;k++;i=i-1;}
        else if(x==room[i][j-1]){path[k]=2;k++;j=j-1;}}
    if(i==0&&j==0)return;
    path_finder(room,path);
}



int main(){
    int m,n;
    int r1,c1;
    printf("Enter the number of rows: ");
    scanf("%d",&m);      //taking the no of rows from the user
    printf("Enter the number of columns: ");
    scanf("%d",&n);      //taking the no of columns from the user
    int room[m][20],temproom[m][20];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
              printf("Enter the cost of the room of index (%d,%d): ",i,j);
              scanf("%d",&room[i][j]);     //taking the cost of each room from the user
        }
    }

    r1=m-1;c1=n-1;
    int min_cost=costfinder(room,temproom,r1,c1);   //storing the cost required in a variable min_cost
    printf("Total minimum cost: %d\n",min_cost);
    i=m-1;j=n-1;
    int path[20]={1000};
    path_finder(temproom,path);   //calling function path finder
    printf("No of moves required: %d\n",k);
    for(j=k-1;j>=0;j--)
    {
        if(path[j]==1)printf("DIAGONAL ");    //loop that prints required steps
        else if(path[j]==0)printf("DOWNWARD ");
        else if(path[j]==2)printf("RIGHTWARD ");
    }


return 0;}
