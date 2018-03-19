/*NAME - VIVEK RAJ
   ROLL-1601CS49
    17/08/2017*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[100];

int find_median(int arr[],int n,int imp){         //creating a function find_median to find the median of the given numbers
    int index,i,newarr1[n],newarr2[n],j=0;
    int count1=0,count2=0;
    index=rand()%n;                          //generating random index to select

    for(i=0;i<n;i++){
        if(arr[i]<=arr[index] && i!=index)count1+=1;    //counting the number lesser than and greater than the value of selected index
        else if(arr[i]>arr[index]) count2+=1;
    }

    if(imp==count1+1){printf("Median is: %d \n",arr[index]);return;}   //if the index matches the required median index, printing its value.

    for(i=0;i<n;i++){
        if(arr[i]<=arr[index] && i!=index)
        {
           newarr1[j]=arr[i];j++;     //storing the numbers lesser than the selected index in a different array
        }
    }
    j=0;
    for(i=0;i<n;i++){
        if(arr[i]>arr[index])
        {
            newarr2[j]=arr[i];j++;   //storing the numbers greater than the selected index in a different array
        }
    }

    if(imp<=count1)
        {
        for(i=0;i<count1;i++){
            arr[i]=newarr1[i];}
        find_median(arr,count1,imp);   //recursive function
      }
     else{
        for(i=0;i<count2;i++){
            arr[i]=newarr2[i];}
        imp=imp-(count1+1);
        find_median(arr,count2,imp);   //recursive function
      }

}

int main(){        //MAIN function
    int n,i,imp;
    printf("Enter the value of n: ");    //taking value of n from the user
    scanf("%d",&n);
    printf("Enter the elements of the array: ");    //taking the elements of array from the user
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     if(n%2==0)imp=n/2; else imp=(n+1)/2;   //finding the median index
    find_median(arr,n,imp);   //passing the array int eh function find _median

return 0;}
