/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>

int es_primo();



int main()
{
    int numero;
    int retorno;
    
    printf("ingrese un numero para saber si es primo: \n");
    scanf("%d",&numero);
    
    retorno = es_primo(numero);
    if (retorno == 1)
    {
        printf("TRUE");
    }
    else
    {
        printf("FALSE");
    }
    
    
}

int es_primo(int numero)
{
    int auxiliar = 1;
    int contador = 0;
    int true = 0;
    int false = 0;
    
    while (auxiliar <= numero)
    {
       
        if ((numero%auxiliar) == 0)
        {
            contador = contador + 1;
             
        }
        else
        {
         
        }
        auxiliar++;       
    }
    
    if (contador == 2)  
    {
        true = 1;
        return true; 
    }
    else
    {
        false = 0;
        return false;     
    }
    
}