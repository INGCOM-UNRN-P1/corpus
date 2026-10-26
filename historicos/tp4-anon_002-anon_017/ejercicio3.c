
#include <stdio.h>

void duplica(int *numero);

//pre: Se necesita un numero entero
//Post: Se imprime el doble del numero entero ingresado.

int main()
{
    int numero = 0;
    
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    
    duplica(&numero);
    
    printf("El numero queda : %d",numero);
    
}




void duplica(int *numero)
{
    *numero = *numero * 2;
}