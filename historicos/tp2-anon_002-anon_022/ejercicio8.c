

#include <stdio.h>
#define TRUE 1
#define FALSE 0






int numero_defectivo (int numero) 
{
    int suma_divisores = 0;
    int i = 1;
    if (numero <= 0)
    {
        return 0;
    }
    for (i; i < numero; i++)
    {
        if (numero % i ==0)
        {
            suma_divisores = suma_divisores+i;
        }
    }
    if (suma_divisores<numero )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
   int numero;
   int evaluar;
   printf("Ingrese un numero para evaluar: \n");
   scanf("%d", &numero);
   evaluar = numero_defectivo(numero);
   if (evaluar==1)
   {
    printf("Es defectivo");
   }
   else
   {
    printf("No es defectivo");
   }
   return 0;
}