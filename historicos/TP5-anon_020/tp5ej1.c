
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char caracter = 'C';
    int entero = 9;
    double doble = 9.1;
     
    int *p_entero = &entero;
    double *p_doble = &doble;
    char *p_caracter = &caracter;
 
    printf("La direccion del char\t 'caracter' es 0x% x\n", &caracter);
    printf("La direccion del int\t 'entero' es 0x% x\n", &entero);
    printf("La direccion del double\t 'doble' es 0x% x\n", &doble);
    
    printf("La direccion del char*\t 'caracter' es 0x% x\n", &p_caracter);
    printf("La direccion del int*\t 'entero' es 0x% x\n", &p_entero);
    printf("La direccion del double*\t 'doble' es 0x% x\n\n", &p_doble);
    
    printf("El valor del char\t 'caracter' es %c\n", caracter);
    printf("El valor del int\t 'entero' es %d\n", entero);
    printf("El valor del double\t 'doble' es %f\n", doble);
    
    printf("El valor del char*\t 'caracter' es % x\n", p_caracter);
    printf("El valor del int*\t 'entero' es % x\n", p_entero);
    printf("El valor del double*\t 'doble' es* % x\n\n", p_doble); 
    
    
    printf("El tamanio del char\t 'caracter' es % x\n", sizeof(caracter));
    printf("El tamanio del int\t 'entero' es % x\n", sizeof(entero));
    printf("El tamanio del double\t 'doble' es % x\n", sizeof(doble));
    printf("El tamanio del char*\t 'caracter' es % x\n", sizeof(p_caracter));
    printf("El tamanio del int*\t 'entero' es % x\n", sizeof(p_entero));
    printf("El tamanio del double*\t 'doble' es % x\n", sizeof(p_doble));
    
    return 0;
}
    
    