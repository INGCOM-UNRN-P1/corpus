

#include <stdio.h>
int main()
{
	int ingreso;
	int factorial = 1;
	int contador = 2;
	
	printf("Ingrese el valor n: ");
	scanf("%d", &ingreso);

	
	while (contador <= ingreso)
	{
		factorial = factorial*contador;
		contador = contador + 1;
	}
	
	printf("El factorial de %d!: %d", ingreso, factorial);

}