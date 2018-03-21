#include <stdio.h>
/*NAME - VIVEK RAJ
   ROLL - 1601CS49
   DATE-07/02/2017*/

int main(){

int i,j,n,z=0;            //assigning and declaring some temporary variables.
int count,counter,hault;  //assigning some temporary variables.
int searchid,newguest;    //assigning variables to the required input
int men=0,women=0;
int tempm=0,tempf=0;      //introducing temporary variables

printf("Enter the no of unique guest ids: ");
scanf("%d",&n);                                             //taking input as no of unique guests from the user
int uniqueid[n];
printf("Enter the unique ids of the guests:(separated by a space) ");
for(i=0;i<n;i++){
	scanf("%d",&uniqueid[i]);                               //taking unique ids of the guests from the user
}

printf("Enter the id to be searched: ");
scanf("%d",&searchid);                                      //taking the id of the guest to be searched
printf("Enter the unique id of the new guest: ");
scanf("%d",&newguest);                                      //taking the id of the new guest from the user

for (i = 0; i < n; i++)                                     //loop to stack the ids in decreasing order
    {
        for (j = i + 1; j < n; j++)
        {
            if (uniqueid[i] < uniqueid[j])
            {
                counter = uniqueid[i];
                uniqueid[i] = uniqueid[j];
                uniqueid[j] = counter;}}}

printf("The seating arrangement is:\n");


if(n<5){for(i=0;i<n;i++)printf("%d ",uniqueid[i]);}                     /*Printing the seating arrangements*/
if(n>=5){for(i=0;i<5;i++){printf("%d ",uniqueid[i]);}printf("\n");}
if(n<10){for(i=5;i<n;i++){printf("%d ",uniqueid[i]);}printf("\n");}
if(n>=10){for(i=5;i<10;i++){printf("%d ",uniqueid[i]);}printf("\n");}
if(n<15){for(i=10;i<n;i++){printf("%d ",uniqueid[i]);}printf("\n");}
if(n>=15){for(i=10;i<15;i++){printf("%d ",uniqueid[i]);}}

for(i=0;i<n;i++){
        if(searchid==uniqueid[i]){
            printf("The guest with id %d is present in the party and is seated at position %d.",searchid,i+1);z+=1;}
}
if(z==0){printf("The guest with id %d is not present in the party",searchid);}  //checking if the searched guest is present in the party or not


for(i=0;i<n;i++){
        if(uniqueid[i]<0){men+=1;}
        if(uniqueid[i]>0){women+=1l;}  //condition to check how many men and women are in the party
}

printf("\nThere are %d males and %d females",men,women); //printing how many men and women are in the party.

for(i=0;i<n;i++){
    if(uniqueid[i]<0){
        if(tempm==0){printf("\nThe male guest id's are: ");}  //printing the male guests ids.
        printf("%d ",uniqueid[i]);tempm+=1;}
    if(uniqueid[i]>0){
        if(tempf==0){printf("\nThe female guest id's are: ");}   //printing the female guests ids.
        printf("%d ",uniqueid[i]);tempf+=1;}
}

men=0;women=0;tempm=0;tempf=0;    //declaration of temporary variables
for(i=0;i<n;i++){
    if(uniqueid[i]%2==0){men+=1;}}      //calculating no of guests in red and blue dress
women=n-men;
printf("\nThere are %d guests in red and %d guests in blue dress respectively.",men,women);  //printing no of guests in red and blue dress

for(i=0;i<n;i++){
    if(uniqueid[i]%2==0){
            if(tempm==0){printf("\nThe seating positions of the guests in red dress are: ");} //printing seating positions of red dress guests
            printf("%d ",i+1);tempm+=1;}
}


for(i=0;i<n;i++){
    if(uniqueid[i]%2!=0){
            if(tempf==0){printf("\nThe seating positions of the guests in blue dress are: ");}  //printing seating positions of blue dress guests
            printf("%d ",i+1);tempf+=1;}
}

men=0;
for(i=0;i<n;i++){
    if(newguest>uniqueid[i] && men==0){hault=i;tempf=uniqueid[i];uniqueid[i]=newguest;men+=1;} //loop to stack the guests in required order including the new guest
}


for(i=hault+1;i<=n;i++){
    tempm=uniqueid[i];
    uniqueid[i]=tempf;
    tempf=tempm;}

printf("\nThe new seating arrangement is: \n");

if(n+1<5){for(i=0;i<n+1;i++)printf("%d ",uniqueid[i]);}
if(n+1>=5){for(i=0;i<5;i++){printf("%d ",uniqueid[i]);}printf("\n");}
if(n+1<10){for(i=5;i<n+1;i++){printf("%d ",uniqueid[i]);}printf("\n");}
if(n+1>=10){for(i=5;i<10;i++){printf("%d ",uniqueid[i]);}printf("\n");}   //loops to print the final seating arrangement.
if(n+1<15){for(i=10;i<n+1;i++){printf("%d ",uniqueid[i]);}printf("\n");}
if(n+1>=15){for(i=10;i<15;i++){printf("%d ",uniqueid[i]);}printf("\n");}




return 0;}
