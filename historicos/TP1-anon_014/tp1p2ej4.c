/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_014 de GitHub
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    int numero, resultado;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    
    resultado = es_primo(numero);
    
    printf("El resultado es: %d", resultado);
}
int es_primo(numero)
{ 
    int resultado,i, mod;
    if (numero < 1)
    {        
        resultado = 0;
    }
    else if (numero == 2)
    {
        resultado = 1;
    }
        
    else
    {
      for (i=2; i<=numero;i++)
      {
          if (numero%i == 0)
          {
              resultado = 0;
              break;
          }
          else
          {
              resultado = 1;
              break;
          }
      }
      
      return resultado;
    }
        
}