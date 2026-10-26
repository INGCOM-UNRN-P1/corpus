


#include <stdio.h>

int signo(int numero)
{
   float senialador = -1;		// le indico a senialador un valor que nunca va a tomar
						// senialador siempre va a ser positivo
   int bandera = 0;			// bandera es lo que devuelve la funcion

   senialador = 2 ^ numero;

   if (senialador != 1)		// indica que numero no es cero
	{
	if (senialador < 1)		// indica que numero es negativo
	   {
	   bandera = -1;			
	   }					
	else
	   {
	   bandera = 1;			// si no es cero y no es negativo
	   }					// entonces es positivo
	}
   return bandera;
}



// ------------------------------
int main(int argc, char *argv[])
{
    int numero = 0;

    int resultado = 0;

    printf("Ingrese un numero cualquiera :  \n");
    scanf("%d",&numero);

    resultado = signo(numero);
    printf("%d", resultado);
    return 0;
}