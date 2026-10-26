/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>
 
int raiz(int radicando);

int main(int argc, char *argv[])
{
    int radicando;
    int resultadoA;
    int resultadoB;

    printf("Ingrese el radicando de la raiz:\n\t");
    scanf("%d", &radicando);

    resultadoA = raiz(radicando);
    printf("El resultado es: %d\n\n", resultadoA);

    printf("Ingrese el radicando A: \n\t");
    scanf("%d", &radicando);
    resultadoA = raiz(radicando);

    printf("Ingrese el radicando B: \n\t");
    scanf("%d", &radicando);
    resultadoB = raiz(radicando);

    printf("El resultado de A es (%d) y el de B es (%d)", resultadoA, resultadoB);

}

int raiz(int radicando)
{
    if(radicando < 1)
    {
        return 0;
    }

    int temporal;
    int i;

    for(i = 1; i<=radicando; i++)
    {
        temporal = i*i;
        if(radicando == temporal)
        {
            return i;
        }
        if(temporal>radicando)
        {
            return i-1;
        }
    }
    return 0;
}