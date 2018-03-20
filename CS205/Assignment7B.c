/*NAME - VIVEK RAJ
   ROLL-1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n,i,j,m,k;

struct pairmaker{
    int a;
    int b;
};

void printpairs(struct pairmaker p[]){
    for(i=0;i<k;i++){
        printf("%d,%d     ",p[i].a,p[i].b);
    }
}


void pairs(struct pairmaker p[],int arr[]){
    k=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i!=j && abs(arr[i]-arr[j])<=m)
                {p[k].a=arr[i];p[k].b=arr[j];k++;}
        }}}


int main(){

printf("Enter the number of elements: ");
scanf("%d",&n);
int arr[n];
printf("Enter the elements: ");
for(i=0;i<n;i++)scanf("%d",&arr[i]);
printf("Enter the value of 'm': ");
scanf("%d",&m);
struct pairmaker p[n*n];
pairs(p,arr);
printf("Set of valid pairs are:\n");
printpairs(p);
int arr2[n];
for(i=0;i<n;i++)arr2[i]=-1000;



return 0;}
