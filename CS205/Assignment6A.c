/*NAME- VIVEK RAJ
   ROLL-1601CS49
   6A.C*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int i,j,sum,n;      //declaring global variables for auxiliary uses.

int min(int a,int b){   //finding minimum of two numbers
	if(a<=b)return a;
	else return b;
}

void sort_den(int d[],int n){  //function to sort the denomination in ascending order
    int m,k,temp;
    for(m=0;m<n;m++){
        for(k=m+1;k<n;k++){
            if(d[m]>d[k]){
                temp=d[m];
                d[m]=d[k];
                d[k]=temp;}}}}


int min_coin(int denomination[],int *dencount[n]){  //function to find the minimum number of coins
	for(i=0;i<n;i++)dencount[i][0]=0;  //assigning 0th column value as 0
	for(i=0;i<n;i++){
            for(j=1;j<=sum;j++){
               dencount[i][j]=100000;
            }}
	for(j=0;j<n;j++){
        for(i=0;i<=sum;i++){
            if(i>=denomination[j])dencount[j][i]=min(dencount[j][i],dencount[j][i-denomination[j]]+1);  //finding the minimum coins required for particular value
            else if(j!=0) dencount[j][i]=dencount[j-1][i];
	}}

	if(dencount[n-1][sum]<1000)printf("Minimum coins required: %d\n",dencount[n-1][sum]);//printing the minimum no of coins required
	else printf("NOT POSSIBLE\n");  //if the given value is not possible to get, printing NOT POSSIBLE
}

int denfinder(int denomination[],int *dencount[n],int liza[n][1]){  //function to find the denominations used
    if(dencount[j][i]==dencount[j][i-denomination[j]]+1){
        liza[j][0]+=1;  //incrementing if the denomination is used more than once
        i=i-denomination[j];
        while(denomination[j]>i)j--;
        if(i==0)return;
        else denfinder(denomination,dencount,liza);  //recursion

    }
}

int main(){
	printf("Enter the number of different coins 'n': ");
	scanf("%d",&n);    //taking the  number of coins from the user
	int liza[n][1];
	for(i=0;i<n;i++)liza[i][0]=0;
	printf("Enter the values of the coins: ");
	int denomination[n];    //taking the values of coins from the user
	for(i=0;i<n;i++){scanf("%d",&denomination[i]);}
	sort_den(denomination,n);
	printf("Enter the sum S: ");
	scanf("%d",&sum);    //taking the sum from the user
	int *dencount[n];
	for(i=0;i<n;i++)dencount[i]=(int *)malloc((sum+1)*sizeof(int));
	min_coin(denomination,dencount);    //calling function min_coin to find minimum coin
	i=sum;j=n-1;
	while(denomination[j]>i)j--;
	denfinder(denomination,dencount,liza);  //calling function den finder to find minimum denomination
	  for(i=n-1;i>=0;i--){
        if(liza[i][0]>=1){
            if(liza[i][0]>1)printf("%d-> %d units\n",denomination[i],liza[i][0]);
            else    printf("%d-> %d unit\n",denomination[i],liza[i][0]);}
    }


return 0;}
