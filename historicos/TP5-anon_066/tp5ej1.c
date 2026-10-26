/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
int main(int argc, char *argv[])
{
    char variable_caracter='a';
    int variable_entera=15000;
    double variable_double=12.55; 
    char *puntero_variable_caracter= &variable_caracter;
    int *puntero_variable_entera = &variable_entera;  
    double *puntero_variable_double = &variable_double;  
    printf("La direccion del char\t\tvariable_caracter\t\t es 0x%x\n",&variable_caracter);
    printf("La direccion del int\t\tvariable_entera\t\t\t es 0x%x\n",&variable_entera);
    printf("La direccion del double\t\tvariable_double\t\t\t es 0x%x\n",&variable_double);
    printf("La direccion del char*\t\tpuntero_variable_caracter\t es 0x%x\n",&puntero_variable_caracter);
    printf("La direccion del int*\t\tpuntero_variable_entera\t\t es 0x%x\n",&puntero_variable_entera);
    printf("La direccion del double*\tpuntero_variable_double\t\t es 0x%x\n\n",&puntero_variable_double);
    printf("La valor del char\t\tvariable_caracter\t\t es %c\n",variable_caracter);
    printf("La valor del int\t\tvariable_entera\t\t\t es %d\n",variable_entera);
    printf("La valor del double\t\tvariable_double\t\t\t es %.2lf\n",variable_double);
    printf("La valor del char*\t\tpuntero_variable_caracter\t es 0x%x\n",puntero_variable_caracter);
    printf("La valor del int*\t\tpuntero_variable_entera\t\t es 0x%x\n",puntero_variable_entera);
    printf("La valor del double*\t\tpuntero_variable_double\t\t es 0x%x\n\n",puntero_variable_double);
    printf("El tamano del char\t\tvariable_caracter\t\t es %d bytes\n",sizeof(variable_caracter));
    printf("El tamano del int\t\tvariable_entera\t\t\t es %d bytes\n",sizeof(variable_entera));
    printf("El tamano del double\t\tvariable_double\t\t\t es %d bytes\n",sizeof(variable_double));
    printf("El tamano del char*\t\tpuntero_variable_caracter\t es %d bytes\n",sizeof(puntero_variable_caracter));
    printf("El tamano del int*\t\tpuntero_variable_entera\t\t es %d bytes\n",sizeof(puntero_variable_entera));
    printf("El tamano del double*\t\tpuntero_variable_double\t\t es %d bytes\n",sizeof(puntero_variable_double));
	return 0;
}
