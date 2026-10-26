
#include <stdio.h>
//Funcion declarada
int compara(int numero, int otro_numero);

int main()
{
    int numero = 100;
    int otro_numero = 1000;
    
    //variable que se le asigno la funcion
    int compara_numeros = compara(numero, otro_numero);
    
    if (compara_numeros == 1) 
    {
        printf("Primer numero (%d) mayor que el segundo (%d).", numero, otro_numero);
    } 
    else if (compara_numeros == -1) 
    {
        printf("Primer numero (%d) menor que el segundo (%d).", numero, otro_numero);
    } 
    else 
    {
        printf("Los numeros son iguales (%d) (%d).", numero, otro_numero);
    }
    
    return 0;
}

int compara(int numero, int otro_numero)
{
    int comparador = 1;
    if(numero < otro_numero)//Condicion que compara si el primero es menor que el segundo
    {
        comparador = -1;
    }
    if(numero == otro_numero)//Condicion compara si son iguales
    {
        comparador = 0;
    }
    else//Condicion que se ejecuta si ninguno de las condiciones anteriores se cumplen
    {
        comparador;
    }
    
    return comparador;
}

// pre: recibe 2 numeros entero
// pos: retorna entre ellos -1 menor, 0 si son iguales y 1 el mayor

