

#include <stdio.h>




int menor_numero (int numero1, int numero2, int numero3) //esta funcion compara los 3 numeros ingresados y devuelve el menor
{
    int min = numero1;
    if (numero2 < min)
    {
        min = numero2;
    }
    if (numero3 < min)
    {
        min = numero3;
    }
    return min;
}


int main()
{
   int numero1;
   int numero2;
   int numero3;
   int evaluar;
   printf("Ingrese el primer numero: \n");
   scanf("%d", &numero1);
   printf("Ingrese el segundo numero: \n");
   scanf("%d", &numero2);
   printf("Ingrese el tercer numero: \n");
   scanf("%d", &numero3);   
   evaluar = menor_numero(numero1, numero2, numero3);
   printf("El menor numero es: %d",evaluar);
   return 0;
}