/*Name- VIVEK RAJ
   ROLL-1601CS49
   16/08/2017*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int arr[200];       //creating global variables to use in the recursive function
int j=0,count=0;

int freq(int arr[]){        //creating a function freq to count the frequency of each letter
	if(arr[j]%2!=0)count=1;
	j=j+1;
	if(j<200){freq(arr);}
	}

bool isEvenWord(char str[],int i){  //creating a function isEvenWord that returns the value true if the word is even
	int n;
	n=strlen(str);
    if(i<n)arr[(int)str[i]]+=1;
	if(i<n)isEvenWord(str,i+1);
	return true ;
	}

int main() {
	char str[100];   //creating a variable str to store the string
	scanf("%s",str);  //taking the string from the user
	memset(arr,0,200);
	strlwr(str);
	isEvenWord(str,0);  //passing the string to the function isEvenWord
	freq(arr);  //calling the function freq
	if(count==1)printf("Odd");else printf("Even");  //printing if the word is even or odd
	return 0;
}
