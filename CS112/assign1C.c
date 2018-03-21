/*NAME - VIVEK RAJ
    ROLL- 1601CS49
    DATE- 01/08/2017 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

struct node{                    //creating a structure "node" representing a book
    int serialno;
    char title[100];
    char author[100];
    bool status;
    int *p;
};

 int main(){
        struct node entry[100];             //creating a structure variable
        char option,optionb,optionbb[100];  //creating variable of char data type to take input from the user
        int optionbz,xy,yx,zx;            //creating variable of data type int to store temporary information
        int dd,gg,mm;                           //creating variable of data type int to store temporary information
        int i=0,j=0;                        //creating variable of data type int to store temporary information

        for(j=0;j<100;j++){
            entry[j].serialno=459618;            //ASSIGNING RANDOM SERIAL NO TO THE BOOKS FOR FURTHUR USE
        }


        while(1==1){ xy=0,yx=0,zx=0,dd=0;gg=0,mm=0;     //resetting the temporary variables.

            printf("\na. Make a new entry of book\n");   //PRINTING THE REQUIRED INFORMATION
            printf("b. View Details of a book\n");
            printf("c. Show list of available books\n");
            printf("d. Issue a book\n");
            printf("e. Return a book\n");
            printf("f. Exit\n Enter the option: ");
            scanf(" %c",&option);
            printf("\n");

            if(option=='f'){                            //FOR EXITING THE PROGRAM
                return 0;
            }

            if (option=='a'){                           //FOR MAKING ENTRY OF A NEW BOOK!
                    printf("Enter the serial no: ");
                    scanf("%d",&entry[i].serialno);
                     for(j=0;j<100;j++){
                            if(entry[i].serialno==entry[j].serialno && j!=i){
                                printf("This serial no is already used. Please enter new serial no! \n");mm=1;}}
                            if(mm!=0){entry[i].serialno=459618;continue;}
                    printf("Enter the title: ");
                    scanf(" %[^\n]",entry[i].title);
                    printf("Enter the author's name: ");
                    scanf(" %[^\n]",entry[i].author);
                    entry[i].status=false;
                    i++;
                    printf("Entry successfull! \n");

                    option='z';continue;}

            else if(option=='b' && i!=0){                      //FOR VIEWING DETAILS OF A BOOK!
                    if(i!=0){
                        printf(" a. By serial no. \n b. By Title\n c. By Author \n Enter the option: ");
                        scanf(" %c",&optionb);
                        if(optionb=='a'){                                   //VIEWING DETAILS BY SERIAL NUMBER
                            printf("Enter the serial no of the book: ");
                            scanf("%d",&optionbz);
                            for(j=0;j<100;j++){
                                if(optionbz==entry[j].serialno){
                                    printf("\n Serial no: %d", optionbz);
                                    printf("\n Title: %s",entry[j].title);
                                    printf("\n Author: %s",entry[j].author);
                                    printf("\n Issue Status: %s\n",entry[j].status ? "true" : "false");yx=1;}}
                                if(yx!=1)printf("\nNo records with this serial no is found !\n");}}

                        if(optionb=='b'){                                     //VIEWING DETAILS BY TITLE OF THE BOOK
                            printf("\nEnter the title of the book: ");
                            scanf("%s",optionbb);
                            for(j=0;j<100;j++){
                                if(strcmp(optionbb,entry[j].title) == 0){
                                    printf("\n Serial no: %d", entry[j].serialno);
                                    printf("\n Title: %s",entry[j].title);
                                    printf("\n Author: %s",entry[j].author);
                                    printf("\n Issue Status: %s\n",entry[j].status ? "true" : "false");xy=1;}}
                                if(xy!=1)printf("\nNo records with this title is found! \n");
                            }

                        if(optionb=='c'){                                      //VIEWING DETAILS BY AUTHOR OF THE BOOK
                            printf("Enter the Author of the book: ");
                            scanf("%s",optionbb);
                            for(j=0;j<100;j++){
                                if(strcmp(optionbb,entry[j].author) == 0){
                                    printf("\n Serial no: %d", entry[j].serialno);
                                    printf("\n Title: %s",entry[j].title);
                                    printf("\n Author: %s",entry[j].author);
                                    printf("\n Issue Status: %s\n",entry[j].status ? "true" : "false");zx=1;}}
                                if(zx!=1)printf("\nNo records with this Author is found!\n ");}}

           else if(option=='d' && i!=0){                                        //TO ISSUE A BOOK
                            printf("Enter the serial no of the book to be issued: ");
                            scanf("%d",&optionbz);
                             for(j=0;j<100;j++){
                                if(optionbz==entry[j].serialno && entry[j].status==false){
                                        entry[j].status= true;
                                        printf("Your book has been issued! \n");dd=1;}

                                else if(optionbz==entry[j].serialno && entry[j].status==true){    //CHECKING IF THE BOOK IS ALREADY ISSUED OR NOT
                                        printf("This book has already been issued! \n");dd=1;}}

                                if(dd==0)printf("No book with this serial number is found! \n");} //CHECKING IF THE BOOK WITH THAT SERIAL NO EXISTS OR NOT




           else if(option=='e' && i!=0){                                                    //TO RETURN A BOOK
                            printf("Enter the serial no of the book to be returned: ");
                            scanf("%d",&optionbz);
                             for(j=0;j<100;j++){

                               if(optionbz==entry[j].serialno && entry[j].status==false){
                                        printf("This book is not issued yet !\n ");dd=1;}   //CHECKING IF THE BOOK IS ISSUED OR NOT

                               else if(optionbz==entry[j].serialno && entry[j].status==true){
                                        entry[j].status= false;
                                        printf("Your book has been returned!\n ");dd=1;}}    //RETURNING THE BOOK


                                if(dd==0)printf("No book with this serial number is found! \n"); //IF BOOK IS NOT FOUND, PRINTING REQUIRED INFORMATION
                                }


             else if(option=='c' & i!=0){                                           //TO DISPLAY LIST OF NON ISSUED BOOKS
                                printf("Details of the non-issued books are: ");
                                 for(j=0;j<100;j++){
                                    if(entry[j].serialno!=459618 && entry[j].status==false){
                                    printf("\n Serial no: %d", entry[j].serialno);
                                    printf("\n Title: %s",entry[j].title);
                                    printf("\n Author: %s",entry[j].author);
                                    printf("\n Issue Status: %s\n",entry[j].status ? "true" : "false");gg=1;}}

                                 if(gg==0)printf("\nAll the books are issued! \n");}    //CHECKING IF ALL THE BOOKS ARE ISSUED OR NOT

             else if(option>102||option<97){printf("Enter valid keyword!\n");option='z';continue;}

             else if(i==0){printf("Make new entry of a book first!\n");option='z';continue;}  //CHECKING IF THERE IS ANY ENTRY OF A BOOK OR NOT!


            }

return 0;

    }



