/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    int numeroA, numeroB, producto, cociente, resto;
    //Ingreso de datos del usuario
    printf("Ingrese el primer numero:\t");
    scanf("%d", &numeroA);
    printf("Ingrese el segundo numero:\t");
    scanf("%d", &numeroB);

    //Realizo las operaciones requeridas
    producto = numeroA * numeroB;
    cociente = numeroA / numeroB;
    resto = numeroA % numeroB;

    //Imprimo los resultados
    printf("Numero A = %d\tNumero B = %d\n", numeroA, numeroB);
    printf("operacion multiplicacion: A*B = %d\n", producto);
    printf("operacion division: A/B = %d\n", cociente);
    printf("operacion resto: A%%B = %d\n", resto);

    return 1;
}
