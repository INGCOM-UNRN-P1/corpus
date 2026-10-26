



#include <stdio.h>




int fibonacci (int posicion) //Retorna el termino en el N-enesima posicion utilizando el metodo recursivo
{
    if (posicion>2) 
    {
        return (fibonacci(posicion-1) + fibonacci(posicion-2));
    }
    if (posicion == 0)
    {
        return 0;
    }
    if (posicion == 1)
    {
        return 0;
    }
    if (posicion == 2)
    {
        return 1;
    }
}



int suma_digitos(int numero) //realiza la suma de los digitos del numero
{
    int suma = 0;
    if (numero == 0) 
    {
        return -1;
    }
    while ( numero > 0)
    {
        suma = suma + numero % 10;
        numero = numero / 10;
    }
    return suma;
}






int suma_digitos_fibonacci(int numero) //realiza la suma de los digitos de fibonacci hasta el N-enesimo termino dado
{
    int sumaTotal = 0;
    int termino;
    int i =1;
    for (i; i <= numero; i++)
    {
        termino = fibonacci(i);
        sumaTotal = sumaTotal + suma_digitos(termino);
    }
    return sumaTotal;
}



int main()
{
   int posicion;
   int suma_digitos_fibo;
   int fibo;
   printf("Ingrese la posicion N-esima de fibonacci: \n");
   scanf("%d", &posicion);
   fibo = fibonacci(posicion);
   printf("Fibonacci es %d\n",fibo);
   suma_digitos_fibo = suma_digitos_fibonacci(posicion);
   printf("Suma digitos de los digitos hasta %d posicion:  %d",posicion,suma_digitos_fibo);
   return 0;
}