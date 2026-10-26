/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * Hanchut -- anon_034
 *************************/

#include <stdio.h>

int main()
{
    int entero = 12;
    char letra = 'a';
    double doble = 1.2;

    int *puntero_entero = &entero;
    char *puntero_letra = &letra;
    double *puntero_doble = &doble;

    printf("La direccion del char \t'letra' es 0x% x\n", &letra);
    printf("La direccion del int \t'entero' es 0x% x\n", &entero);
    printf("La direccion del double \t'doble' es 0x% x\n", &doble);

    printf("\n");

    printf("La direccion del puntero al char \t'letra' es 0x% x\n", &puntero_letra);
    printf("La direccion del puntero al int \t'entero' es 0x% x\n", &puntero_entero);
    printf("La direccion del puntero al double \t'doble' es 0x% x\n", &puntero_doble);

    printf("\n");

    printf("El valor del char \t 'letra' es %c\n", letra);
    printf("El valor del int \t 'entero' es %d\n", entero);
    printf("El valor del double \t 'doble' es %f\n", doble);

    printf("\n");

    printf("El valor del puntero al char \t 'letra' es %c\n", &puntero_letra);
    printf("El valor del puntero al int \t 'entero' es %d\n", &puntero_entero);
    printf("El valor del puntero al double \t 'doble' es %f\n", &puntero_doble);

    printf("\n");

    printf("El tamanio del char\t 'letra' es %llx\n", sizeof(letra));
    printf("El tamanio del int\t 'entero' es %llx\n", sizeof(entero));
    printf("El tamanio del double\t 'doble' es %llx\n", sizeof(doble));
    printf("El tamanio del puntero a char\t 'letra' es %llx\n", sizeof(*puntero_letra));
    printf("El tamanio del puntero a int\t 'entero' es %llx\n", sizeof(*puntero_entero));
    printf("El tamanio del puntero a double\t 'doble' es %llx\n", sizeof(*puntero_doble));

    return 0;
}