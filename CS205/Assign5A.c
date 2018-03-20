/*NAME-VIVEK RAJ
    ROLL-1601CS49*/


#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


//FUNCTION TO SWAP TWO ELEMENTS
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//FUNCTION PARTITION TO PARTITION THE ARRAY AS REQUIRED IN QUICKSORT
int partition (int arr[], int low, int high,int pivot_type)
{
    int pivot;
    if(pivot_type==0){pivot=pivot_finder(arr,low,high,pivot_type);swap(&arr[pivot],&arr[low]);pivot=low;} //IF PIVOT OPTION IS 0
    if(pivot_type==1){pivot=pivot_finder(arr,low,high,pivot_type);swap(&arr[pivot],&arr[low]);pivot=low;}//IF PIVOT OPTION IS 1
    if(pivot_type==2){pivot=pivot_finder(arr,low,high,pivot_type);swap(&arr[pivot],&arr[low]);pivot=low;}//IF PIVOT OPTION IS 2
    if(pivot_type==3){pivot=pivot_finder(arr,low,high,pivot_type);swap(&arr[pivot],&arr[low]);pivot=low;}//IF PIVOT OPTION IS 3

    int i = low,j=high;

    for (;i<j;)
    {
       for(i;arr[i]<=arr[pivot]&&i<high;i++){}
       for(j;arr[j]>arr[pivot];j--){}
       if(i<j)swap(&arr[i],&arr[j]);
    }
    swap(&arr[j], &arr[pivot]);
    return (j);
}

//FUNCTION QUICKSORT TO SORT A GIVEN ARRAY
void quickSort(int arr[], int low, int high,int pivot_type)
{
    if (low >= high)return;
    else
    {
        int pi = partition(arr, low, high,pivot_type);
        quickSort(arr, low, pi - 1,pivot_type);
        quickSort(arr, pi + 1, high,pivot_type);
    }
}

//A FUNCTION TO FIND MEDIAN OF THREE NUMBERS
int median(int arr[],int r,int s,int t){
    int lower;
    if((arr[r]<=arr[s] &&arr[r]>=arr[t] )|| (arr[r]<=arr[t]&&arr[r]>=arr[s]))lower=r;
    else if((arr[s]<=arr[t] &&arr[s]>=arr[r] )|| (arr[s]<=arr[r]&&arr[s]>=arr[t]))lower=s;
    else if((arr[t]<=arr[s] &&arr[t]>=arr[r] )|| (arr[t]<=arr[r]&&arr[t]>=arr[s]))lower=t;
    return lower;
}

//FUNCTION TO FIND THE CORRECT INDEX OF PIVOT
int pivot_finder(int arr[],int low,int high,int pivot_type){
    int type;
    int n=high+1-low;
    if(pivot_type==0){type=low;}
    else if(pivot_type==1){type=low+rand()%(high+1-low);}
    else if(pivot_type==2){type=median(arr,low,n/2+low,high);}
    else if(pivot_type==3){type=median(arr,low+n/4,low+n/2,3*n/4+low);}
    return type;
}
//FUNCTION TO PRINT THE ARRAY
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d   ", arr[i]);

}

