
#include <stdio.h>

int main(int argc, char *argv[])

{
	int numero;
	printf("ingrese un numero para comprobar si es mayor a 100: ");
	scanf("%d",&numero);

	if (numero<100)
	{
		printf("el numero es menor a 100 \n");
		while(numero<100)
		{
			printf("ingrese otro numero para comprobar si es mayor a 100: ");
			scanf("%d",&numero);
		}
	printf("el numero es mayor a 100!");
	}	
	else
	{
		printf("el numero ingresado es mayor a 100");
	}
}

 