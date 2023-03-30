#include <stdio.h>

int main(void){
	double km,lt,ppl;
	
	printf("Input total distance in km= ");
	scanf("%lf",&km);
	printf("Input total fuel spent in liters= ");
	scanf("%lf",&lt);
	printf("Input fuel price per liter= ");
	scanf("%lf",&ppl);
	printf("Average consuption(lt/km)= %.3f\nFuel cost per 100 km= %.2f$",lt/km,lt/km*100*ppl);
	
	return(0);
	
}
