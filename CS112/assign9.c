/* NAME - VIVEK RAJ
    ROLL-1601CS49
    DATE- 21/03/2017*/

#include <stdio.h>
#include <string.h>

typedef struct _node{                                        //defining given structure
    char roll[10];                                                  //declaring roll number as char
    int ht;                                                         //declaring height as int
    int wt;                                                         //declaring weight as int
    struct _node *next_ht;                                          //creating pointer next_ht to point to next node
    struct _node *next_wt;                                         //creating pointer next_wt to point to next node
    }list;


void printNameList(list *ptr,list *ptr2){               //function to print the list of names

    while (ptr != NULL) {                                       //using while loop to do the required function

    printf("%s  ", ptr->roll);
    ptr = ptr->next_ht;
}

}

void swap(list *a, list *b);
void swapwt(list *a, list *b);

void sort_ht(list *start)                           //function to bubble sort wrt height
{
    int swapped, i;
    struct _node *ptrz;
    struct _node *ptry = NULL;


    if (ptrz == NULL)
        return;

    do
    {swapped = 0;
     ptrz = start;

        while (ptrz->next_ht != ptry)
        {if (ptrz->ht > ptrz->next_ht->ht)
            {
            swap(ptrz, ptrz->next_ht);
            swapped = 1;}
            ptrz = ptrz->next_ht;
        }
        ptry = ptrz;}
    while (swapped);
}

  typedef struct node{
    char roll[10];
    int ht;
    int wt;
    struct node *next_ht;
    struct node *next_wt;
    }list1;


void sort_wt(list *start)               //function to bubble sort wrt weight
{
    int swapped, i;
    struct _node *ptrz;
    struct _node *ptry = NULL;


    if (ptrz == NULL)
        return;

    do
    {swapped = 0;
     ptrz = start;

        while (ptrz->next_wt != ptry)
        {if (ptrz->wt > ptrz->next_wt->wt)
            {
            swapwt(ptrz, ptrz->next_wt);
            swapped = 1;}
            ptrz = ptrz->next_wt;
        }
        ptry = ptrz;}
    while (swapped);
}


void swap(list *a, list *b)
{   char tempu[10];
    strcpy(tempu,a->roll);
    strcpy(a->roll,b->roll);
    strcpy(b->roll,tempu);
    int temp = a->ht;
    a->ht = b->ht;
    b->ht = temp;
}

void swapwt(list *a, list *b)
{
    char tempu[10];
    strcpy(tempu,a->roll);
    strcpy(a->roll,b->roll);
    strcpy(b->roll,tempu);
    int temp = a->wt;
    a->wt = b->wt;
    b->wt = temp;
}

int main(){                                      //main function
    int n, i,j;
    struct _node *head = NULL, *p, *prev;
    struct node *head1=NULL,*p1,*prev1;

    printf("Enter number of nodes: ");
    scanf("%d", &n);                                    //taking no of nodes from the user
    printf("Enter Roll no, Height and Weight separated by space:\n");
    for (i= 0; i< n; ++i) {
    p = (struct _node *) malloc(sizeof(struct _node));
    scanf("%s", &p->roll);                                  //taking name, roll and height from the user
    scanf("%d", &p->ht);
    scanf("%d", &p->wt);
    p->next_ht = NULL;
    p->next_wt= NULL;

    if (head == NULL) head = p;
    else {prev->next_ht = p;prev->next_wt = p;}             //feeding my nodes into the structure
    prev= p;

    p1 = (struct node *) malloc(sizeof(struct node));
    strcpy(p1->roll,p->roll);
    p1->ht=p->ht;
    p1->wt=p->wt;
    p1->next_ht = NULL;
    p1->next_wt= NULL;

    if (head1 == NULL) head1 = p1;
    else {prev1->next_ht = p1;prev1->next_wt = p1;}
    prev1= p1;
    }

    printf("\nSort using height: ");        //sorting using height
        sort_ht(head);
    printNameList(head,prev);

    printf("\nSort using weight: ");        //sorting using weight
        sort_wt(head1);
    printNameList(head1,prev1);




return 0;

}
