
#include <stdio.h>

int compara(int num1, int num2);

int main(int argc, char *argv[])
{
   int num1;
   int num2;
   int resultado;

   printf( "\n Ingrese un numero: " );
   scanf( "%d", &num1 );
   
   printf( "\n Ingrese otro numero: " );
   scanf( "%d", &num2 );
   
   resultado = compara(num1,num2);
   printf("\n %d",resultado);

}

int compara(int numero, int otronumero)
{
	int resultado = 0;
	
	if(numero < otronumero)
	{
		resultado = -1;
	}
	if (numero > otronumero)
	{
		resultado = 1;
	}
	
	return resultado;
}