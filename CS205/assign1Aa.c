/*NAME - VIVEK RAJ
    ROLL- 1601CS49
    05/08/2017*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name{                                //creating a structure  to store the distinguished names.
    char names[100];
    struct name *next;
};


int main(){
    int n,i,j,k,x=0;                        //declaring variables for temporary use.
    char names[100][100],names2[100][100],temp[100],temp2[100];   //declaring character array for storing names.
    struct name *p,*prev,*head=NULL;        //declaring pointer of the structures
    printf("Enter the value of n: ");
    scanf("%d",&n);                         //Taking value of n from the user.
    printf("Enter the names separated by space: ");
    for(i=0;i<n;i++){
        scanf("%s",names[i]);               //Taking names from the user.
    }

    printf("\nNames in array: ");
    for(i=0;i<n;i++){
        printf("%s  ",names[i]);            //Printing names
    }

    for(i=0;i<n;i++){     //loop to unambiguously distinguish students
        for(j=0;j<n;j++){
            while(i!=j){
                if(names[i][x]==names[j][x]){
                    names2[i][x]=names[i][x];
                    }
                else {names2[i][x]=names[i][x];
                      x=0;
                     break;}
                x++;}}}


    for(i=0;i<n;i++){    //copying the distinguished names to the list
        p=(struct name *)malloc(sizeof(struct name));
        strcpy(p->names,names2[i]);
        p->next=NULL;
        if(head==NULL)head=p;
        else prev->next=p;
        prev=p;
    }

    printf("\n\nNames in list: ");
    p=head;
    while(p!=NULL){
        printf("%s  ",p->names);    //printing the names in the list.
        p=p->next;
    }


      for (i = 0; i < n - 1 ; i++)    //sorting in dictionary order.
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(names[i], names[j]) > 0|| strcmp(names2[i], names2[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
                strcpy(temp2, names2[i]);
                strcpy(names2[i], names2[j]);
                strcpy(names2[j], temp2);}}}

    printf("\n\nSorted Names in list: ");
     for(i=0;i<n;i++){
    printf("%s  ",names2[i]);
   }


    printf("\n \nFinal Sorted Names: ");   //printing final sorted names.
   for(i=0;i<n;i++){
    printf("%s  ",names[i]);
   }
   printf("\n");

return 0;}
