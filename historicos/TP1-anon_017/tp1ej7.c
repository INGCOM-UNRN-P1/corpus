/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int main()

{
	int numero;
	int contador;
	int resultado=1;
	printf("ingrese un numero para su saber su factorial: ");
	scanf("%d",&numero);
	contador=1;
	
	while (contador<=numero)
	{
		resultado=resultado*contador;
		contador=contador+1;	
	}	
	printf("el factorial de %d es : ",numero);
	printf("%d \n",resultado);
	contador=contador-1;
	
	while (contador>0)
	{
		resultado=resultado/contador;
		contador=contador-1;
		printf("el factorial de %d es : ",contador);
		printf("%d \n",resultado);
	}

}

 