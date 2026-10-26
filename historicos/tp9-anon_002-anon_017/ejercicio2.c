
#include <stdio.h>


long long int fibonacci(long long int actual, long long int anterior, int numero_serie);
long long int factorial(int numero_serie);

int main()
{
    long long int actual = 1;
    long long int anterior = 0;
    int numero_serie = 0;
    
    long long int ret_fibonacci = 0;
    long long int ret_factorial = 0;
    
    printf("Ingrese el numero a calcular: ");
    scanf("%d",&numero_serie);
    
    
    ret_fibonacci = fibonacci(actual, anterior, numero_serie);
    ret_factorial = factorial(numero_serie);
    
    printf("Fibonacci: fib(%d) = %lld\n",numero_serie, ret_fibonacci);
    printf("Factorial: %d! = %lld\n",numero_serie, ret_factorial);
    
    
    
    
    
}


/**
 * La funcion calcula la serie de fibonacci y devuelve el termino pedido
 *  @param numero_serie es termino que se busca
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @returns retorna el valor del termino de la serie.
 *  @post se espera que se encuentre el numero en la posicion pedida.
 */


long long int fibonacci(long long int actual, long long int anterior, int numero_serie)
{
    long long int retorno = 0;
    long long int aux = 0;
    
    if(numero_serie <= 2)//Esto es por que calcula la cantidad de sumas, no la posicion, entonces sin esto haria 2 sumas de mas.
    {
        retorno = actual;
    }
    else
    {
        
        //Hace la cantidad de sumas de: numero_serie, no da el termino de numero_serie
        aux = actual;//Esto es para que se guarde sin que se mofique al hacer la primera suma.
        retorno = fibonacci(actual + anterior, aux, numero_serie - 1);
    }
    
       
    return retorno;
}



/**
 * La funcion calcula el factorial de un numero de forma recursiva.
 *  @param numero_serie es numero al que se la va a hacer el factorial.
 *  @pre tiene que ser un numero entero mayor a 1.
 *  @returns retorna el factorial de un numero
 *  @post se espera que se calcule el factorial de un numer0
 */


long long int factorial(int numero_serie)
{
    
    if(numero_serie > 1 )//Si el numero del factorial es mayor a 1, opera, si no multiplicaria por 0.
    {
        
        numero_serie = numero_serie * factorial(numero_serie - 1);//Es como si se acumularan los retornos y despues se resuelven.
    }
    
    return numero_serie;

}