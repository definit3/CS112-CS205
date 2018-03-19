/*NAME- VIVEK RAJ
    1601CS49
    08/08/2017*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(int arr[],int low,int n,int key){    //FUNCTION TO FIND THE REQUIRED NUMBER BY DIVIDE AND CONQUER
    int i,count=0;
	if((n-low)<5)
	{	for(i=low;i<low+4;i++){
        if(key==arr[i]){printf("Index of the number to be searched is: %d",i);count=1;}  //PRINTING IF THE NUMBER WAS FOUND
        }
		if(count!=1)printf("The number you entered was not found in the list! ");  //PRINTING IF THE NUMBER WAS NOT FOUND
		return;
	}
	int n1;
	n1=2*(n-low)/5;
	n1=low+n1;
    if (arr[n1]==key)
	{
		printf("Index of the number to be searched is: %d",n1);return;
	}

	else if(key<arr[n1]){
		sort(arr,low,n1-1,key);   //PASSING THE FUNCTION TO ITSELF-  RECURSIVE APPROACH
	}

	else if(key>arr[n1]){
		sort(arr,n1+1,n,key);

	}
}

int main()
{
	int n,i,key,low=0;
	printf("Enter the size of the list: ");  //TAKING THE SIZE OF THE LIST FROM THE USER
	scanf("%d",&n);
	int arr[n];
	printf("Enter the numbers in sorted order: ");      // TAKING THE NUMBERS FROM THE USER IN THE SORTED ORDER
	for (i = 0; i <n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to be searched: ");   //TAKING THE NUMBER TO BE SEARCHED FROM THE USER
	scanf("%d",&key);
	sort(arr,low,n,key);
	return 0;
}
