
#include <stdio.h>

int multiplo(int numero);

 int main(int argc, char *argv[])
{
	int num;
	printf("Ingrese un entero A mayor a 100: \n");
	scanf("%d",&num);
	printf("Numero: A = %d \n", num);
	int resultado = multiplo(num);
	return 0;
}

int multiplo(int numero)
{
    if(numero>100)
	{
		if (numero%2==0)
		{
			printf("Es multiplo de 2: SI \n");
		}
		else
		{
			printf("Es multiplo de 2: NO \n");
		}
		
		if (numero%3==0)
		{
			printf("Es multiplo de 3: SI \n");
		}
		else
		{
			printf("Es multiplo de 3: NO \n");
		}
		
		if (numero%4==0)
		{
			printf("Es multiplo de 4: SI \n");
		}
		else
		{
			printf("Es multiplo de 4: NO \n");
		}
		
		if (numero%5==0)
		{
			printf("Es multiplo de 5: SI \n");
		}
		else
		{
			printf("Es multiplo de 5: NO \n");
		}
		
		if (numero%6==0)
		{
			printf("Es multiplo de 6: SI \n");
		}
		else
		{
			printf("Es multiplo de 6: NO \n");
		}
	}
	return 0;
}