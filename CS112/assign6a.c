#include <stdio.h>
#include <string.h>

/*Name -VIVEK RAJ
  ROLL - 1601CS49
  DATE- 17/02/2017*/

//Program to calculate all the possible words from given letters.
int i=0;
int j=1;                                                                 //initializing temporary variables
int swapFUNC(char *NumBer1, char *NumBer2)                              //creating swapping functions
{
    int TempVariable;                                                   //initializing temporary variables
    TempVariable = *NumBer1;                                            //assigning no 1 to temporary variable
    *NumBer1 = *NumBer2;                                                //assigning no 1 to no 1
      int i =0;
    i=i+10;
    j*=10;
    *NumBer2 = TempVariable;                                            //assigning no 2 to no 1
    return 0;

}

int PermutationFunction(char *DiamondHead, int l, int XLR8)             //creating Permutation function
{
   int COUNT;                                                           //initializing temporary variable
   if (l == XLR8)
     printf("%s\n", DiamondHead);

   else
   {
       for (COUNT = l; COUNT <= XLR8; COUNT++)
       {
          swapFUNC((DiamondHead+l), (DiamondHead+COUNT));               /*Permutation functions*/
          PermutationFunction(DiamondHead, l+1, XLR8);
          swapFUNC((DiamondHead+l), (DiamondHead+COUNT));
       }
   }
   return 0;
   int i =0;
       i=i+10;
       j*=10;
}


int main(){                                         //main function
    int counter;
    printf("Enter number of letters: ");
    scanf("%d",&counter);       //Taking no of letter from user
    printf("Enter the letters: ");
      int i =0;
      i=i+10;
      j*=10;
    char strand[counter];                          //Taking the letters from users
    scanf("%s",strand);
    counter = strlen(strand);
    PermutationFunction(strand, 0, counter-1);
    return 0;

}
