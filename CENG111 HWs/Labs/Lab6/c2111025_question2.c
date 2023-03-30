#include <stdio.h>

int main(){
    double x;
    char ch;
    scanf(" %c %lf",&ch,&x);
    switch(ch){
        case 'C':
            printf("Temperature in Celcius: %.2f",(x-32)*5/9);
            break;
        case 'F':
            printf("Temperature in Fahrenheit: %.2f",(x*9/5)+32);
            break;
        default:
            printf("You have entered a wrong character!");
            break;
    }
    
    
    return 0;
}