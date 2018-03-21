#include <stdio.h>
/* NAME- VIVEK RAJ; ROLL-1601CS49; DATE-17-01-2017*/
//Program to calculate who wins the described race and by what margin.
int main()
{

float x,y;                //assigning data type to the input of x and y
float z,original_x;       //assigning data type to intermediate required variables.


//Taking input of x and y from user
printf("Enter X: ");
scanf("%f",&x);
printf("Enter Y: ");
scanf("%f",&y);


original_x=x;             //storing entered value of x in a variable original_x
z=x+y;                    //storing sum of x and y in a variable z



//Applying condition for who wins the match and by what margin
if (x<12.85714 && z >=20){
     x=18-1.4*x;
     printf("Winner: Tortoise \nWinning distance margin: %.2f meters",x);  //printing who wins the match and by what margin
}

else if( x>= 12.85714){
     x=18-12.85714*0.9;
     printf ("Winner: Rabbit \nWinning distance margin: %.2f meters",x);}  //printing who wins the match and by what margin

else if(x<12.85714 && z<20){

     x=20-z;
     x=x+original_x;

     if (x <12.85714){
        x=18-1.4*x;
        printf("Winner: Tortoise \nWinning distance margin: %.2f meters",x);}  //printing who wins the match and by what margin

     else if(x >= 12.85714){
        x=18-(12.85714+y)*0.9;
        printf ("Winner: Rabbit \nWinning distance margin: %.2f meters",x);}  //printing who wins the match and by what margin

}


return 0;}
