
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numeroA, numeroB,resultado;
    printf("Introduzca primer numero: ");
    scanf("%d", &numeroA);
	printf("Introduzca segundo numero: ");
	scanf("%d", &numeroB);
	resultado = numeroA * numeroB;
	printf("El resultado de la multiplicacion es: %d\n",resultado);
	resultado = numeroA / numeroB;
	printf("El resultado de la division es: %d\n", resultado);
	resultado = numeroA % numeroB;
	printf("El resto es de: %d\n", resultado);
	return 0;
}
