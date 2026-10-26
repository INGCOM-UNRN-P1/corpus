#include <stdio.h>



int main ()
{
    int entero = 14;
    double decimal = 3.124;
    char caracter = 'a';
    int *entero_ptr = &entero;
    double *decimal_ptr = &decimal;
    char * caracter_ptr = &caracter;
    printf("La direccion del int \t\t Entero es 0x%p \n",&entero);
    printf("La direccion del double\t\t Decimal es 0x%p \n",&decimal);
    printf("La direccion del char \t\t Caracter es 0x%p \n",&caracter);
    printf("La direccion del int* \t\t Entero_ptr es 0x%p\n",entero_ptr);
    printf("La direccion del double*\t Decimal_ptr es 0x%p\n",decimal_ptr);
    printf("La direccion del char* \t\t Caracter_ptr es 0x%p\n", caracter_ptr);
    printf("El valor del char\t\t Caracter es %c\n",caracter);
    printf("El valor del int\t\t Entero es %i\n",entero);
    printf("El valor del double\t\t Decimal es %lf\n", decimal);
    printf("El valor del char*\t\t Caracter_ptr es 0x%p\n",caracter_ptr);
    printf("El valor del int*\t\t Entero_ptr es 0x%p\n",entero_ptr);
    printf("El valor del double*\t\t Decimal_ptr es 0x%p\n", decimal_ptr);
    printf("El tamanio del char\t\t es %lu bytes\n", sizeof(caracter));
    printf("El tamanio del int\t\t es %lu bytes\n", sizeof(entero));
    printf("El tamanio del double\t\t es %lu bytes\n", sizeof(decimal));
    printf("El tamanio del char*\t\t es %lu bytes\n", sizeof(caracter_ptr));
    printf("El tamanio del int*\t\t es %lu bytes\n", sizeof(entero_ptr));
    printf("El tamanio del double*\t\t es %lu bytes\n", sizeof(decimal_ptr));
    return 0;

}