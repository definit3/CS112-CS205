#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*NAME -VIVEK RAJ*
 ROLL - 1601CS49
 DATE- 09/03/2017*/

int main(){

int i,j,na;												//declaring temporary variables
char temp[100],counter;
char names[100][100],*n[100];						//declaring variable names to store the words


printf("Enter the number of names: ");				//printing info for the user
scanf("%d",&na);									//taking the number of names from the user

for(i=0;i<na;i++){

    for(j=0;j!='\0';j++){
    scanf("%s",names[i][j]);
  							//taking the names from the user
    }
}


 for(i=0; i<na;i++){					//loop to arrange in dictionary order
        for(j=i+1; j<na ; j++)
        {
            counter=strcmp(names[i],names[j]);
            if(counter>0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
 }


 for(i=0; i<na;i++){					//loop to arrange in dictionary order
        for(j=i+1; j<na ; j++)
        {
            counter=strcmp(n+i,n+j);
            if(counter>0)
            {
                strcpy(temp, n+j);
                strcpy(n+i, n+j);
                strcpy(n+j, temp);
            }
        }
 }




        printf("\nIn dictionary order:");
    for(i=0; i<na; ++i)
    {
        printf("\n%s",names[i]);   //printing the ordered names
    }



      printf("\nIn dictionary order:");
    for(i=0; i<na; ++i)
    {
        printf("\n%s",(n+i));   //printing the ordered names
    }



return 0;}
