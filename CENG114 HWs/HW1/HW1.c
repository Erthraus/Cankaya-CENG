#include <stdio.h>

float hp, mp, fp;                  //GLobal Variables for percentages
void setPercentages(void);
float setHomeworkPercentage(void);
float setMidtermPercentage(void);
float setFinalPercentage(void);
int getTotalGrade(int x, int y, int z);
char getLetterGrade(int x);

/* MAIN FUNCTION */

int main(void)
{
	char flag;
	int x, y, z, t1, t2, t3, i=0;
	float sumt1 = 0, sumt2 = 0, sumt3 = 0;
	printf("Welcome to course grading system!\n");
	setPercentages();
	do{
		printf("(Student%d) Enter homework, midterm and final grades for first course: ", i+1);     //You need to enter all three notes before pressing enter!
		scanf(" %d %d %d", &x, &y, &z);
		t1 = getTotalGrade(x, y, z);
		sumt1 += t1;
		printf("(Student%d) Enter homework, midterm and final grades for second course: ", i+1);
		scanf(" %d %d %d", &x, &y, &z);
		t2 = getTotalGrade(x, y, z);
		sumt2 += t2;
		printf("(Student%d) Enter homework, midterm and final grades for third course: ", i+1);
		scanf(" %d %d %d", &x, &y, &z);
		t3 = getTotalGrade(x, y, z);
		sumt3 += t3;
		printf("(Student%d) Grade for first course is: %c (%d)\n", i+1, getLetterGrade(t1), t1);
		printf("(Student%d) Grade for first course is: %c (%d)\n", i+1, getLetterGrade(t2), t2);
		printf("(Student%d) Grade for first course is: %c (%d)\n", i+1, getLetterGrade(t3), t3);
		i++;
		while(1)
		{
			printf("\nDo you want to enter an another student? (y/n): ");
			scanf(" %c", &flag);
			if(flag != 'y' && flag != 'n')
				printf("You have entered a wrong character!");
			else 
				break;
		}
		
		
	}while(flag != 'n');	

	printf("\nFirst course average: %f", sumt1/i);
	printf("\nFirst second average: %f", sumt2/i);
	printf("\nFirst third average: %f\nBye!", sumt3/i);
	return 0;
}

/* OTHER FUNCTIONS */

void setPercentages(void)
{
	printf("Please set homework, midterm and final percentages first:\n");
	
	do{	
		hp = setHomeworkPercentage();
		mp = setMidtermPercentage();
		fp = setFinalPercentage();
		if(hp + mp + fp != 100)
			printf("Sum of the percentages are not 100! Please re-enter!\n");
		else
			break;
	}while(1);
	
	printf("Done.\n\n");
}

float setHomeworkPercentage(void)
{
	float x;
	do{
		printf("Please enter homework percentage: ");
		scanf("%f", &x);
		if(x<0 || x>100)
			printf("You have entered a wrong number!\n");
		else
			break;
	}while(1);
	
	return(x);
}

float setMidtermPercentage(void)
{
	float x;
	do{
		printf("Please enter midterm percentage: ");
		scanf("%f", &x);
		if(x<0 || x>100)
			printf("You have entered a wrong number!\n");
		else
			break;
	}while(1);
	
	return(x);
}

float setFinalPercentage(void)
{
	float x;
	do{
		printf("Please enter final percentage: ");
		scanf("%f", &x);
		if(x<0 || x>100)
			printf("You have entered a wrong number!\n");
		else
			break;
	}while(1);
	
	return(x);
}

int getTotalGrade(int x, int y, int z)
{
	float t = (x*hp + y*mp + z*fp)/100;
	return((int)t);
}

char getLetterGrade(int x)
{
	if(x>=90)
		return('A');
	else if(x>=75)
		return('B');
	else if(x>=60)
		return('C');
	else if(x>=45)
		return('D');
	else
		return('F');
}
