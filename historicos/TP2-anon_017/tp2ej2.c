

#include <stdio.h>

int multi(int numero,int numero2);
int potencia(int numero_1,int numero_2);


int main()
{
	int numero;
	int numero2;
	int numero_1;
	int numero_2;
	long long int resultado;
	long long int resultado2;
	
	
	printf ("ingrese un numero para multiplicar: ");
	scanf("%d",&numero);
	printf ("ingrese el numero por el cual se multiplicara: ");
	scanf("%d",&numero2);
	
	resultado=multi( numero,numero2);
	printf ("el resultado de la multiplicacion es : %lli \n",resultado);

	printf ("ingrese un numero para su potencia: ");
	scanf("%d",&numero_1);
	printf ("ingrese el exponente: ");
	scanf("%d",&numero_2);
	
	resultado2=potencia(numero_1,numero_2);
	printf ("el resultado de la multiplicacion es : %lli",resultado2);
	
	
}

int multi(int numero,int numero2)
{
	long long int resultado=0;
	while (numero != 0)
	{
		resultado=resultado+numero2;
		numero -=1;
	}
	return resultado;
}
int potencia(int numero_1,int numero_2)
{
	long long int resultado2=numero_2;
	int contador=numero_1;
	contador -=1;
	
	while (contador>0)
	{
		resultado2=multi( numero_1,resultado2);
		contador -=1;
	}
	return resultado2;
	
	
}