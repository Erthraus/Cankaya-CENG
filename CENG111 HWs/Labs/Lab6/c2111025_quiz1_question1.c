#include <stdio.h>

int main(){
    int enter,exit;
    char type;
    scanf(" %c %d %d",&type,&enter,&exit);
    switch(type){
        case 'B':
            if(exit-enter<=2)
                printf("%.2f $",(exit-enter)*1);
            else
                printf("%.2f $",(exit-enter-2)*2.30+2);
            break;
        case 'C':
            if(exit-enter<=3)
                printf("Free");
            else
                printf("%.2f $",(exit-enter-3)*1.50);
            break;
        default:
            printf("You have entered a wrong character!");
            break;
    }
    
    
    return 0;
}