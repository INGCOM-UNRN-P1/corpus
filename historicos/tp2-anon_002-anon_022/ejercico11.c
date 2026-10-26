


#include <stdio.h>
#define TRUE 1
#define FALSE 0




int numero_perfecto (int numero) //la funcion realiza la suma de sus divisores propios y devuelve si es perfecto o no 
{
    int suma_divisores = 0;
    int i;
    for (i = 1; i< numero; i++)
    {
        if (numero % i == 0)
        {
            suma_divisores = suma_divisores + i;
        }
    }
    if (suma_divisores != numero)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
   int numero; 
   int evaluar;
   printf("Ingrese el numero a evaluar: \n");
   scanf("%d", &numero);
   evaluar = numero_perfecto(numero);
   if (evaluar == 1)
   {
    printf("Es perfecto\n");
   }
   else
   {
    printf("No es perfecto");
   }
   return 0;
}