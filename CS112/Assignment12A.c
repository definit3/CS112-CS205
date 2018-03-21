/*NAME- VIVEK RAJ
  ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i,j,k,l,n,N,adj[200][200]={0};
char company[20][30]={
"Microsoft", "Google","Adobe", "Mentor Graphics", "Synopsis", "IBM",
"Wipro", "TCS", "CTS", "Goldman", "Infosys",
"Cadence", "Texas Instrument", "DRDO", "HAL", "ISRO", "Capgemini", "Ushacomm",
"Ericson"};
char student[100][30];


void print_matrix(){    //function to print the adjacency matrix
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%d  ",adj[i][j]);
        }
        printf("\n");
    }}

void adjbuild(){
    int count=0;
    int m=0;
	int arr[100]={0};
	for(i=0;i<20;i++){
        count=0;
		for(j=0;j<strlen(company[i]);j++){
			for(k=0;k<n;k++){
				for(l=0;l<strlen(student[k]);l++)
                {
                    if(company[i][j]==student[k][l] && arr[l]==0){count+=1;arr[l]=1;}
				}
				if(count>=2)adj[k+1][n+1+i]=1;
				count=0;
				for(m=0;m<100;m++)arr[m]=0;
			}
		}
	}


}

int main(){
	printf("Enter the number of students: ");
	scanf("%d",&n);
	printf("Enter the names of the students: ");
	for(i=0;i<n;i++){
		scanf("%s",student[i]);
	}

	N=21+n;
	for(i=1;i<=n;i++)adj[0][i]=1;
	for(i=n+1;i<N-1;i++)adj[N-1][i]=1;
	adjbuild();
	print_matrix();





return 0;}
