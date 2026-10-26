/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>
int main()
{
	int ingreso;
	int limite = 100;
	int auxiliar = 2;
	int resto;

	printf("Ingrese un numero entero mayor a 100 ->");
	scanf("%d", &ingreso);

	if (ingreso > limite)
	{
		while (auxiliar <= 6)
		{
			resto = ingreso%auxiliar;
			printf("Es multiplo de %d:", auxiliar);
		
			if (resto == 0)
			{
				printf("SI\n");
			}
			else
			{
				printf("NO\n");
			}

			auxiliar = auxiliar + 1;
		}
	}
	else
	{
		printf("El numero ingresado es incorrecto");
	}

}