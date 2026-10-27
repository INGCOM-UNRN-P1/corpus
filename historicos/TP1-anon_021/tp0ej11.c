
#include <stdio.h>
 
int suma_lenta(int numero, int otronumero);
 
int main(int argc, char *argv[])
{
int numero1, numero2, resultado;

printf("\ningrese el primer valor : ");

scanf("%d",&numero1);

printf("\ningrese el valor2 : ");

scanf("%d",&numero2);

resultado = suma_lenta(numero1,numero2);

printf("\nel resultado de la suma es |%d|",resultado);

return 0;
}

int suma_lenta(int numero, int otronumero)
{
int suma;

suma = numero + otronumero;

if (suma > numero)
{
	
	while (numero <= suma)
	{
		
		printf("|%d|\n",numero);
	
		numero = numero + 1;
	
	}
	
}
else
{
	
	while(numero >= suma)
	{
	
		printf("|%d|\n",numero);
	
		numero = numero - 1;
	
	}
}
return suma;	
}