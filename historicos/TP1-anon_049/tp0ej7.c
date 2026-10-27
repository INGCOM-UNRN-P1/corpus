
#include <stdio.h>
 
int main(){
	int numero,i, factorial;
	printf("Ingrese un numero entero positivo: ");
	scanf("%d", &numero);

	while(numero > 0){
		
		factorial = 1;
		
		for(i= 1; i <= numero; i++){
			factorial = factorial * i;
		}
		printf("\nEl factorial de %d! es: %d ", numero, factorial);
		numero = numero - 1;
	}

	return 0;

}