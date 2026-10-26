
#include <stdio.h>

int es_primo(int num1);

int main(int argc, char *argv[])
{
   int num1;
   int resultado;

   printf( "\n Ingrese un numero: " );
   scanf( "%d", &num1 );
   
  
   resultado = es_primo(num1);
   
   if (resultado == 1)
   {
	   printf("\n El numero %d es primo.",num1);
   }
   else
   {
	   printf("\n El numero %d no es primo.",num1);
   }

}

int es_primo(int numero)
{
    int divisor = numero;
    int resto = 0;
    int contador = 0;
	
    while (divisor >= 1 && contador < 3)
	{
        resto = numero % divisor;
        if (resto == 0)
		{
            contador = contador + 1;
		}
        divisor = divisor -1 ;
	}
    if (contador > 2)
	{
        return 0;
	}
    else
	{
		return 1;
	}
}