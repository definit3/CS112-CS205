/*NAME - VIVEK RAJ
   ROLL- 1601CS49
   26/08/2017*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int p1[16][16];

void MultiplyMatrix(int m1[16][16],int m2[16][16],int r1,int r2){  //function to find the product of the entered matrix
    int i,j,k;
    for(i=0;i<r1;i++){
        for(j=0;j<r2;j++){
            p1[i][j]=0;
        }
    }
     i=0;
     while(i<r1){
        for(j=0;j<r2;j++){
            for(k=0;k<r2;k++){
                p1[i][j]=p1[i][j]+m2[k][j]*m1[i][k];
            }
        }
        i++;
    }
}

void printmatrix(int p1[16][16],int r){   //function to print the entered matrix
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            printf("%d ",p1[i][j]);
        }
    }
}

int main(){   //MAIN FUNCTION
    int matrix1[16][16],matrix2[16][16];
    int i,j,k;
    int r1,c1,r2,c2;
    printf("Enter the rows and columns of square Matrix 1 (separated by space): ");  //taking the value of rows and columns of matrix 1 from the user
    scanf("%d %d",&r1,&c1);
    printf("Enter the rows and columns of square Matrix 2 (separated by space): ");  //taking the value of rows and columns of matrix 2 from the user
    scanf("%d %d",&r2,&c2);
    if(c1!=r2){printf("\nMultiplication of the entered Matrix is not possible.\n");return 0;}
    printf("Enter the elements of Matrix 1 (separated by space): ");//taking the elements of the matrix 1 from the user
    for(i=0;i<r1;i++){
        for(j=0;j<c1;j++){
            scanf("%d",&matrix1[i][j]);}}
    printf("Enter the elements of Matrix 2 (separated by space): "); //taking the elements of matrix 2 from the user
    for(i=0;i<r2;i++){
        for(j=0;j<c2;j++){
            scanf("%d",&matrix2[i][j]);}}

    MultiplyMatrix(matrix1,matrix2,r1,r2);
    printf("Elements of the product Matrix : ");  //printing the product of the matrix
    printmatrix(p1,r1);

}
