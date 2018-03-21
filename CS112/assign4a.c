#include <stdio.h>
#include <math.h>
/* VIVEK RAJ;
    1601CS49
    31/01/2017*/

//PROGRAM TO FIND ALL THE PERFECT SQUARES IN A GIVEN RANGE

int main() {

int no1,no2,i,count,j,phantom=0;  //declaration of variables used
double sqroot,k=0;                //declaration of variables used
char inch;                        //declaring character inch for the input requirements

do{                                //using do while loop for required condition

if(k==0){
printf("Enter the range of numbers:");}

scanf("%d %c %d",&no1,&inch,&no2); //Taking the range of input from the user in the given format(e.g "10-16")
count=no2-no1;



	for(i=0;i<=count;i++){        //using for loop for finding all the perfect squares

	sqroot=sqrt(no1);             //finding the square root
	j=floor(sqroot);              //flooring the value of found square root to nearest integer
		if(sqroot==j){            //condition if the no is perfect square or not

            if(phantom==0){printf("The perfect squares in the given range are:");}
            printf(" %d",no1);  //printing the found perfect squares
			phantom+=1;
			}
    no1+=1;}

	if(phantom==0){k+=1;printf("\nNo perfect square exists. Please enter another range:");} //taking condition in case no perfect square is found


}while(phantom==0);





return 0;}
