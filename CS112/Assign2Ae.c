/*NAME - VIVEK RAJ
  ROLL- 1601CS49
  DATE- 07/08/2017*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int d=0,sem=0;

int sum(int n){                       //function to find the sum of digits
	if(n<0){printf("Enter the number greater than 0! ");return 0;}
	d=n%10;                             //finding the last digit of the number
	sem+=d;                             //taking sum of the digits
	n=n/10;                             //removing the last digit from the number
	if(n==0){
            printf("%d",sem);
            if(sem>=10){n=sem;sem=0;printf(" -> ");sum(n);}
            else if(sem<10)return 0;}
	else sum(n);                        //calling the function itself
}


int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);                     //taking value of n from the user
	sum(n);                             //passing the value of n to the function sum

return 0;}

