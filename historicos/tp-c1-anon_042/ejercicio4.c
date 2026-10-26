



#include <stdio.h>
#include <stdlib.h>

int compara(int numero,int otro_numero){
	int resultado;
	if (numero - otro_numero > 0){
		resultado = 1;
	}
	else if(numero - otro_numero < 0){
		resultado = -1;
	}
	else if(numero - otro_numero == 0){
		resultado = 0;
	}
	return resultado;
}

int main()
{
	int numero, otro_numero, resultado;
    printf("Ingrese un numero. \n");
	scanf("%d", &numero);
	printf("Ingrese otro numero. \n");
	scanf("%d", &otro_numero);
	
	resultado = compara(numero, otro_numero);
	printf("%i. \n", resultado);
    return 0;
}