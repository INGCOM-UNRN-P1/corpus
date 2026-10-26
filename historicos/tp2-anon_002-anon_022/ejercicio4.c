



#include <stdio.h>




int mayor_numero (int numero1, int numero2, int numero3) // Esta funcion sirve para comparar los numeros ingresados
{
    int max = numero1;
    if (numero2 > max)
    {
        max = numero2;
    }
    if (numero3 > max)
    {
        max = numero3;
    }
    return max;
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
   evaluar = mayor_numero(numero1, numero2, numero3);
   printf("El mayor numero es: %d",evaluar);
   return 0;
}
