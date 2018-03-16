/*NAME - VIVEK RAJ
    1601CS49
    03/08/2017*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



struct node1{                                           //creating required structures
	char name;                                          //list1
	struct node1 *next;};

struct node2{                                           //list 2
	char name;
	struct node2 *next;};

struct node11{
    char name;
    struct node11 *next;};

struct node12{
    char name;
    struct node12 *next;};


bool Vowel(char x)                          //function to check if the given alphabet is vowel or not!
{
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||x == 'A' || x == 'E' || x == 'I' ||x == 'O' || x == 'U')
        return true;
   else return false
    ;
}

int main(){
	int n,i,j,k,x;                  //declaring int variables for temporary use
	char str1[100],str2[100],euro1[100],euro2[100];
	printf("Enter value of n: ");
	scanf("%d",&n);                         //taking value of n from the user.
	struct node1 *p1,*prev1; struct node1 *head1=NULL;  //declaring pointer variables of the created list
	struct node2 *p2,*prev2; struct node2 *head2=NULL;
	struct node11 *p11,*prev11; struct node11 *head11=NULL;
	struct node12 *p12,*prev12; struct node12 *head12=NULL;
	printf("Enter the names of the students: ");

	char nemo[100][100];                    //taking names from the user
	for(i=0;i<n;i++){
        scanf("%s",nemo[i]);	}

	for(i=0;i<n/2;i++){
		p1=(struct node1 *)malloc(sizeof(struct node1));    //creating new node in the linked list1
		p1->name=nemo[i][0];
		p1->next=NULL;
		if(head1==NULL)head1=p1;
		else prev1->next=p1;
		prev1=p1;
	}

	for(i=n/2;i<n;i++){
		p2=(struct node2 *)malloc(sizeof(struct node2));  //creating new node in the linked list 2
		p2->name=nemo[i][0];
		p2->next=NULL;
		if(head2==NULL)head2=p2;
		else prev2->next=p2;
		prev2=p2;
	}

	p1=head1;

	while(p1!=NULL){                                                //copying the vowel part of the linked list 1 to another linked list
            if(Vowel(p1->name)==true){
                p12=(struct node12 *)malloc(sizeof(struct node12));
                p12->name=p1->name;
                p12->next=NULL;
                if(head12==NULL)head12=p12;
                else prev12->next=p12;
                prev12=p12;
            }
            p1=p1->next;}

    p1=head1;
    while(p1!=NULL){
            if(Vowel(p1->name)==false){             //copying the non vowel part of the linked list 1 to another linked list.
                p12=(struct node12*)malloc(sizeof(struct node12));
                p12->name=p1->name;
                p12->next=NULL;
                if(head12==NULL)head12=p12;
                else prev12->next=p12;
                prev12=p12;
            }
            p1=p1->next;}

    p2=head2;

    while(p2!=NULL){
            if(Vowel(p2->name)==true){
                p11=(struct node11 *)malloc(sizeof(struct node11));  //copying the vowel part of the linked list 2 to another linked list
                p11->name=p2->name;
                p11->next=NULL;
                if(head11==NULL)head11=p11;
                else prev11->next=p11;
                prev11=p11;
            }
            p2=p2->next;}

    p2=head2;

    while(p2!=NULL){                                        //copying the non vowel part of the linked list 1 to another linked list.
            if(Vowel(p2->name)==false){
                p11=(struct node11 *)malloc(sizeof(struct node11));
                p11->name=p2->name;
                p11->next=NULL;
                if(head11==NULL)head11=p11;
                else prev11->next=p11;
                prev11=p11;
            }
            p2=p2->next;}



    p1=head1;
    printf("Linked List: ");                    //printing the required linked list
        while(p1!=NULL){
        printf("%c ",p1->name);
        p1=p1->next;
    }

    printf(" and ");

     p2=head2;
        while(p2!=NULL){
        printf("%c ",p2->name);               //printing the required linked list
        p2=p2->next;
    }

    p12=head12; i=0;


    printf("\nArranged List: ");
        while(p12!=NULL){
        printf("%c ",p12->name);
        str1[i]=p12->name;                    //printing the required linked list
        p12=p12->next;i++;
    }

    printf(" and ");

     p11=head11;i=0;
        while(p11!=NULL){
        printf("%c ",p11->name);
        str2[i]=p11->name;                    //printing the required linked list
        p11=p11->next;i++;
    }


    str1[n/2]='\0';
    str2[n-n/2]='\0';

    int l;k=0;
    int f;
    int count=0; int counter=0;
    int original=n;
    n=n/2;
    int original_n=n;
    l=n-1;


    if(strlen(str1)>1){     //CHECKING FOR PALINDRIME IN ARRANGED LIST 1
    while(1){

          for(f=0;f<100;f++){
            euro1[f]='\0';
            euro2[f]='\0';
        }

        x=0;
        for(i=k;i<n;i++){
           euro1[x]=str1[i];x++;}

        x=0;
        for(j=l;j>=k;j--){
           euro2[x]=str1[j];x++;}

        if(strcmp(euro1,euro2)==0){counter=2;break;}
        count ++;
        if(count<=(n-k-1)){
                n=n-1;l=l-1;}
        else {
            n=original_n;
            k=k+1;
            l=n-1;
            count=0;
        }
        if((n-k)<2) break;

    }
}
        if(counter==2)printf("\n%s is a palindrome !",euro1); //PRINTING IF ITS A PALINDROME OR NOT
        else printf("\nLinked list 1 is not a palindrome");


    k=0;
    count=0;counter=0;
    n=original;
    n=n-n/2;
    original_n=n;
    l=n-1;


    if(strlen(str2)>1){     //CHECKING FOR PALINDROME IN ARRANGED LIST 2
    while(1){

          for(f=0;f<100;f++){
            euro1[f]='\0';
            euro2[f]='\0';
        }
        x=0;
        for(i=k;i<n;i++){
           euro1[x]=str2[i];x++;}

        x=0;
        for(j=l;j>=k;j--){
           euro2[x]=str2[j];x++;}

        if(strcmp(euro1,euro2)==0){counter=2;break;}
        count ++;
        if(count<=(n-k-1)){
                n=n-1;l=l-1;}
        else {
            n=original_n;
            k=k+1;
            l=n-1;
            count=0;
        }
        if((n-k)<2) break;

    }
}
        if(counter==2)printf("\n%s is a palindrome !",euro1);  //PRINTING IF ITS A PALINDROME OR NOT
        else printf("\nLinked list 2 is not a palindrome");






return 0;}
