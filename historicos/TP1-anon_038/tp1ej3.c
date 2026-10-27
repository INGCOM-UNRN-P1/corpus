
#include <stdio.h>
 
int main(int argc, char *argv[])
{
	int numero_1;
	int numero_2;
	
	printf("Ingrese 2 numeros \n");
	scanf("%d", &numero_1);
	scanf("%d", &numero_2);

	int multiplicacion = numero_1 * numero_2;
	int division = numero_1 / numero_2;
	int resto = numero_1 % numero_2;
	
	printf("La multiplicacion da %d \n", multiplicacion);
	printf("La division da %d \n", division);
	printf("El resto da %d \n", resto);

	return 0;
}

