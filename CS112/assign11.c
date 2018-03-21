#include <stdio.h>
#include <stdlib.h>
/*NAME VIVEK RAJ ; 1601CS49 ; 5/04/17 */
int n;
int count=0;counter=0;
typedef struct _node{                                       //creating the structure
	int data;
	struct _node *leftchild;
	struct _node *rightchild;
	struct _node *parent;}node;


node *NewNode(node *point,int element) {                    //function to insert data in the form of binary tree
     node *head=NULL;
     if(head==NULL)head=point;
	if(point==NULL){
	point=(struct _node *)malloc(sizeof(struct _node));             //manually allocating size for new node
	point->leftchild=point->rightchild=NULL;
	point->data = element;                                          //assigning the data of the binary tree
	return point;}

	else{
	if(element<=point->data)
		point->leftchild=NewNode(point->leftchild,element);         //loop to fill the data in given binary tree form
	else if(element > point->data)
		point->rightchild=NewNode(point->rightchild,element);
	return point;
}
}


 int  printParent(node *head){                     //function to print the required output
  if (head != NULL) {

  if(count==0){printf("\n");
               printf("|Node| \n");count++;}

   printf(" %d  \n", head->data);
  printParent(head->leftchild);              //recursion
  printParent(head->rightchild);            //recursion
}

}



int main(){

int i,data;

struct _node *head=NULL,*p=NULL;                    //declaring pointer of the structure

printf("Enter the value of n: ");                       //taking the value of n from the user
scanf("%d",&n);
printf("Enter data: ");                             //taking data from the user
head=NULL;
for(i=1;i<=n;i++){
scanf("%d",&data);
head=NewNode(head,data);if(p==NULL)p=head;          //calling the inserting data function
}

printParent(head);                                  //calling the printing function




return 0;}
