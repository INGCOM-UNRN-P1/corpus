
#include <stdio.h>

int division(int numero);
int combinatoria(int numero,int numerok);
int factorial(int numero);

int main()
{
	int numero;
	
	printf("ingrese un numero: ");
	scanf("%d",&numero);
	
	division(numero);
}

int division (int numero)
{
	int resultado=1;
	int numerok=1;
	
	while(numerok<numero)		
	{
		resultado=combinatoria(numero,numerok);
		printf("El resultado de la combinaria  n=%d y m=%d es: %d \n",numero,numerok,resultado);
		numerok +=1;

	}
	return resultado;
}

int factorial(int numero)
{
	int contador=1;
	int resultado=1;
	while (contador<=numero)
	{
		resultado=resultado*contador;
		contador=contador+1;
	}
	return resultado;
}

int combinatoria(int numero,int numerok)
{	
	int numerador;
	int denominador;
	int operacion1;
	int operacion2;
	int resultado_division;
	
	numerador=factorial(numero);
	
	operacion1=factorial(numerok);
	
	operacion2=numero-numerok;
	operacion2=factorial(operacion2);
	
	denominador=operacion2*operacion1;
	
	resultado_division=numerador/denominador;
	
	return resultado_division;

}