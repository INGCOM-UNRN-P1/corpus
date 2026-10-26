/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_017
*************************/
#include <stdio.h>
#define POSITIVO 1
#define NEGATIVO 0

int signo();


int main()
{
    int numero;
    int resultado;
    
    printf("Ingrese un numero: \n");
    scanf("%d",&numero);
    
    resultado = signo(numero);
    printf("%d",resultado);
   
}


int signo(int numero)
{
    int resultado = numero;

    
    resultado = numero -(-resultado);
    if (resultado < numero)
    {
        
        return NEGATIVO; 
    }
    else
    {

        return POSITIVO; 
    }   
}
