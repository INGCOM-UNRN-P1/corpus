
#include <stdio.h>

//Funcion declarada
int signo(int numero);

int main()
{
    int numero = 100;
    //Asignacion de funcion a variable
    int num_positivo_negativo = signo(numero);
    
    if (num_positivo_negativo == 1) 
    {
        printf("%d es positivo\n", numero);
    } 
    else if (num_positivo_negativo == -1) 
    {
        printf("%d es negativo\n", numero);
    } 
    else 
    {
        printf("%d es cero\n", numero);
    }
    
    return 0;
}

//Funcion indica si un numero es negativo, positivo o cero
int signo(int numero)
{
    int decision = 0;
    if(numero > 0)//Si numero es mayor a cero retorna 1 que indica positivo
    {        
        decision = 1;
    }
    if (numero < 0)//Si numero es menor a cero retorna -1 indicando que es negativo
    {        
        decision = -1;
    }
    else//Retornara cero si es igual a 0
    {        
        decision;
    }

    return decision;
}
// pre: recibe un numero entero
// pos:compara si es positivo negativo o 0