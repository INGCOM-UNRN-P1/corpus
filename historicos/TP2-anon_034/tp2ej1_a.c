

#include <stdio.h>

int raiz(int entero)
{
    float i = 0;
    int resto;

    if(entero >= 0)
    {
        do
        {
            i = i + 0.1;
            resto = i * i;
        }
        while(entero >= resto);
    }
    else
    {
        return -1;
    }

    return i;
}

int main()
{
    int entero, resultado;

    printf("Ingrese un numero entero para calcular su raiz cuadrada: ");
    scanf("%d", &entero);

    resultado = raiz(entero);
    printf("El resultado de la operacion fue: %d", resultado);

    return 0;
}