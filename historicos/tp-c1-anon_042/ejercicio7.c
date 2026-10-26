



#include <stdio.h>
#include <stdlib.h>

int es_primo(int numero){
	int contador = 0;
	for(int i = 1; i<=numero; i++){
		if(numero%i==0){
			contador = contador + 1;
		}
	}
	if (contador == 2){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
    int numero;
    int resultado;
    printf("Ingrese el numero. \n");
    scanf("%d", &numero);

    resultado = es_primo(numero);
    printf("%d \n", resultado);
    return 0;
}