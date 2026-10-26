

#include <stdio.h>


int main() 
{
    double numero_double = 3.14159;
    int numero_int = 42;
    char caracter = 'A';

    // Declaro punteros e inicializo con las direcciones de las variables correspondientes
    double *puntero_double = &numero_double;
    int *puntero_int = &numero_int;
    char *puntero_char = &caracter;

    // Imprimo la dirección, valor almacenado y tamaño en bytes de cada variable y puntero    
    printf("Dirección del char:\t%p\n", puntero_char);
    printf("Dirección del int:\t%p\n", puntero_int);
    printf("Dirección del double:\t%p\n", puntero_double);
    printf("Dirección del *char:\t%p\n", &caracter);
    printf("Dirección del *int:\t%p\n", &numero_int);
    printf("Dirección del *double:\t%p\n\n", &numero_double);    

    printf("Valor del char: \t%c\n", caracter);
    printf("Valor del int:  \t%d\n", numero_int);
    printf("Valor del double:\t%lf\n", numero_double);
    printf("Valor del *char:\t%c\n", *puntero_char);
    printf("Valor del *into:\t%d\n", *puntero_int);
    printf("Valor del *double:\t%lf\n\n", *puntero_double);    

    printf("Tamaño del char \t%zu bytes.\n", sizeof(caracter));
    printf("Tamaño del int  \t%zu bytes.\n", sizeof(numero_int));
    printf("Tamaño del double\t%zu bytes.\n", sizeof(numero_double));
    printf("Tamaño del *char\t%zu bytes.\n", sizeof(puntero_char));
    printf("Tamaño del *int \t%zu bytes.\n", sizeof(puntero_int));
    printf("Tamaño del *double\t%zu bytes.\n", sizeof(puntero_double));

    return 0;
}
