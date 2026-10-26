
#include <stdio.h>

void division_lenta(int *dividendo, int *divisor, int *cociente, int *resto);

//pre: Se necesita un numero entero para dividendo y un numero entero mayor a 1 para divisor
//post: Se imprime el resto y el cociente de la division entre dividendo y divisor.

int main()
{
    int dividendo = 0;
    int divisor = 0;
    int cociente = 0;
    int resto = 0;
    
    
    printf("Ingrese el dividendo: ");
    scanf("%d",&dividendo);
    
    printf("Ingrese el divisor: ");
    scanf("%d",&divisor);
    
    if(divisor != 0)
    {
        division_lenta( &dividendo,  &divisor,  &cociente,  &resto);
        printf("Cociente: %d\n",cociente);
        printf("Resto: %d\n",resto);
    }
    else
    {
        printf("No se puede dividir por 0!");
    }
    
    
    
}



void division_lenta(int *dividendo, int *divisor, int *cociente, int *resto)
{
    int contador = 0;
    
    
    while(*dividendo >= *divisor)
    {
        
        *cociente = *cociente + 1;
        *dividendo = *dividendo - *divisor;
        
    }
    
    *resto = *dividendo;
    
}