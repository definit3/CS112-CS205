/*VIVEK RAJ;
  1601CS49
 31/01/2017*/

//PROGRAM to convert two decimal integers into their corresponding binary string representations and to calculate their hamming weights
#include<stdio.h>


int main(){

    int integer1,integer2,remainder,quotient1,quotient2,binNum1[1000],binNum2[1000],i,j,k,l;  //declaring required variables
    i=1;l=1;                                                                                  //assigning the values to temporary variables
    int a; int count=0;
    int hammingweight1=0,hammingweight2=0,hammingdistance;                                     //assigning the values to temporary variables


    printf("Enter two decimal integers: ");
    scanf("%d,%d",&integer1,&integer2);                                                       //taking input from user
    quotient1=integer1;                                                                 //temporarily assigning the value of integer1 to quotient1
    quotient2=integer2;                                                                 //temporarily assigning the value of integer2 to quotient2


    while(quotient1!=0){    //loop to convert decimal into binary string for integer 1

         binNum1[i]= quotient1 % 2;
         quotient1 = quotient1 / 2;
         if(binNum1[i]==1){hammingweight1+=1;}  //calculating hamming weight for integer 1
         i++;}

    while(quotient2!=0){ //loop to convert decimal into binary string for integer 1

         binNum2[l]= quotient2 % 2;
         quotient2 = quotient2 / 2;
         if(binNum2[l]==1){hammingweight2+=1;}  //calculating hamming weight for integer 2
         l++;

    }



    printf("The binary representation for %d is ",integer1);
     for(k=i -1 ;k>0;k--)

         printf("%d",binNum1[k]);   //printing binary representation of integer 1

    printf("\nThe binary representation for %d is ",integer2);
    for(j=l-1 ;j>0;j--)

         printf("%d",binNum2[j]);  //printing binary representation of integer 2

    printf("\nHamming weight for the first string = %d",hammingweight1); //printing hamming weight for integer 1
    printf("\nHamming weight for the second string = %d",hammingweight2); //printing hamming weight for integer 2

      for(a=1;a<=5;a++){
       if(binNum1[a]=binNum2[a]){count+=1;}
    }
    if(i==l){
    printf("\nHamming distance between the two strings = %d",count);} //printing hamming distance between the two strings

    printf("\nThe hexadecimal representation for the first string = %x",integer1); //printing hexadecimal representation of the first string
    printf("\nThe hexadecimal representation for the first string = %x",integer2); //printing hexadecimal representation of the second string




    return 0;

}

