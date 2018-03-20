/*NAME - VIVEK RAJ
   ROLL- 1601CS49
   26/08/2017*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int binarr1[100],binarr2[100],count1=1,count2=1,i=0,arr[100];      //DECLARING GLOBAL VARIABLES
int sum[100],sum2[100],count=0;

void convertBinary1(int n1){       //FUNCTION TO CONVERT NUMBER 1 INTO BINARY
    if(n1<2){
		arr[i]=n1%2;
		int j=0;
		for(i=count1-1;i>=0;i--){binarr1[j]=arr[i];j++;}
		return;}
	arr[i]=n1%2;
	n1=n1/2;
	i++;count1++;
	convertBinary1(n1);
}

void convertBinary2(int n2){    //FUNCTION TO CONVERT NUMBER 2 INTO BINARY
    if(n2<2){
		arr[i]=n2%2;
		int j=0;
		for(i=count2-1;i>=0;i--){binarr2[j]=arr[i];j++;}
		return;}
	arr[i]=n2%2;
	n2=n2/2;
	i++;count2++;
	convertBinary2(n2);
}

int equaliser(int ar1[],int ar2[],int *count1,int *count2){   //FUNCTION TO EQUALISE THE BITS OF TWO BINARY NUMBERS
    int temp1[100];int temp2[100];
    for(i=0;i<*count1;i++)temp1[i]=ar1[i];
    for(i=0;i<*count2;i++)temp2[i]=ar2[i];
    if(*count1>*count2){
        int differ;
        differ=*count1-*count2;
        for(i=0;i<differ;i++){ar2[i]=0;}
        int j=0;*count2=*count1;
        for(i;i<*count2;i++){ar2[i]=temp2[j];j++;}
    }
    else{
        int differ;
        differ=*count2-*count1;
        for(i=0;i<differ;i++){ar1[i]=0;}
        int j=0;*count1=*count2;
        for(i;i<*count2;i++) {ar1[i]=temp1[j];j++;}
    }
    return *count2;   //returning the count of equalised bits.

}


int *summation(int x[],int y[],int cnt){        //FUNCTION TO RETURN THE SUM OF TWO BINARY NUMBERS
	int carry=0;
	int j=0;
	count=0;
    i=cnt-1;
	while(i>=0){
		if(x[i]==0 && y[i]==0 && carry==0){
			sum[j] = 0;
			carry = 0;
		}
        else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==0){
			sum[j] = 1;
			carry = 0;
		}
		else if(x[i]==0 && y[i]==0 && carry==1){
                        sum[j] = 1;
                        carry = 0;
                }
        else if(x[i]==1 && y[i]==1 && carry==0){
			sum[j] = 0;
			carry = 1;
		}

		else if(((x[i]==1 && y[i]==0)||(x[i]==0 && y[i]==1)) && carry==1){
                        sum[j] = 0;
                        carry = 1;
                }

		else if(x[i]==1 && y[i]==1 && carry==1){
                        sum[j] = 1;
                        carry = 1;
                }
        j++;count+=1;i--;}
        if(carry==1){sum[j]=1;count+=1;};
          int k=0;
        for(i=count-1;i>=0;i--){
            sum2[k]=sum[i];
            k++;
        }

}


long long int multiplication(int arr1[],int arr2[],int cnt1, int cnt2){     //Function to find the product of two given numbers efficiently
    int length;int n1,n2,j;
    int Xl[100],Xr[100],Yl[100],Yr[100],XlXr[100],YlYr[100],countxlxr,countylyr;

    length=equaliser(arr1,arr2,&cnt1,&cnt2);
    if(length==0)return 0;
    if(length==1){return arr1[0]*arr2[0];}

    n1=length/2;n2=length-length/2;
    cnt1=n1;cnt2=n2;

    for(i=0;i<n1;i++){Xl[i]=arr1[i];}
    for(i=0;i<n1;i++){Yl[i]=arr2[i];}
    j=0;
    for(i=n1;i<length;i++){Xr[j]=arr1[i];j++;}
    j=0;
    for(i=n1;i<length;i++){Yr[j]=arr2[i];j++;}


    long long int product1,product2,product3,fproduct;

    product1=multiplication(Xl,Yl,n1,n1);

    product2=multiplication(Xr,Yr,n2,n2);

    int f=length-length/2;
    int v=length/2;

    int c1=equaliser(Xl,Xr,&v,&f);
     f=length-length/2;
     v=length/2;

    int c2=equaliser(Yl,Yr,&v,&f);

    summation(Xl,Xr,c1);
    countxlxr=count;
    for(i=0;i<count;i++){XlXr[i]=sum2[i];}
    summation(Yl,Yr,c2);
    countylyr=count;
    for(i=0;i<count;i++){YlYr[i]=sum2[i];}
    product3=multiplication(XlXr,YlYr,countxlxr,countylyr);

    length=length-length/2;
    fproduct=product1*pow(2,2*length);
    fproduct=fproduct+((product3-product1-product2)*pow(2,length));
    fproduct=fproduct+product2;
    return fproduct;   //returning the value of final product
}

int main(){     //MAIN FUNCTION
    int n1,n2;
    printf("Enter number 1: ");   //taking the value of no1 from the user
    scanf("%d",&n1);
    printf("Enter number 2: ");   //taking the value of no2 from the user
    scanf("%d",&n2);
    convertBinary1(n1);    //converting no1 into binary
    i=0;convertBinary2(n2);  //converting no2 into binary
    printf("\nProduct of the entered numbers: %lld\n",multiplication(binarr1,binarr2,count1,count2));  //printing the product of given numbers

return 0;}
