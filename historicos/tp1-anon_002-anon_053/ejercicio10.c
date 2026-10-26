
//Funcion declarada
long factorial(int numero);

#include <stdio.h>

int main()
{
    int numero = 5;
    
//funcion asignada a una variable
    long facto_rial = factorial(numero);

    printf("El factorial de %d es : %ld", numero, facto_rial);
    return 0;
        
}

long factorial(int numero)
{
    int i;
    long factor = 1;// factor en cada iteracion realizara la multiplicacion hasta cumplir con el valor de "numero"
    for(i = 1; i <= numero; i++)//numero es la condicion de las veces que se realiza la multiplicacion
    {
        factor = factor * i;//se actualiza en cada iteracion el valor de factor 
    }
    return factor;
}   
//pre: recibe un numero entero no negativo
//pos: retorna el producto de todos los numeros hasta el numero entero


