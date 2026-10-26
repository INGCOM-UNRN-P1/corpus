
//Funcion declarada
int es_primo(int numero);

#include <stdio.h>

int main()
{
    int numero = 7;
    int primo; 
// funcion asignada a variable
    primo = es_primo(numero);
    if (primo)
    {
        printf("\nEl numero %d es primo", numero);
    }
    else
    {
        printf("El numero %d no es primo", numero);
    }  
    return 0;
}
//funcion
int es_primo(int numero)
{
    int resolucion = 0;
    if (numero / 1 == numero && numero % 2 != 0)//condicion que cumple un numero primo
    {        
        resolucion = 1;
    }
    else;
    {
        resolucion;      
    }
    return resolucion;
}

//pre: recibe un numero entero
//pos: compara y retorna 1 si es primo

