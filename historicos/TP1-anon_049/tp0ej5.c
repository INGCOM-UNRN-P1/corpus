
#include <stdio.h>
 
int main(){
	int numero1, numero2, i;
	printf("Ingrese un primer numero: ");
	scanf("%d", &numero1);
	
	printf("\nIngrese un segundo numero: ");
	scanf("%d", &numero2);
	
	for(numero1; numero1 <= numero2; numero1++){
		printf("%d\n",numero1);
	}
	return 0; 
}
