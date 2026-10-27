
#include <stdio.h>

int suma_lenta(int numero, int otronumero);

int main()
{
	int numero;
	int otronumero;
	printf("ingrese un numero para sumar: ");
	scanf("%d",&numero);
	printf("ingrese otro numero para sumar: ");
	scanf("%d",&otronumero);
 
 
	int resultado=suma_lenta(numero,otronumero);
	printf("%d", resultado); 
}

int suma_lenta(int numero, int otronumero)

{
	int contador=0;
	int resultado;
	while(otronumero>contador)
	{
		resultado=numero+1;
		numero=resultado;
		contador =contador + 1;
	}
	return resultado;
}

