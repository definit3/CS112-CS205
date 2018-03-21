#include <stdio.h>
/*Name-Vivek Raj
     1601CS49
     07/02/2017*/
//PROGRAM TO check if a person can see the stage or not.
int main(){


int i,n,j,count=0,counter=0,result; //assigning variables used in the program

printf("Enter the number of students participated: ");
scanf("%d",&n);                     //taking input of no of students participated from the user.
int inputno[n],color[n];
printf("Enter their heights: ");

for(i=0;i<n;i++){
scanf("%d",&inputno[i]);           //Taking input as height from the user.
}

printf("\nEnter the color of robes denoted by integers: ");

for(i=0;i<n;i++){
scanf("%d",&color[i]);             //Taking input as color from the user.
}


for(i=n-1;i>=0;i--){               //loop to check the no of students who can see the stage.
 count=0;

	for(j=n-2;j>=0;j--){
		if(inputno[i]<inputno[j] &&count!=1 && j<i){count+=1;counter+=count;}
	}

}
	result=n-counter;
	printf("\nNo. of students can see the stage: %d\n",result);   //Printing the result

count=0;
for(i=n-1;i>=0;i--){                //loop to check if all students has different clothes's color or not.


	for(j=n-2;j>=0;j--){
		if(color[i]==color[j] && j<i){count+=1;}
	}

}

	if(count==0){printf("\nIt is a GIRLS party\n");}    //printing the required condition
	if(count!=0){printf("\nIt is a BOYS party\n.");}





return 0;}
