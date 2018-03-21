#include <stdio.h>
/* VIVEK RAJ
   1601CS49; 23/01/2017 */

//Program to show no of choices of plan for a boat building company

int main(){

     int i, months, term1 = 1, term2 = 2, nextTerm = 0;                        //declaring variables type as int

    printf("Enter the month after which the area is to be closed: ");
    scanf("%d", &months);                                                      //Taking input from user

    if(months==0)printf("There is 0 choice of plan");                          //If months entered is 0, choice will be 0
    if(months==1)printf("There is 1 choice of plan");                          //If months entered is  1, choice will be 1
    if(months==2)printf("There are 2 choices of plan");                        //If months entered is 2, choices will be 2

    /* After 2 months onwards, the output choices will follow the fibonacci series. So, calculating the fibonacci no for entered month*/

    if(months>2){
    for (i = 3; i <= months; ++i)
    {
        nextTerm = term1 + term2;                /* code to calculate fibonacci number*/
        term1 = term2;
        term2 = nextTerm;
    }
    printf("There are %d choices of plan", nextTerm);  //Printing the choices of plan
    }


return 0;}
