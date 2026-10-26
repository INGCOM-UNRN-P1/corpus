



#include <stdio.h>
#include <stdlib.h>

int suma_lenta(int numero,int otro_numero){
	int c = 0;
	while (c < otro_numero){
		numero = numero + 1;
		c = c+1;
	}
	return numero;
}

int main()
{
	int numero, otro_numero;
    printf("Ingrese un numero. \n");
	scanf("%d", &numero);
	printf("Ingrese otro numero. \n");
	scanf("%d", &otro_numero);
	
	int resultado = suma_lenta(numero, otro_numero);
	printf("%i. \n", resultado);
	
    return 0;
}