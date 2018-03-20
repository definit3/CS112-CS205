/*NAME- VIVEK RAJ
   ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ENTER THE NAMES IN SMALL LETTER ONLY

int i,j,k,l,n,d,count=0;
int asc[10000],adj[10000][10000]={0};

void print_matrix(){    //function to print the adjacency matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }}

void concheck(){       //function to check the conditions of who can access whose account
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(adj[i][j]>=1){
                if(adj[i][j]<d && asc[i]>asc[j]){}
                else adj[i][j]=0;
            }
        }
    }}

int discalc(char stud[n][6]){
      for(i=0;i<n;i++){               //calculating d and storing it into adj
        for(j=0;j<n;j++){
            if(adj[i][j]>=1){
                adj[i][j]=0;
                for(k=0;k<5;k++){
                    adj[i][j]+=abs(stud[i][k]-stud[j][k]);
            }}}
    }

}


void finalcon(){
    int count=0;
    k=i;
    while(1){
        for(j=0;j<n;j++){
            if(adj[k][j]>=1){
                count=1;
                if(k!=i)adj[i][j]=1;
                k=j;
                break;
                }
        }
        if(count!=1)break;
        count=0;
    }
}


int main(){
    printf("Enter the number of students: ");
    scanf("%d",&n);         //taking no of student from the user
    char stud[n][6];
    for(i=0;i<n;i++){
        printf("Enter the name of student %d: ",i+1);
        scanf("%s",stud[i]);       //taking name of the student from the user
    }
    printf("Enter the thresold distance, d: ");
    scanf("%d",&d);

    for(i=0;i<n;i++){        //calculating |X| and storing it into asc
        for(j=0;j<5;j++){
            asc[i]+=(int)stud[i][j];
        }}
    count=0;

    for(i=0;i<n;i++){      //checking if 4 posi is matching
        for(j=0;j<n;j++){
            for(k=0;k<5;k++){
                if(i!=j){
                if(stud[i][k]==stud[j][k])count+=1;}}
                if(count>=4)adj[i][j]=1;
                count=0;}}
    discalc(stud);


   // printf("\n");
   // print_matrix();

    //for(i=0;i<n;i++){printf("%d  ",asc[i]);}


     concheck();
   // printf("\n");
   // print_matrix();
    for(i=0;i<8;i++)finalcon();
   // printf("\n");
   // print_matrix();
    int count=0;
    for(i=0;i<n;i++){
            count=0;
        for(j=0;j<n;j++){
            if(adj[i][j]>0){
                if(count!=1)
                    printf("%s can access account of: ",stud[i]);          //printing who can access whose account
                    count=1;
                    printf("%s  ",stud[j]);}
        }
       if(count==1) printf("\n");
    }



return 0;}
