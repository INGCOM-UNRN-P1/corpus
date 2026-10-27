
#include <stdio.h>

int compara();


int main()
{
    int numero1;
    int numero2;
    int resultado;
    
    printf("ingrese el primer numero: ");
    scanf("%d",&numero1);
    
    printf("ingrese el segundo numero: ");
    scanf("%d",&numero2);
    
    resultado = compara(numero1, numero2);
    printf("%d",resultado);
  
}

int compara(int numero1, int numero2)
{
    int valor;
    
    valor = numero1 - numero2;
    
    if (valor < 0)
    {
        return -1;
    }
    else if (valor > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
        
}