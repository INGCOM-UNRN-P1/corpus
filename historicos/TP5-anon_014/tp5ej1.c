
#include <stdio.h>
int main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    double valor_double = 100;
    int valor_int = 10;
    char valor_char = 'A';
    double* puntero_double = &valor_double;
    int* puntero_int = &valor_int;
    char* puntero_char = &valor_char;
    printf("La direccion del char \t\t'valor_char' \t\tes\t 0x%p\n"
       "La direccion del int \t\t'valor_int' \t\tes\t 0x%p \n"
       "La direccion del double \t'valor_double' \t\tes\t 0x%p \n"
       "La direccion del char* \t\t'puntero_char' \t\tes\t 0x%p \n"
       "La direccion del int* \t\t'puntero_int' \t\tes\t 0x%p \n"
       "La direccion del double* \t'puntero_double' \tes\t 0x%p \n\n",
       &valor_char,&valor_int,&valor_double,&puntero_char,&puntero_int,&puntero_double);
    printf("La valor del char \t\t'valor_char' \t\tes \t %c \n"
       "La valor del int \t\t'valor_int' \t\tes \t %d \n"
       "La valor del double \t\t'valor_double' \t\tes \t %.0f \n"
       "La valor del char* \t\t'puntero_char' \t\tes \t 0x%p \n"
       "La valor del int* \t\t'puntero_int' \t\tes \t 0x%p \n"
       "La valor del double*\t\t'puntero_double' \tes \t 0x%p \n\n",
       valor_char, valor_int, valor_double, puntero_char, puntero_int, puntero_double);
    printf("El tamaño del char \t\t es \t %lld bytes \n"
       "El tamaño del int \t\t es \t %lld bytes\n"
       "El tamaño del double \t\t es \t %lld bytes\n"
       "El tamaño del char* \t\t es \t %lld bytes\n"
       "El tamaño del int* \t\t es \t %lld bytes\n"
       "El tamaño del double* \t\t es \t %lld bytes\n",
       sizeof(valor_char), sizeof(valor_int), sizeof(valor_double), sizeof(puntero_char), sizeof(puntero_int), sizeof(puntero_double));
    return 0;
}
