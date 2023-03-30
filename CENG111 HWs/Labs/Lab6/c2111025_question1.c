#include <stdio.h>

int main(){
    int x;
    scanf("%d",&x);
    switch(x){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("Number of days in %d. month is 31",x);
            break;
        case 2:
            printf("Number of days in %d. month is 28",x);
            break;
        case 4: case 6: case 9: case 11:
            printf("Number of days in %d. month is 30",x);
            break;
        default:
            printf("You have entered an invalid month!");
            break;
    }
    return 0;
}