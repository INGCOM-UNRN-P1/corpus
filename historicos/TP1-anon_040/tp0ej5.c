
#include <stdio.h>

int main(int argc, char *argv[]){
	int num1, num2;
	
	printf("ingrese numero: ");
	scanf("%d", &num1);
	
	printf("ingrese numero: ");
	scanf("%d", &num2);
	
	printf("\n\n");
	
	for(num1 ; num1 <= num2; num1++){
		printf("%d\n", num1);
	}

	return 0;
}