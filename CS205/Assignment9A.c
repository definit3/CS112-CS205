/*NAME- VIVEK RAJ
   ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int n,i,j,k,count=0;
char houses[30][30];int c[30][30]={-1},w[30]={0};
int arr1[100]={0},arr2[100]={0},cost[30]={0},adj[30][30]={0};

int min(int a,int b){
	if(a<b)return a;
	else return b;
}

void printhouses(){
	for(i=0;i<n;i++){printf("%s\n",houses[i]);}
}

void print_matrix(int adj[][30]){    //function to print the adjacency matrix
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }}


int main(){
	printf("Enter the number of houses, N , in the city: ");
	scanf("%d",&n);
	printf("Enter the names of the owner: ");
	for(i=0;i<n;i++){
		scanf("%s",houses[i]);
		for(j=0;j<strlen(houses[i]);j++)
			{cost[i]+=((int)tolower(houses[i][j]));}

			}
	//printhouses();

	//for(k=0;k<100;k++)printf("%d  ",arr1[k]);
	printf("\n");
	for(i=0;i<n;i++){

		for(k=0;k<strlen(houses[i]);k++){arr1[((int)tolower(houses[i][k]))-97]+=1;}
		//for(k=0;k<100;k++)printf("%d  ",arr1[k]);
		for(j=0;j<n;j++){
			if(i!=j){
				for(k=0;k<strlen(houses[j]);k++){arr2[((int)tolower(houses[j][k]))-97]+=1;}
				//for(k=0;k<100;k++)printf("%d  ",arr1[k]);
				for(k=0;k<100;k++){if(arr1[k]==arr2[k])count+=arr1[k];else if(arr1[k]>0&&arr2[k]>0) count+=min(arr1[k],arr2[k]);}
				int s=strlen(houses[j]);
				//printf("count- %d : strj: %d\n",count,s);
				if(abs(strlen(houses[j])-strlen(houses[i]))==1){
					if(count+1==strlen(houses[j])||count-1==strlen(houses[j])||count==strlen(houses[j]))adj[i][j]=1;}
				else if(strlen(houses[i])==strlen(houses[j])){if(count+1==strlen(houses[j]))adj[i][j]=1;}}
				count=0;
				for(k=0;k<100;k++){arr2[k]=0;}
				}
				//printf("\n");
				count=0;
				for(k=0;k<100;k++){arr1[k]=0;arr2[k]=0;}
				}

		for(i=0;i<n;i++)
			{
			for(j=0;j<n;j++){
				if(adj[i][j]==1){c[i][j]=abs(cost[i]-cost[j]);}
				else c[i][j]=-1;}}

		for(i=0;i<n;i++){
			for(j=0;j<strlen(houses[i]);j++){
				w[i]+=(int)tolower(houses[i][j]);
			}
			w[i]/=strlen(houses[i]);
		}


    printf("Adjacency matrix of the found graph: \n");
	print_matrix(adj);
	printf("\n");
	printf("Cost of pipeline between houses i and j in matrix form: \n");
	print_matrix(c);
	//for(i=0;i<n;i++)printf("%d  ",cost[i]);
	//printf("\n");printf("\n");
	//print_matrix(c);



	}
