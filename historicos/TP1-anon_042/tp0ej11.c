
#include <stdio.h>

int suma_lenta(int numero, int numero_dos, int resultado);
int main(int argc, char *argv[])
{
    int numero = 0;
    int numero_dos = 0;
    int resultado;
    int total;
    printf("Ingrese un numero entero:");
    scanf("%d", &numero);
    printf("Ingrese otro numero entero:");
    scanf("%d", &numero_dos);
    total = suma_lenta(numero, numero_dos, resultado);
    return total;		
}

int suma_lenta(int numero, int numero_dos, int resultado)
{
    resultado = numero + numero_dos;
    int resultado_total;
    while (numero < resultado)
    {
        numero = numero + 1;
        resultado_total = printf("%d \n", numero);
    }
    return resultado_total;
}