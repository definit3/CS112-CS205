#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linklist1{
        int number[5];
        struct linklist1 *next;
        struct linklist1 *prev;

}linklist1;

int main(){
    linklist1 *previous,*head=NULL,*p;
    int n1,n2,i,j,k,l=5,r1,r2;
    int count;
    char choice;
    char number1[200],number2[200];
    printf("Comparison(c) or Addition (a) or Subtraction (s) or Exit (x): ");
    scanf("%c",&choice);
    if(choice=='x'){return 0;}
    printf("Enter the first number: ");
    scanf("%s",number1);
    printf("Enter the second number: ");
    scanf("%s",number2);
    n1=strlen(number1);
    int arr1[n1];
    n2=strlen(number2);
    int arr2[n2];

    for(i=1;i<=n1;i++){arr1[i]=number1[i]-'0';}
    for(i=1;i<=n2;i++){arr2[i]=number2[i]-'0';}

        for(i=1;i<=n2;i++){printf("%d",arr2[i]);}

    if(n1%5==0)r1=n1%5;else r1=n1%5+1;
    if(n2%5==0)r2=n2%5;else r2=n2%5+1;


 if(n1<5)l=n1;

for(j=1;j<=r1;j++){

            p = (struct linklist1 *) malloc(sizeof(struct linklist1));
            if(head==NULL){head=p;}

            k=0;
            for(i=n1;i>n1-l;i--){
            p->number[k]=arr1[i];k++;}


            previous=p;
            if(head!=NULL) {
              //  p=p->next;
                p->next=head;
                p->prev=previous;
                previous->next=p;}



    if(n1%5==0 && j!=r1-1){n1=n1-5;}

    if(n1%5!=0 && j==r1-1 && n1>5){n1=n1-5;l=n1;}
}


printf("\n\n");

p=head;
do{
        for(i=1;i<=2;i++)
    printf("%d",arr1[i]);
    p=p->next;
}while(p!=head);






//if(n1%5==0 && j!=r1-1){n1=n1-5;}
  //  if(n1%5!=0 && j==r1-1){n1=n1-5;l=n1-2*j;}






}
