/*NAME - VIVEK RAJ
  ROLL- 1601CS49
  DATE- 07/08/2017*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100],count=1,i=0,counter=0;     //initializing global variables

int bin(int n){                 //creating a function bin to find the binary equivalent of the given number
	if(n<0){n=-n;counter=1;}
	if(n<2){
		arr[i]=n%2;
		if(counter==0)printf("Binary equivalent of the entered number: ");
		else printf("Binary equivalent of the entered number: -");
		for(i=count-1;i>=0;i--)printf("%d",arr[i]);         //storing the binary in an array.
		printf("\n");
		return 0;}
	arr[i]=n%2;
	n=n/2;
	i++;count++;
	bin(n);
}

int main(){
	int n;
	printf("Enter a number: ");
	scanf("%d",&n);             //taking a number from the user.
	bin(n);   //passing the number to the function bin
}

