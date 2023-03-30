#include <stdio.h>

int main(){
    int age;
    scanf("%d",&age);
    if(age<18)
        printf("Child");
    else if(age<=30)
        printf("Young");
    else if(age>30)
        printf("Mature");
    else
        printf("You have entered a wrong integer");
   
   
   
   return 0;
   
}