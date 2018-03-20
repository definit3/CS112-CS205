/*NAME- VIVEK RAJ
  ROLL- 1601CS49
  01/10/2017*/

#include <stdio.h>
#include <stdlib.h>

int n,i,j,k;


void tempfun(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int ithorderstats (int arr[], int low, int high,int pivot_type)  //function to find the ith order
{
    int pivot;
    pivot=low;

    int i = low,j=high;

    for (;i<j;)
    {
       for(i;arr[i]<=arr[pivot]&&i<high;i++){}
       for(j;arr[j]>arr[pivot];j--){}
       if(i<j)tempfun(&arr[i],&arr[j]);
    }
    tempfun(&arr[j], &arr[pivot]);
    return (j);
}

void findingith(int arr[], int low, int high,int pivot_type)
{
    if (low >= high)return;
    else
    {
        int pi = ithorderstats(arr, low, high,pivot_type);
        findingith(arr, low, pi - 1,pivot_type);
        findingith(arr, pi + 1, high,pivot_type);
    }
}

void printArray(int arr[], int size)   //function to print the array
{
    int i;
    for (i=0; i < size; i++)
        printf("%d   ", arr[i]);

}

int main(){
    printf("Enter the number of elements: ");
    scanf("%d",&n);           //taking the value of n from the user
    int arr[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){scanf("%d",&arr[i]);}   //taking the elements from the user
    printf("Enter the ith smallest number to be found: ");
    int f;
    scanf("%d",&f);    //taking the value of i
    findingith(arr,0,n-1,0);
     printArray(arr,n);
    printf("\n%d th smallest number : %d",f,arr[f-1]);  //printing the ith order

return 0;}
