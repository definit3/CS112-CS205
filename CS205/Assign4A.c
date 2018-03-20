/*NAME - VIVEK RAJ
   ROLL- 1601CS49
   24/08/2017*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct patient{      //CREATING A STRUCTURE OF PATIENT'S NAME, TIME, PRIORITY AND SIMILARITY TO DOC NAME
    char names[30];
    int priority;
    float time;
    int compare[200];
};



void rearrange(struct patient number[],int x,int *n){   //FUNCTION TO REAARANGE THE STRUCTURE OF ARRAY AFTER THE PATIENT IS checked
    int i;
    number[x]=number[x+1];
    x=x+1;
    if(x==(*n-1)){*n=*n-1;return;}
    rearrange(number,x,n);

}

int m_priority(float *time,int n,struct patient number[]){  //function to find the priority of the patients dynamically
    int max_index=0,i,count=0;
    float new_time=100;
    for(i=0;i<n;i++){
        if(number[i].time<=*time)count=1;
        else if(number[i].time<new_time){new_time=number[i].time;}}
    if(count!=1)*time=new_time;
    count=0;
    for(i=0;i<n;i++){
        if(number[i].time<=*time)
            {if(number[i].priority>number[max_index].priority || count==0){max_index=i;count=1;}
            }}

    return max_index;
}

void true_line(float count_time,int n,struct patient number[]){   //function to print and find the next correct order
    int max_priority=m_priority(&count_time,n,number);
    printf("%s : %.2f\n",number[max_priority].names,count_time);
    if(n==1)return;
    count_time+=0.10;
    rearrange(number,max_priority,&n);
    true_line(count_time,n,number);


}


void time_sort(struct patient number[],int n){    //function to sort the entered time
    int i,j;struct patient localtime;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(number[i].time>number[j].time){
                localtime=number[i];
                number[i]=number[j];
                number[j]=localtime;
            }
        }
    }
}

int main(){     //main function
    printf("Enter the number of patients: ");          //taking number of patients from the user
	int n,i,j,count=0,counter=0;
	float count_time=8.0;
	char docname[20];
	scanf("%d",&n);
	struct patient number[n];
	printf("Enter the names of the patients: ");    //taking name of patients from the user
	for(i=0;i<n;i++){
		scanf("%s",number[i].names);
	}
	printf("Enter the time of arrival of patients   RESPECTIVELY   in 24 hr format (e.g. type 14.30 for 02:30 pm): ");  //taking the time of the arrival of patients from the user
	for(i=0;i<n;i++){
		scanf("%f",&number[i].time);
		if(number[i].time<8.0)count=1;
		else{if(counter==0){count_time=number[i].time;counter=1;}if(number[i].time<count_time)count_time=number[i].time;}
	}
	if(count==1)count_time=8.0;
	printf("Enter the doctor's name: ");
	scanf("%s",docname);printf("\n");   //taking the name of doctor from the user
	int doccomp[200];
	for(i=0;i<200;i++){doccomp[i]=0;}
	for(i=0;i<strlen(docname);i++){
        doccomp[(int)tolower(docname[i])]=1;
	}

	for(i=0;i<n;i++){
            for(j=0;j<200;j++){
                number[i].compare[j]=0;
            }
            number[i].priority=0;
            for(j=0;j<strlen(number[i].names);j++){
                number[i].compare[(int)tolower(number[i].names[j])]=1;}
            for(j=0;j<200;j++){
                if(doccomp[j]==number[i].compare[j] &&doccomp[j]==1)number[i].priority+=1;}
    }
    time_sort(number,n);  //sorting the entered time of arrival of patients
    printf("Doc will see the patients in the following order and time:\n");
    true_line(count_time,n,number);  //finding the correct order



return 0;}
