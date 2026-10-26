

#include <stdio.h>

int es_factorial(int numero){
    int aux;
    int resultado=1;
    for (aux= 1; aux<=numero; aux++){
        resultado = resultado * aux;
    }
    return resultado;
}

int main()
{
   int numero;
   int evaluar;
   printf("Ingrese el numero para calcular su factorial: \n");
   scanf("%d", &numero);
   evaluar = es_factorial(numero);
   printf("Factorial de %d es: %d \n",numero,evaluar);
   return 0;
}