




#include <stdio.h>





int es_primo(int numero) //verifica que el numero ingresado es primo
{
    int i;
    for (int i = 2; i * i <= numero; i++) 
    {
        if (numero % i == 0) 
        {
            return 0;
        }
    }
    return 1;
}




int suma_primos(int n) //realiza la suma de los primos verificando con la funcion anterior si el numero es primo y los suma
{
    int suma = 0;
    int contador = 0;
    int numero = 2;
    while (contador < n)
    {
        if (es_primo(numero))
        {
            suma = suma +numero;
            contador++;
        }
        numero++;
    }
    return suma;
}



int main()
{
   int n;
   int resultado;
   printf("Ingrese un valor N para la suma de numeros primos: ");
   scanf("%d",&n);
   resultado = suma_primos(n);
   printf("La suma de los primeros %d numeros es %d\n",n,resultado);
   return 0;
}