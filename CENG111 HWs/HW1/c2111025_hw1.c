#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	srand(time(NULL));
	
	int n, counter, counter2, bin, dec, mult, flag=1, rdn, a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0;
	char letter;
	
	do{
		counter = 1;
		printf("Enter number of letters for message: ");
		scanf("%d",&n);
	
		for(; n>0; n--){
			dec = 0;
			mult = 1;
			scanf("%d",&bin);
		
			for(counter2 = 0; counter2 < 3; counter2++){
				dec = dec + bin % 10 * mult;
				mult *= 2;
				bin = bin/10;
			}
		
		switch(dec){
			case 0:
				letter = 'A';
				a++;
				break;
			case 1:
				letter = 'B';
				b++;
				break;
			case 2:
				letter = 'C';
				c++;
				break;
			case 3:
				letter = 'D';
				d++;
				break;
			case 4:
				letter = 'E';
				e++;
				break;
			case 5:
				letter = 'F';
				f++;
				break;
			case 6:
				letter = 'G';
				g++;
				break;
			case 7:
				letter = 'H';
				h++;
				break;
			default:
				printf("You have entered a wrong binary number!");
				return 0;
			}
		rdn = rand()%8;
		printf("%d. encrypted letter is %c and random number is %d\n",counter,letter,rdn);
		counter++;
		
		}
	
	  	printf("Message has just taken...\nEnter 1 to continue and 0 to exit: ");
	  	scanf("%d",&flag);
	}while (flag == 1);
	
	printf("Number of letters after coding-> A: %d, B: %d, C: %d, D: %d, E: %d, F: %d, G: %d, H: %d",a,b,c,d,e,f,g,h);
	
	return 0;
	
}
