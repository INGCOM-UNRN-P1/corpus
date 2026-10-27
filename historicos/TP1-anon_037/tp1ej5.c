

#include <stdio.h>
int main()
{
	int numero_uno;
	int numero_dos;
	int contador;
	
	printf("Ingrese un numero entero ");
	scanf("%d", &numero_uno);
	
	printf("Ingrese otro numero ");
	scanf("%d", &numero_dos);

	if (numero_uno > numero_dos)
	{
		contador = numero_dos;
		
		while (contador <= numero_uno)
		{
			printf("%d \n", contador);
			contador = contador + 1;
		}
	}
	else if (numero_uno < numero_dos)
	{
		contador = numero_uno;
		
		while (contador <= numero_dos)
		{
			printf("%d \n", contador);
			contador = contador + 1;
		}
	}
	else
	{
		printf("Son iguales");
	}
}