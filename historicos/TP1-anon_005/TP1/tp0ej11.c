
#include <stdio.h>
 
int suma_lenta(int num1, int num2);

int main(int argc, char *argv[])
{
	int numero_uno;
	int numero_dos;
	printf("Ingrese un numero natural, Num1: \n");
	scanf("%d",&numero_uno);
	printf("Ingrese otro numero natural, Num2: \n");
	scanf("%d",&numero_dos);
	int resultado = suma_lenta(numero_uno, numero_dos);
	return 0;
}

int suma_lenta(int num1, int num2)
{	
	int i;
	int suma = num1;
	if(num2 == 0)
	{
		printf("Suma: %d + %d = %d \n", num1, num2, num1);
	}
	else if(num1 == 0)
	{
		printf("Suma: %d + %d = %d \n", num1, num2, num2);
	}
	else if((num1 > 0) && (num2 > 0))
	{
		for(i=1; i<num2+1; i++)
		{
			suma = suma+1;
		}
		printf("Suma: %d + %d = %d \n", num1, num2, suma);
	}
	else
	{
		if(num1 < 0)
		{
			printf("El primer numero ingresado no es valido. \n");
		}
		if(num2 < 0)
		{
			printf("El segundo numero ingresado no es valido. \n");
		}
	}
	return 0;
}