
#include <stdio.h>


int compara(int numero, int otronumero);

int main()
{
	int numero;
	int otronumero;
	printf("ingrese un numero: ");
	scanf("%d",&numero);
	printf("ingrese otro numero: ");
	scanf("%d",&otronumero);
	
	int resultado=compara(numero,otronumero);
	printf("%d",resultado);
}

int compara (int numero,int otronumero)
{
	int resultado;
	if (numero==otronumero)
	{
	resultado = 0;
	}
	else if (numero<otronumero)
	{
	resultado= -1;
	}
	else if (numero>otronumero)
	{	
	resultado= 1;	
	}
	return resultado;
} 


