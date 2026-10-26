/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>

int compara(int numero, int otronumero);
 
int main(int argc, char *argv[])
{

int numero1,numero2, resultado;

printf("\n Ingrese el primer valor :");

scanf("%d",&numero1);

printf("\n Ingrese el segundo valor :");

scanf("%d",&numero2);

resultado = compara(numero1,numero2);

switch (resultado)
{
	case -1:
	
		printf("\n\n El numero |%d| es menor a |%d|\n",numero1,numero2);
		
	break;
	
	case 0:
		
		printf("\n\n Los numeros ingresados son iguales\n");
		
	break;
	
	case 1:
		
		printf("\n\nEl numero |%d| es mayor a |%d|\n",numero1,numero2);
		
	break;
}

return 0;
}

int compara(int numero, int otronumero)
{
	
int quienmayor;
	
if (numero > otronumero)
{
	
	quienmayor = 1;
	
}
else if (numero < otronumero)
{
	
	quienmayor = -1;
	
}
else
{
	
	quienmayor = 0;
	
}

return quienmayor;
}