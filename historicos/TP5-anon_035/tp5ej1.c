
 
#include <stdio.h>




int main(int argc, char *argv[])
{
    int entero = 24;
    char caracter = 'x';
    double doble = 32.32443;
    
    int *p_entero = &entero;
    char *p_caracter = &caracter;
    double *p_doble = &doble;
    
    

    printf("La direccion del char es              0x%x\n", &caracter);
    printf("La direccion del int es               0x%x\n", &entero);
    printf("La direccion del double es            0x%x\n", &doble);
    printf("La direccion del puntero char es      0x%x\n", *p_caracter);
    printf("La direccion del puntero int* es      0x%x\n", *p_entero);
    printf("La direccion del puntero double* es   0x%x\n\n", *p_doble);
    
   
    printf("La valor del char    es   %c\n", caracter);
    printf("La valor del int     es   %d\n", entero);
    printf("La valor del double  es   %lf\n", doble);
    printf("La valor del char*   es 0x%x\n", p_caracter);
    printf("La valor del int*    es 0x%x\n", p_entero);
    printf("La valor del double* es 0x%x\n\n", p_doble);
    
    
    printf("El tamanio del char        es %d bytes\n", sizeof(caracter));
    printf("El tamanio del int         es %d bytes\n", sizeof(entero));
    printf("El tamanio del double      es %d bytes\n", sizeof(doble));
    printf("El tamanio del char*       es %d bytes\n", sizeof(p_caracter));
    printf("El tamanio del int*        es %d bytes\n", sizeof(p_entero));
    printf("El tamanio del double*     es %d bytes\n\n", sizeof(p_doble)); 


    
    




}
        