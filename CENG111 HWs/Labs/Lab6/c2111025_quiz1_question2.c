#include <stdio.h>

int main(){
    int temp,hum;
    scanf(" %d %d",&temp,&hum);
    if(temp>30 && hum>20)
        printf("Swim");
    else if(temp>30 && hum<=20)
        printf("Play Tennis");
    else if(temp<=30 && hum<=20)
        printf("Play Basketball");
    else if(temp<=30 && hum>20)
        printf("Watch TV");
    else
        printf("Do nothing");
    
    return 0;
}