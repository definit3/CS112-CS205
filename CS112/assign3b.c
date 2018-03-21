#include <stdio.h>
/* VIVEK RAJ
   1601CS49; 23/01/2017 */

//Program to display seven segment display for entered roll number
int main() {
int one,two,three,four,five,six,seven,eight,nine,ten;  //declaring variables for the respective digits
int rollno,ones,tens,a,i;                              //declaring variables for roll no and other variables.
int arr[2];                                            //creating an array for ones and tens place of the entered roll no
char specialchar;                                      //declaring variable for special character


printf("Enter last two digits of your Roll.No: ");
scanf("%d",&rollno);                                   //taking roll no from the user

printf("Enter the Character for display: ");
scanf(" %c",&specialchar);                             //taking special character from the user

ones=rollno%10;                                        //calculating ones place of the entered digit
tens=rollno/10;                                        //calculating tens place of the entered digit
arr[0]=tens;                                           //assigning the first element of array as tens
arr[1]=ones;                                           //assigning the second element of array as ones
//If the digit is one

for(i=0;i<=1;i++){                                      //creating a loop to print tens and ones place of the entered digit
if(arr[i]==1){
    for(a=1;a<=7;a++){printf("     %c\n",specialchar);}     //code to print digit 1 in special character
printf("\n\n");
}

//If the digit is 2
if(arr[i]==2){
    for(a=1;a<=6;a++){printf("%c",specialchar);}            //code to print digit 2 in special character
printf("\n");

    for(a=1;a<=2;a++)printf("     %c\n",specialchar);

    for(a=1;a<=5;a++)printf("%c",specialchar);

    for(a=1;a<=3;a++)printf("%c\n",specialchar);

    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n\n");
}


//If the digit is 3
if(arr[i]==3){
    for(a=1;a<=6;a++){printf("%c",specialchar);}            //code to print digit 3 in special character
printf("\n");

    for(a=1;a<=2;a++)printf("     %c\n",specialchar);

    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n");
    for(a=1;a<=2;a++)printf("     %c\n",specialchar);

    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n\n");
}


//If the digit is 4
if(arr[i]==4){
    for(a=1;a<=2;a++){printf("%c    %c\n",specialchar,specialchar);}


    for(a=1;a<=6;a++){printf("%c",specialchar);}                            //code to print digit 4 in special character

printf("\n");
    for(a=1;a<=3;a++)printf("     %c\n",specialchar);
printf("\n\n");
}

//If the digit is 5
if(arr[i]==5){
    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n");

    for(a=1;a<=2;a++)printf("%c\n",specialchar);                            //code to print digit 5 in special character

    for(a=1;a<=6;a++){printf("%c",specialchar);}

printf("\n");

    for(a=1;a<=2;a++)printf("     %c\n",specialchar);


    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n\n");
}

//If the digit is 6
if(arr[i]==6){
    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n");                                                               //code to print digit 6 in special character

    for(a=1;a<=2;a++)printf("%c\n",specialchar);

    for(a=1;a<=6;a++){printf("%c",specialchar);}

printf("\n");

    for(a=1;a<=2;a++){printf("%c    %c\n",specialchar,specialchar);}


    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n\n");
}

//If the digit is 7
if(arr[i]==7){
    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n");
    for(a=1;a<=6;a++){printf("     %c\n",specialchar);                      //code to print digit 7 in special character
}
printf("\n\n");
}

//If the digit is 8
if(arr[i]==8){
    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n");

    for(a=1;a<=2;a++){printf("%c    %c\n",specialchar,specialchar);}        //code to print digit 8 in special character

    for(a=1;a<=6;a++){printf("%c",specialchar);}

printf("\n");

    for(a=1;a<=2;a++){printf("%c    %c\n",specialchar,specialchar);}

    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n\n");
}
//If the digit is 9
if(arr[i]==9){

    for(a=1;a<=6;a++){printf("%c",specialchar);}

printf("\n");
    for(a=1;a<=2;a++){printf("%c    %c\n",specialchar,specialchar);}       //code to print digit 9 in special character

    for(a=1;a<=6;a++){printf("%c",specialchar);}

printf("\n");

    for(a=1;a<=3;a++)printf("     %c\n",specialchar);
printf("\n\n");
}

//If the digit is 0
if(arr[i]==0){

    for(a=1;a<=6;a++){printf("%c",specialchar);}

printf("\n");
    for(a=1;a<=4;a++){printf("%c    %c\n",specialchar,specialchar);}     //code to print digit 0 in special character

    for(a=1;a<=6;a++){printf("%c",specialchar);}
printf("\n\n");

}
}
return 0; }

