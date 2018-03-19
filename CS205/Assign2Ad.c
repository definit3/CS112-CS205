/*NAME - VIVEK RAJ
  ROLL - 1601CS49
  13/08/2017*/

#include <stdio.h>
#include <stdlib.h>

int routine(int arr[],int initial,int maximum,int n){  //creating a function routine to sort using recursive min max
    int i,max,min,k,l,temp;
    max=0;min=10;
    for(i=initial;i<=maximum;i++){              //finding the max and min value for i th recursion
        if(arr[i]>max){max=arr[i];k=i;}
        if(arr[i]<min){min=arr[i];l=i;}
    }

    if(arr[maximum]!=max){temp=arr[maximum];arr[maximum]=max;arr[k]=temp;}   //placing the min and max to initial and highest index respectively
    if(arr[initial]!=min){temp=arr[initial];arr[initial]=min;arr[l]=temp;}
    if(maximum-initial<=1)return;   //base condition
    else routine(arr,initial+1,maximum-1,n);

}

int main(){

    int n,i;
    printf("Enter the size n: ");    //taking value of n from the user
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers: ");   //taking the numbers from the user
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    routine(arr,0,n-1,n);
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);   //printing the sorted numbers
    }

return 0;}
