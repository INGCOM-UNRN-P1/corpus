
#include <stdio.h>

int sumaLenta(int num1, int num2);

int main(int argc, char *argv[])
{
	
	int num1;
	int num2;
	int resultado;

	printf( "\n Ingrese un numero: " );
	scanf( "%d", &num1 );
	printf( "\n Ingrese otro numero: " );
	scanf( "%d", &num2 );

	resultado = sumaLenta(num1, num2);
	printf(" \n Resultado suma lenta: %d ",resultado);

}

int sumaLenta(int numero, int otronumero)
{
	    while (otronumero != 0)
		{			
			if (otronumero < 0)
			{
				otronumero = otronumero + 1;
				numero -=1;
			}
			if (otronumero > 0)
			{
				otronumero = otronumero -1;
				numero += 1;    
			}
		}				
	return numero;
}

