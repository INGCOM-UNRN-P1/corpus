/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_039 de GitHub
 *************************/
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Declaracion de las variables
    int entero = 5;
    double doble = 10;
    char caracter = 25;
    
    //Declaracion de los punteros
    int *p_entero = &entero;
    double *p_doble = &doble;
    char *p_caracter = &caracter;
    
    //Direcciones
    
    printf("La direccion del char \t 'caracter' es: 0x%p\n", &caracter);
    printf("La direccion del int \t 'entero' es: 0x%p\n", &entero);
    printf("La direccion del double \t'doble' es: 0x%p\n", &doble);
    printf("La direccion del char* \t 'caracter' es: 0x%p\n", &p_caracter);
    printf("La direccion del int* \t 'entero' es: 0x%p\n", &p_entero);
    printf("La direccion del double* \t'doble' es: 0x%p\n", &p_doble);
    
    //Valores
    
    printf("\nEl valor del char \t 'caracter' es: %c\n", caracter);
    printf("El valor del int \t 'entero' es: %d\n", entero);
    printf("El valor del double \t'doble' es: %f\n", doble);
    printf("El valor del char* \t 'caracter' es: 0x%p\n", p_caracter);
    printf("El valor del int* \t 'entero' es: 0x%p\n", p_entero);
    printf("El valor del double* \t'doble' es: 0x%p\n", p_doble);
    
    //Tamaños
    
    printf("\nEl tamano del char \t 'caracter' es: %lld bytes\n", sizeof(caracter));
    printf("El tamano del int \t 'entero' es: %lld bytes\n", sizeof(entero));
    printf("El tamano del double \t'doble' es: %lld bytes\n", sizeof(doble));
    printf("El tamano del char* \t 'caracter' es: %lld bytes\n", sizeof(p_caracter));
    printf("El tamano del int* \t 'entero' es: %lld bytes\n", sizeof(p_entero));
    printf("El tamano del double* \t'doble' es: %lld bytes\n", sizeof(p_doble));
    
    return 0;
}