int main()
{
    srand((unsigned int)time(NULL));
    int arr1[10000],arr2[100000];  //CREATING ARRAY OF 10^4 AND 10^5 SIZE
    int i,n,k;
    printf("                   PERFORMANCE OF QUICK SORT\n") ;
    printf("n       Pivot type         Random      Sorted      Almost Sorted\n");
    clock_t c1, c2,c3,c4,c5,c6;
    double runtime1,runtime2,runtime3,runtime4;
    n=10000;k=n/100;
// WHEN N=10^4
    for(i=0;i<n;i++){
        arr1[i] = rand() % 1000000000;  //ASSIGINING EVERY ELEMENTS OF AN ARRAY A RANDOM NUMBER
    }
    c1 = clock();
    quickSort(arr1,0,n-1,0);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr1,0,n-1,0);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr1[rand()%n],&arr1[rand()%n]);}  //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c1 = clock();
    quickSort(arr1,0,n-1,0);
    c2 = clock();
    runtime3 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    printf("10000     FIRST             %f       %f        %f\n",runtime1,runtime2,runtime3);  //PRINTING FOR FIRST PIVOT CASE

            //FOR SECOND PIVOT CASE -N =10^4
    for(i=0;i<n;i++){
        arr1[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(arr1,0,n-1,1);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr1,0,n-1,1);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr1[rand()%n],&arr1[rand()%n]);}         //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c1 = clock();
    quickSort(arr1,0,n-1,1);
    c2 = clock();
    runtime3 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    printf("10000    RANDOM             %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE

    //FOR THIRD PIVOT CASE -N =10^4
    for(i=0;i<n;i++){
        arr1[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(arr1,0,n-1,2);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr1,0,n-1,2);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr1[rand()%n],&arr1[rand()%n]);}         //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c1 = clock();
    quickSort(arr1,0,n-1,2);
    c2 = clock();
    runtime3 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    printf("10000  MEDIAN OF THREE 1    %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE

    //FOR FOURTH PIVOT CASE -N =10^4
    for(i=0;i<n;i++){
        arr1[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(arr1,0,n-1,3);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr1,0,n-1,3);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr1[rand()%n],&arr1[rand()%n]);}         //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c1 = clock();
    quickSort(arr1,0,n-1,3);
    c2 = clock();
    runtime3 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    printf("10000  MEDIAN OF THREE 2    %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE


    //FOR N=10^5

    n=100000;k=n/100;
    for(i=0;i<n;i++){
        arr2[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(arr2,0,n-1,0);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr2,0,n-1,0);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr2[rand()%n],&arr2[rand()%n]);}         //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(arr2,0,n-1,0);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("\n100000     FIRST            %f       %f        %f\n",runtime1,runtime2,runtime3);  //PRINTING FOR PIVOT OPTION 1

    //FOR N=10^5 -> SECOND PIVOT CASE
    for(i=0;i<n;i++){
        arr2[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(arr2,0,n-1,1);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr2,0,n-1,1);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr2[rand()%n],&arr2[rand()%n]);}         //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(arr2,0,n-1,1);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("100000     RANDOM           %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE

    //FOR N=10^5 -> THIRD PIVOT CASE
    for(i=0;i<n;i++){
    arr2[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(arr2,0,n-1,2);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr2,0,n-1,2);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr2[rand()%n],&arr2[rand()%n]);}         //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(arr2,0,n-1,2);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("100000  MEDIAN OF THREE 1   %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE

    //FOR N=10^5 -> FOURTH PIVOT CASE
    for(i=0;i<n;i++){
    arr2[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(arr2,0,n-1,3);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(arr2,0,n-1,3);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&arr2[rand()%n],&arr2[rand()%n]);}         //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(arr2,0,n-1,3);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("100000  MEDIAN OF THREE 2   %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE
    c6=clock();
    runtime4=(double)(c6 - c5) / (double)CLOCKS_PER_SEC;

                                                                            //FOR N=10^6 -> FIRST PIVOT CASE
    printf("\nSorting for n=10^6 is slow and might take some time. Do you wish to continue?('0 to exit, '1'to continue): ");
    int m;scanf("%d",&m);
    if(m==0)return 0;
    int *p;
    n=1000000;k=n/100;
    p=(int *)malloc(1000000*sizeof(int));
    for(i=0;i<1000000;i++){
        *(p+i)=rand()%1000000000;}
      c1 = clock();
    quickSort(p,0,n-1,0);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,0);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}       //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,0);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("\n1000000     FIRST            %f      %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE
                                                                                                    //FOR N=10^6-> SECOND PIVOT CASE
    for(i=0;i<n;i++){
        p[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(p,0,n-1,1);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,1);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}       //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,1);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("1000000     RANDOM           %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE
                                                                                //FOR N=10^6 -> THIRD PIVOT CASE
    for(i=0;i<n;i++){
    p[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(p,0,n-1,2);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,2);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}           //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,2);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("1000000  MEDIAN OF THREE 1   %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE

                                                                                    //FOR N=10^6 -> FOURTH PIVOT CASE

    for(i=0;i<n;i++){
    p[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(p,0,n-1,3);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,3);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}       //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,3);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("1000000  MEDIAN OF THREE 2   %f       %f        %f\n",runtime1,runtime2,runtime3); //PRINTING VALUES OF SORTED ALMOST SORTED RANDOM IN FOURTH PIVOT CASE




    printf("\nSorting for n=10^7 is too slow. Do you wish to continue?('0 to exit, '1'to continue): ");
    ;scanf("%d",&m);
    if(m==0)return 0;


                                                                                 //FOR N=10^7 -> FIRST PIVOT CASE
    n=10000000;k=n/100;
    p=(int *)malloc(10000000*sizeof(int));
    for(i=0;i<10000000;i++){
        *(p+i)=rand()%1000000000;}
      c1 = clock();
    quickSort(p,0,n-1,0);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,0);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}       //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,0);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("\n10000000     FIRST          %f       %f        %f\n",runtime1,runtime2,runtime3);
                                                                                        //FOR N=10^7 -> SECOND PIVOT CASE
    for(i=0;i<n;i++){
        p[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(p,0,n-1,1);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,1);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}       //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,1);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("10000000     RANDOM           %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE
                                                                                        //FOR N=10^7 -> THIRD PIVOT CASE
    for(i=0;i<n;i++){
    p[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(p,0,n-1,2);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,2);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}       //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,2);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("10000000  MEDIAN OF THREE 1   %f       %f        %f\n",runtime1,runtime2,runtime3);//PRINTING RANDOM,SORTED,ALMOST SORTED CASE
                                                                                            //FOR N=10^7 -> FOURTH PIVOT CASE
    for(i=0;i<n;i++){
    p[i] = rand() % 1000000000;
    }
    c1 = clock();
    quickSort(p,0,n-1,3);
    c2 = clock();
    runtime1 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    c1 = clock();
    quickSort(p,0,n-1,3);
    c2 = clock();
    runtime2 = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    for(i=0;i<k;i++){swap(&p[rand()%n],&p[rand()%n]);}       //SWAPPING K ELEMENTS OF THE ARRAY TO CREATE ALMOST SORTED ARRAY
    c3 = clock();
    quickSort(p,0,n-1,3);
    c4 = clock();
    runtime3 = (double)(c4 - c3) / (double)CLOCKS_PER_SEC;
    printf("10000000  MEDIAN OF THREE 2   %f       %f        %f\n",runtime1,runtime2,runtime3);  //PRINTING RANDOM,SORTED,ALMOST SORTED CASE



    return 0;


}
