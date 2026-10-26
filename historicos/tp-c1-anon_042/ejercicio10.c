



#include <stdio.h>
#include <stdlib.h>

int factorial(int numero){
	int i, factorial =1;
	for(i=1;i<=numero;i++)
	{
		factorial=factorial*i;
		
	}
	return factorial;
}

int main()
{
    int numero;
    int resultado;
    printf("Ingrese el numero. \n");
    scanf("%d", &numero);

    resultado = factorial(numero);
    printf("El factorial es %d \n", resultado);
    return 0;
}