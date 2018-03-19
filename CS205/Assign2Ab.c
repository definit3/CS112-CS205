/*NAME - VIVEK RAJ
  ROLL- 1601CS49
  DATE- 07/08/2017*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int largest=0,smallest=10;

int largesmall(long long int n){      //function to find the largest and smallest digit in a given number
	int x;
	if(n<0)n=-n;
	if(n<10){
		if(n>largest)largest=n;
		if(n<smallest)smallest=n;
		printf("Largest digit: %d	Smallest digit: %d\n",largest,smallest);	   //printing the largest and the smallest number
		return 0;}
	x=n%10;
	if(x>largest){largest=x;}
	if(x<smallest){smallest=x;}
	n=n/10;
	largesmall(n);                  //taking recursive approach
}

int main(){
	long long int n,original_n;
	printf("Enter a number: ");
	scanf("%lld",&n);               //taking value of n from the user
	original_n=n;
	largesmall(n);              //passing the value of n to the function largesmall
return 0;}
