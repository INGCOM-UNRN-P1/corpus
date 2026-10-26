


#include <stdio.h>

int es_multiplo(int numero, int multiplo)
{
    while (numero>=multiplo)
    {
        numero = numero - multiplo;
    }
    return numero;
}


int main()
{
   int numero;
   int multiplo;
   int evaluar;
   printf("Ingrese el numero: \n");
   scanf("%d", &numero);
   printf("Ingrese el posible multiplo: \n");
   scanf("%d", &multiplo);
   evaluar = es_multiplo(numero,multiplo);
   if (evaluar==0)
   {
    printf("Es multiplo");
   } 
   else
   {
    printf("No es multiplo");
   }
   return 0;
}
