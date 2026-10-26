

#include <stdio.h>



int cantidad_digitos(int numero)
{
    int i;
    int digitos;

    while(numero > 0)
    {
        numero = numero / 10;
        digitos++;
    }

    return digitos;
}

int main()
{
    int numero;
    int resultado;
    
    printf("Ingrese un numero entero positivo para saber su cantidad de digitos:\n");
    scanf("%d", &numero);

    resultado = cantidad_digitos(numero);

    printf("El numero ingresado tiene %d digitos", resultado);
    
    return 0;
}
