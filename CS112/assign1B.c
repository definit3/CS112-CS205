
/*NAME -VIVEK RAJ
        1601cs49
        1/08/2017*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MAX(int a, int b){
    if(a>b) return a; else return b;    //function to find the maximum of two digits
}

int maxchocolates(int n,int arr[]){    //function to find the required maximum chocolates
    int inclusive = arr[1];             //defining inclusive and exclusive to find the maximum value upto that sub array
    int exclusive = 0,j;int new1;
    for(j=2;j<=n;j++){
        new1=MAX(inclusive,exclusive);
        inclusive=exclusive+arr[j];
        exclusive=new1;
    }
    return MAX(inclusive,exclusive); //returning the maximum number of chocolates

}

int LargeDigit(int n){           //function to find the largest digit of a given number using recursion
    if(n==0)
        return 0;
    return MAX(n%10, LargeDigit(n/10));

}


int main(){

    int n, i,arr[100],max;
    scanf("%d",&n);           //taking number of boxes from the user
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);   //taking number of chocolates in each boxes from the user
    }
    max=maxchocolates(n,arr);  //finding the maximum number of chocolates in accordance to the required condition
    printf("%d",max);           //printing the maximum number of chocolates
    printf("\n%d",LargeDigit(max));  //printing the largest digit of the given maximum number

    return 0;}
