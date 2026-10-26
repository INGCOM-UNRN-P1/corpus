
#include <stdio.h>
#include <stdlib.h>
int suma_lenta(int numero, int otro_numero)
{
    int contador;
    contador = abs(otro_numero);
    while(contador > 0)
    {
        if(otro_numero < 0)
        {
            numero = numero - 1;  
        }
        else
        {
            numero = numero + 1;
        }
        contador = contador - 1;
    }
    return numero;
}
int main()
{
   int numero, otro_numero, guardar;
   printf("Ingresar un numero entero: \n");
   scanf("%d", &numero);
   printf("Ingresar un numero entero: \n");
   scanf("%d", &otro_numero);
   guardar = suma_lenta(numero, otro_numero);
   printf("El resultado es: %d", guardar);
   return 0;
}

