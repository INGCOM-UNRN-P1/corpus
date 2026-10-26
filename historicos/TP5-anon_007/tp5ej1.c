/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_007
 *************************/
# include <stdio.h>
int main(int argc, char *argv[])
{
    double primera_variable = 2981998;
    int segunda_variable = 298;
    char tercera_variable = 'a';
    double * p_primera_variable = &primera_variable;
    int * p_segunda_variable = &segunda_variable;
    char * p_tercera_variable = &tercera_variable;
    printf("La direccion del double es: 0x%x \n", &primera_variable);
    printf("La direccion del int es: 0x%x \n", &segunda_variable);
    printf("La direccion del char es: 0x%x \n", &tercera_variable);
    printf("La direccion del dobule * es: 0x%x \n", &p_primera_variable);
    printf("La direccion del int * es: 0x%x \n", &p_segunda_variable);
    printf("La direccion del char * es: 0x%x \n\n", &p_tercera_variable);
    printf("El valor del double es: %0.f \n", primera_variable);
    printf("El valor del int es: %d \n", segunda_variable);
    printf("El valor del char es: %c \n", tercera_variable);
    printf("El valor del dobule * es: %0.f\n", *p_primera_variable);
    printf("El valor del int * es: %d \n", *p_segunda_variable);
    printf("El valor del char * es: %c \n\n", *p_tercera_variable);
    printf("El tamaño en bytes del double es: %lu \n", sizeof(primera_variable));
    printf("El tamaño en bytes del int es: %lu \n", sizeof(segunda_variable));
    printf("El tamaño en bytes del char es: %lu \n", sizeof(tercera_variable));
    printf("El tamaño en bytes del double * es: %lu \n", sizeof(p_primera_variable));
    printf("El tamaño en bytes del int * es: %lu \n", sizeof(p_segunda_variable));
    printf("El tamaño en bytes del char * es: %lu \n", sizeof(p_tercera_variable));
    return 0;
}

