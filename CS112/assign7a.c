#include <stdio.h>

float detrminant(float a[25][25], float k) {
 float s = 1, det = 0, b[25][25];
 int i, j, m, n, c;
 if (k == 1) {
  return (a[0][0]);
 } else {
  det = 0;
  for (c = 0; c < k; c++) {
   m = 0;
   n = 0;
   for (i = 0; i < k; i++) {
    for (j = 0; j < k; j++) {
     b[i][j] = 0;
     if (i != 0 && j != c) {
      b[m][n] = a[i][j];
      if (n < (k - 2))
       n++;
      else {
       n = 0;
       m++;
      }
     }
    }
   }
   det = det + s * (a[0][c] * detrminant(b, k - 1));
   s = -1 * s;
  }
 }

 return (det);
}
int main(){

float arr[25][25];
float n,q;
int i,j;
float d;

printf("Enter the size of the matrix(n X m) = ");
scanf("%f,%f", &n,&q);

for(j=1;j<=n;j++){
printf("Enter the elements of row %d = ", j);

for(i=1;i<=q;i++){
scanf("%f",&arr[j][i]);}}

if(n==q)printf("\nThe entered matrix is invertible.");
if(n!=q){printf("\nThe entered matrix is not invertible.");
	printf("\nThe entered matrix is not a square matrix.");}

   d = detrminant(arr, n);
   
   printf("%f",d);

  if (d == 0)

   printf("\nInverse of Entered Matrix is not possible\n");




return 0;}
