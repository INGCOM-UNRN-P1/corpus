

#include <stdio.h>


int pocos_caballos(int base, int exponente)
{
    int resultado = 1;
    while (base != 0) {
        resultado = resultado * exponente;
        base--;
    }
    return resultado;
}

int main()
{
    int base;
    int exponente;

    printf("Ingrese la base: \n");
    scanf("%d", &base);

    printf("Ingrese el exponente: \n");
    scanf("%d", &exponente);

    printf("El resultado de la potencia entre la base %d y el exponente %d es: %d\n", 
    base, exponente, pocos_caballos(base, exponente));
    return 0;
}
