/*NAME- VIVEK RAJ
 ROLL- 1601CS49*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct player{      //creating a structure to store the name and score of the players
	char name[20];
	int score;
};

void CountingSort(struct player players[],int n,int digit){   //FUNCTION COUNTING SORT- PART OF RADIX SORT
	int i;
	int count[10]={0};
	struct player last[n];   //creating an auxiliary array of structure player

	for(i=0;i<n;i++){
		count[(players[i].score/digit)%10]+=1;}   //storing the count of each digits

	int sum=count[0];
	for(i=1;i<10;i++){
		count[i]+=sum;
		sum=count[i];
	}

     i=n-1;
	 while(i >= 0)
    {
        last[count[ (players[i].score/digit)%10 ] - 1] = players[i];  //sorting a particular place of the numbers
        count[ (players[i].score/digit)%10 ]-=1;
        i--;
    }

    for(i=0;i<n;i++){
		players[i]=last[i];  //updating original score
	}
}

void swapname(struct player players[],int i,int j){    //FUNCTION TO SWAP THE NAMES
    struct player temp;
    temp=players[i];
    players[i]=players[j];
    players[j]=temp;
}

void namesort(struct player players[],int n){  //function to sort the names if the scores are same
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(players[i].score==players[j].score)
                {if(strcmp(players[i].name,players[j].name)>0)
                    swapname(players,i,j);
                }
        }
    }

}

void radixsort(struct player players[],int max,int n){   //radix sort- main driving function
    int digit;
    for (digit = 1; max/digit> 0; digit *= 10){  //running count sort for each place of the numbers
        CountingSort(players, n, digit);}  //calling counting sort

}

void printstats(struct player players[],int n){  //function to print the stats
    int i;
    printf("\n\n   Name     Score\n");
    for(i=0;i<n;i++){
        printf("   %s        %d\n",players[i].name,players[i].score);
    }
}


int main(){    //MAIN FUNCTION
	int i,n,max=0;
	printf("Enter the number of players: ");   //TAKING NO OF PLAYERS FROM THE USER
	scanf("%d",&n);
	struct player players[n];
	for(i=0;i<n;i++){
		printf("Enter the name of the player %d: ",i+1);  //TAKING NAME AND SCORE OF THE PLAYERS FROM THE USER
		scanf("%s",players[i].name);
		printf("Enter the score of the player %d: ",i+1);
		scanf("%d",&players[i].score);
		if(players[i].score>max)max=players[i].score;
	}
    radixsort(players,max,n);  //CALLING RADIX SORT
    namesort(players,n);   //CALLING NAME SORT
    printstats(players,n);  //PRINTING THE STATS


    return 0;}
