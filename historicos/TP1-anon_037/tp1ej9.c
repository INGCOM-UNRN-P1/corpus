

#include <stdio.h>
int main()
{
	int ingreso;
	int limite = 100;
	int interruptor = 1;
	
	while (interruptor == 1)
	{
		printf("Ingrese un numero->");
		scanf("%d", &ingreso);
		
		if (ingreso > limite)
		{
			printf("El numero ingresado es mayor a 100.");
			interruptor = 0;
		}
		
		else if (ingreso == limite)
		{
			printf("El numero ingresado es igual a 100.");
			interruptor = 0;
		}
		
		else
		{
			printf("El numero ingresado es menor a 100.\n");
		}
	}
}