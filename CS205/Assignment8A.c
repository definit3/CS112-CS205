/*NAME- VIVEK RAJ
  ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
int i,j,x,k,z=0;


void swap(int RPairs[][2],int i,int q){  //function to swap two nodes
        int temp[1][1];
        temp[0][0]=RPairs[i][0];
        RPairs[i][0]=RPairs[q][0];
        RPairs[q][0]=temp[0][0];

        temp[0][0]=RPairs[i][1];
        RPairs[i][1]=RPairs[q][1];
        RPairs[q][1]=temp[0][0];

}

void finder(int RPairs[][2],int R,int T1[],int T2[],int N){   //auxiliary function
    z=0;
    int p,m=0;
    for(p=i+1;p<R;p++){
        if(RPairs[i][0]==RPairs[p][0]||RPairs[i][0]==RPairs[p][1])z=p;
        if(RPairs[i][1]==RPairs[p][0]||RPairs[i][1]==RPairs[p][1])z=p;
        if(z!=0){
         for(x=0;x<N;x++)
                    {if(RPairs[z][0]==T1[x]||RPairs[z][0]==T2[x])m=1;
                     if(RPairs[z][1]==T1[x]||RPairs[z][1]==T2[x])m=1;}
        if(m!=1 && p<R-1)continue;
        if(p==R-1 &&z!=0)m=1;
        if(m==1 &&z!=0){swap(RPairs,i,p);break;}

    }

}}



void printTeams(int T1[],int T2[],int j,int k){   //function to print the players of team 1 and team 2
        printf("Team 1 has players: ");
        for(i=0;i<j;i++)printf("%d ",T1[i]);
        printf("\n");
        printf("Team 2 has players: ");
        for(i=0;i<k;i++)printf("%d ",T2[i]);
        printf("\n");
}


int removen(int arr[],int n){    //function to remove duplicate elements from an array
    int i,j,k;
     for (i = 0; i < n; i++) {
      for (j = i + 1; j < n;) {
         if (arr[j] == arr[i]) {
            for (k = j; k < n; k++) {
               arr[k] = arr[k + 1];
            }
            n--;
         } else
            j++;
      }
   }
   return n;

}


int main(){
	printf("Enter the number of players, N: ");      //taking value of N from the user
	int N;
	scanf("%d",&N);
	int arr[N];
	printf("Enter the players: (e.g. 1 2 3..): ");  //taking the players numbers from the user
	for(i=0;i<N;i++){scanf("%d",&arr[i]);}
	printf("Enter R, No of rivalry pairs: " );   //taking the number of rivalry pairs from the user
	int R;scanf("%d",&R);
	int RPairs[R][2];
	if(R!=0)printf("Enter the rivalry players (e.g. 1 2  3 4 ..): ");   //taking the rivalry pairs from the user


	for(i=0;i<R;i++){scanf("%d %d",&RPairs[i][0],&RPairs[i][1]);}
	int T1[30]={-100},T2[30]={-100};
	int count=0,counter=0;

    if(R==0){
        j=0;k=0;
        for(x=0;x<N;x++)
	        {
		       if(x%2==0){T1[j]=arr[x];j++;}
		       else {T2[k]=arr[x];k++;}
		       }
		         printTeams(T1,T2,j,k);return 0;
	}


	T1[0]=RPairs[0][0];T2[0]=RPairs[0][1];
	j=1;k=1;



	for(i=1;i<R;i++){

	         //checking if RPairs[i][0] is already in team 1 or team 2

        while(1){
	         for(x=0;x<N;x++)
                    {if(RPairs[i][0]==T1[x])count=1;
                    else if(RPairs[i][0]==T2[x])count=2;}
             if(count==1)
                     {T2[k]=RPairs[i][1];k++;count=0;z=0;break;}
             else if(count==2)
	                 {T1[j]=RPairs[i][1];j++;count=0;z=0;break;}

	          //checking if RPairs[i][1] is already in team 1 or team 2
	         for(x=0;x<N;x++)
                    {if(RPairs[i][1]==T1[x])count=1;
                    else if(RPairs[i][1]==T2[x])count=2;}
             if(count==1)
                    {T2[k]=RPairs[i][0];k++;count=0;z=0;break;}
             else if(count==2)
                    {T1[j]=RPairs[i][0];j++;count=0;z=0;break;}
             if(z!=0){T1[j]=RPairs[i][0];j++;T2[k]=RPairs[i][1];k++;z=0;break;}
             finder(RPairs,R,T1,T2,N);
             if(z==0){T1[j]=RPairs[i][0];j++;T2[k]=RPairs[i][1];k++;break;}
             else if(z==1)continue;

	         }


		  }

        //to distribute the remaining players in the two teams
        count=0;
        for(x=0;x<N;x++)
	        {
	                for(i=0;i<N;i++){

		       if(arr[x]==T1[i]||arr[x]==T2[i])count=1;}
		       if(count==0 && x%2==0){T1[j]=arr[x];j++;}
		       else if(count==0 && x%2!=0){T2[k]=arr[x];k++;}
		       else count=0;  }

	    k=removen(T2,k);
	    j=removen(T1,j);
	    //printing players of team1 and team 2
	 printTeams(T1,T2,j,k);

}
