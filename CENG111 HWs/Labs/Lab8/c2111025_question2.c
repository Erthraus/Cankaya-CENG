#include <stdio.h>

int main(void){
	int grd, cls, sum=0, counter=0, counter2=0;
	float avg;
	for(;counter<20;counter++){
		printf("Input the grade and class of the student: ");
		scanf("%d%d",&grd,&cls);
		if(cls==3){
			sum = sum + grd;
			counter2++;
		}
			
			
	}
	avg=sum/counter2;
	printf("Average grade of the 3rd year students: %.2f",avg);
	
	return 0;
	
}
