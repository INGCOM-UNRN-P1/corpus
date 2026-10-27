
#include <stdio.h>

int factorial(int numero);
int division(int numero,int numerok);

int main()

{
	int numero;
	int numerok;
	int resultado_division;
	
	printf("ingrese un numero : ");
	scanf("%d",&numero);
	
	printf("ingrese un numero menor o igual al primero: ");
	scanf("%d",&numerok);
	
	if (numerok<=numero)
	{
		resultado_division=division(numero,numerok);
		printf("el resultado de la combinatoria es :%d",resultado_division);
	}
	else
	{
		printf("%d,no es menor o igual a %d !",numerok,numero);
	}
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

int division(int numero,int numerok)
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