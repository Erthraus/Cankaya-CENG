#include <stdio.h>

void add(int a, int b){
	printf("sum= %d",a+b);
}

void subs(int a, int b){
	printf("substraction= %d",a-b);
}

void div(int a, int b){
	printf("division= %d",a/b);
}

void mult(int a, int b){
	printf("multiplication of numbers= %d",a*b);
}

int main(void){
	int x,y;
	char op;
	
	do{
		printf("Enter an operator (+, -, *,/): ");
		scanf(" %c", &op);
		if(op == '.')
			return 0;
		printf("Enter two operands: ");
		scanf("%d %d", &x, &y);
		switch(op){
			case '+':
				add(x,y);
				printf("\n");
				break;
			case '-':
				subs(x,y);
				printf("\n");
				break;
			case '*':
				mult(x,y);
				printf("\n");
				break;
			case '/':
				div(x,y);
				printf("\n");
				break;
		
		}
	}while(1);

}
