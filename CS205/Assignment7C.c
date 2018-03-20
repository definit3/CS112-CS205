
/*NAME- VIVEK RAJ
   1601CS49*/
#include <stdio.h>
#include <stdlib.h>

int i,j;

void printdp(int n,int dp[5][n+1]){   //function to print the matrix dp
	for(i=0;i<5;i++){
		for(j=0;j<=n;j++){
			printf("%d   ",dp[i][j]);
		}
		printf("\n");}}

int min(int a,int b,int c){    //function to calculate the minimum of three numbers
	if(a<=b && a<=c)return a;
	else if(b<=a && b<=c)return b;
	else if(c<=a && c<=b)return c;
}

int minstep(int n){    //function to calculate the min steps required
	int dp[5][n+1];
	int d[]={1,7,5,3,2};

	for(i=0;i<5;i++){
		for(j=0;j<=n;j++){
			if(j==1||j==0)dp[i][j]=0;
			else dp[i][j]=100000;
		}
	}

	for(j=2;j<=n;j++)dp[0][j]=j-1;

	for(i=1;i<5;i++){
		for(j=2;j<=n;j++){
			if(j%d[i]==0){
				dp[i][j]=min(dp[i][j/d[i]]+1,dp[i-1][j],dp[i][j]);
			}
			else if(j>=d[i]) {dp[i][j]=min(dp[i][j-1]+1,dp[i-1][j],dp[i][j]);}
			else dp[i][j]=dp[i-1][j];
		}
	}
	//printdp(n,dp);
	return dp[4][n];


}



int main(){    //main function
	int n;
	printf("Enter the value of n: ");    //taking value of n from the user
	scanf("%d",&n);
	if(n<=0){printf("Enter number greater than 0! \n");return 0;}
	printf("\nMinimum steps required: %d\n",minstep(n));   //printing the min steps required


return 0;}
