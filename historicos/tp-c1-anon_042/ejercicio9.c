



#include <stdio.h>
#include <stdlib.h>

int es_multiplo(int numero,int multiplo){
	while(multiplo >= numero){
		multiplo = multiplo - numero;
	}
	if (multiplo == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main()
{
    int numero, multiplo;
    int resultado;
    printf("Ingrese el numero. \n");
    scanf("%d", &numero);
	printf("Ingrese el multiplo. \n");
    scanf("%d", &multiplo);

    resultado = es_multiplo(numero, multiplo);
    printf("[1]si [0]no => el resultado es %d \n", resultado);
    return 0;
}