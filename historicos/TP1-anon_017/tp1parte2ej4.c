
#include <stdio.h>

int es_primo(int numero);

int main()
{	
	int numero;
	printf("ingrese un numero para ver si es primo: ");
	scanf("%d",&numero);
	if (numero<=1)
	{
	printf("el numero tiene que ser mayor a 1!");	
	}
	else
	{	
	numero=es_primo( numero);	
	}
}

int es_primo(int numero)

{
	int contador=1;
	int respuesta=0;
	while (contador<=numero)
	{
	if (numero%contador==0)
	{
	respuesta=respuesta+1;
	}
	contador=contador+1;
	}	
	if (respuesta==2)
	{
	printf("es primo");
	}
	else
	{
	printf("no es primo");
	}
	
}

 