

#include <stdio.h>

int main(int argc, char *argv[])
{



    float flotante = 21.2;
    int entero = 23;
    char cadena = 'c';

    float *flotante_p = &flotante;
    int *entero_p = &entero;
    char *cadena_p = &cadena;

    int tamanio;



    printf("el valor del float \t\t es: %f \n", flotante);
    printf("el valor del int \t\t es: %i \n", entero);
    printf("el valor del char \t\t es: %c \n", cadena);
    printf("\n\n");


    printf("el valor del *float \t\t es: 0x% x \n", flotante_p);
    printf("el valor del *int \t\t es: 0x% x \n", entero_p);
    printf("el valor del *char \t\t es: 0x% x \n", cadena_p);
    printf("\n\n");



    tamanio = sizeof(flotante);
    printf("el tamaño del float \t\t es: %i \n", tamanio);

    tamanio = sizeof(entero);
    printf("el tamaño del int \t\t es: %i \n", tamanio);

    tamanio = sizeof(cadena);
    printf("el tamaño del char \t\t es: %i \n", tamanio);
    printf("\n\n");



    tamanio = sizeof(flotante_p);
    printf("el tamaño del float* \t\t es: %i \n", tamanio);

    tamanio = sizeof(entero_p);
    printf("el tamaño del int* \t\t es: %i \n", tamanio);

    tamanio = sizeof(cadena_p);
    printf("el tamaño del char* \t\t es: %i \n", tamanio);

    printf("\n\n");


    printf("la dirrecion del float  \t es: 0x% x \n", flotante);
    printf("la dirrecion del int    \t es: 0x% x \n", entero);
    printf("la dirrecion del char   \t es: 0x% x \n", cadena);

    printf("\n\n");

    printf("la dirrecion del *float \t es: 0x% x \n", flotante_p);
    printf("la dirrecion del *int   \t es: 0x% x \n", entero_p);
    printf("la dirrecion del *char  \t es: 0x% x \n", cadena_p);

    printf("\n\n");
}