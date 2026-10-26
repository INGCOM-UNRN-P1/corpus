

#include <stdio.h>



int tabla_multiplicar(int numero, int tabla)
{
    int multiplicacion;
    
    multiplicacion = numero * tabla;

    return multiplicacion;
}

int main()
{
    int numero;
    int resultado;
    int i;

    printf("Ingrese un numero entero para saber su tabla de multiplicar del 1 al 10:\n");
    scanf("%d", &numero);

    for(i = 1;i < 11;i++)
    {
        resultado = tabla_multiplicar(numero, i);
        printf("%d * %d = %d\n", numero, i, resultado);
    }
}