/*Vivek Raj
  Roll- 1601CS49
  09/08/2017*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(int arr[],int low,int n,int key){    //FUNCTION TO FIND THE GIVEN KEY BY DIVIDE AND CONQUER
	if((n-low)<2)
	{	if(key==arr[low])printf("Index of the number to be searched is: %d",low);
		else if(key==arr[low+1]) printf("Index of the number to be searched is: %d",low+1);
		else if(1==1)printf("The number you entered was not found in the list! ");   //PRINTING IF THE NUMBER IS NOT FOUND IN THE LIST
		return;
	}
	int n1,n2;
	if((n-low)==2){n1=low;n2=low+1;}
	else {n1=(low+n)/3;
        n2=2*(low+n)/3;}
	if (arr[n1]==key)
	{
		printf("Index of the number to be searched is: %d",n1);return;    //printing the index of the number that was found.
	}
	else if (arr[n2]==key)
	{
		printf("Index of the number to be searched is: %d",n2);return;   //printing the index of the number that was found.
	}
	else if(key<arr[n1]){
		sort(arr,low,n1-1,key);             //passing the value to the function itself
	}
	else if (key>=arr[n1] && key<arr[n2])
	{
		sort(arr,n1,n2-1,key);          //passing the value to the function itself
	}
	else if(key>=arr[n2]){
		sort(arr,n2,n-1,key);              //passing the value to the function itself

	}
}

int main()
{
	int n,i,key,low=0;
	printf("Enter the size of the list: ");  //taking the value of the size of the list from the user.
	scanf("%d",&n);
	int arr[n];
	printf("Enter the numbers in sorted order: ");     //taking the numbers from the user
	for (i = 0; i <n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the number to be searched: ");
	scanf("%d",&key);                           //taking the number to be searched from the user.
	sort(arr,low,n,key);
	return 0;
}
