
#include <stdio.h>

int potencia(int base, int exponente);
int producto(int numeroA, int numeroB);

int main(int argc, char *argv[])
{
    int numeroA;
    int numeroB;
    int resultado;

    printf("Ingrese la base de su potencia: \n\t");
    scanf("%d", &numeroA);
    printf("Ingrese el exponente de su potencia: \n\t");
    scanf("%d", &numeroB);

    resultado = potencia(numeroA, numeroB);

    printf("El resultado de la operación es: (%d)\n\n", resultado);

    printf("Ingrese el primer número de la multiplicación: \n\t");
    scanf("%d", &numeroA);
    printf("Ingrese el segundo número de la multiplicación: \n\t");
    scanf("%d", &numeroB);

    resultado = producto(numeroA, numeroB);

    printf("El resultado de la operación es: (%d)\n\n", resultado);

}

int potencia(int base, int exponente)
{
    if(base == 0 || exponente == 0)
    {
        return 0;
    }
    int i;
    int temporal = base;
    for(i = 1; i < exponente; i++)
    {
        temporal = temporal * base;
    }
    return temporal;
}
int producto(int numeroA, int numeroB)
{
    if(numeroA == 0 || numeroB == 0)
    {
        return 0;
    }
    return numeroA * numeroB;
}