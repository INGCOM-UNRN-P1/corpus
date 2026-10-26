




#include <stdio.h>
#define SIZE 50



int contar_digitos (int numero)   
{
    int contador = 0;
    if (numero == 0)
    {
        return 1;
    }
    while (numero > 0)
    {
        numero = numero / 10;
        contador = contador +1;
    }
    return contador;
}
int main()
{
    int numero;
    int evaluar;
    printf("Ingrese un numero: \n");
    scanf("%d", &numero);
    evaluar = contar_digitos(numero);
    printf("Cantidad de digitos de %d es: %d", numero,evaluar);
    return 0;
}