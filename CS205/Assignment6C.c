/*NAME-VIVEK RAJ
    1601CS49
    6C.c*/

#include <stdio.h>
#include <stdlib.h>

int n,i,k=0,l=0,j,sum=0;

int wayup1(int s1[][sum+1]){   //function wayup1 to initialize the first column of the matrix
    i=0;
    while(i<=n){
        s1[i][0]=1;
        i++;}}

int wayup2(int s1[][sum+1]){  //function wayup2 to initialize the first row of the matrix
    j=1;
    while(j<=sum){
        s1[0][j]=0;
        j++;}}

int matrixbydp(int s1[][sum+1],int set[]){  //function to create a matrix to solve by dp
    wayup1(s1);
    wayup2(s1);
    i=1;
    while(i<=n){
        j=1;
        while(j<=sum){
            s1[i][j]=s1[i-1][j];
            if(set[i-1]<=j)s1[i][j]=s1[i-1][j]||s1[i-1][j-set[i-1]];
            j++;
        }i++;}
}

int difffinder(int s1[][sum+1]){   //function to find the minimum difference between two sets
    i=sum/2;
    int diff;
    while(i>=0){
        if(s1[n][i]==1){
            diff=sum-2*i;
            break;}i--;
    }
    return diff;

}

int subsetfind(int s1[][sum+1],int set[],int subset1[],int subset2[]){   //function to find the subset 1 and subset 2;
    if(i==0&& j==0)return;
    if(s1[j-1][i]==1){j--;subset2[l]=set[j];l++;subsetfind(s1,set,subset1,subset2);}
    else {
        subset1[k]=set[j-1];
        k++;
        j--;
        i=i-set[j];
        subsetfind(s1,set,subset1,subset2);
    }
}

void printmatrix(int s1[][sum+1]){   //function to print the auxiliary dp matrix
    for(i=0;i<=n;i++){
        for(j=0;j<=sum;j++){
            printf("%d ",s1[i][j]);
        }printf("\n");}
}

int main(){
    printf("Enter the size of the set: ");
    scanf("%d",&n);    //taking the size of the set by the user
    printf("Enter the positive integers : ");
    int set[n];    //taking the elements of the set from the user
    for(i=0;i<n;i++){
        scanf("%d",&set[i]);
        sum+=set[i];
    }
    int s1[n+1][sum+1];
    matrixbydp(s1,set);    //calling function matrix by DP
    int diff=difffinder(s1);  //calling function difffinder
    int subset1[n+1],subset2[n+1];
    j=n;
    subsetfind(s1,set,subset1,subset2);
    //printmatrix(s1);
    printf("\nMinimum difference: %d\nSet 1: ",diff);  //printing minimum difference
    for(i=k-1;i>=0;i--){printf("%d ",subset1[i]);}
    printf("\nSet 2: ");
    for(i=l-1;i>=0;i--){printf("%d ",subset2[i]);}

return 0;}
