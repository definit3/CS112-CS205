/*NAME - VIVEK RAJ
  ROLL- 1601CS49
  DATE- 07/08/2017*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count(long long int n,long long int *cnt){					//creating a function count to count the number of odd digits in a given number
	int r;
	if(n<10){								//defining base case for recursion
		if(n%2!=0){*cnt=*cnt+1;}
		printf("Count of odd digits in the number: %lld\n", *cnt);	//printing the count
		return 0;}
	r=n%10;
	n=n/10;
	if(r%2!=0){*cnt=*cnt+1;count(n,cnt);}				//checking if the digit is even or odd
	else count(n,cnt);						//passing the function to itself
}



int main(){
	long long int n,cnt=0;
	printf("Enter a number: ");				//taking value of an integer from the user
	scanf("%lld",&n);
	count(n,&cnt);



return 0;}
