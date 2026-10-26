/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * @anon_023
 *************************/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char carac = 'Z';
    int ent = 69;
    double dob = 4.2;
    
    char *puntero_carac = &carac;
    int *puntero_ent = &ent;
    double *puntero_dob = &dob;
    
    // Direcciones:
    printf("La direccion del char\t 'carac'\t es 0x%x\n", &carac);
    printf("La direccion del int\t 'ent'\t\t es 0x%x\n", &ent);
    printf("La direccion del double\t 'dob'\t\t es 0x%x\n", &dob);
    printf("La direccion del char*\t 'puntero_carac' es 0x%x\n", &puntero_carac);
    printf("La direccion del int*\t 'puntero_ent'\t es 0x%x\n", &puntero_ent);
    printf("La direccion del double* 'puntero_dob'\t es 0x%x\n\n", &puntero_dob);
    
	// Valores:
    printf("El valor del char\t 'carac'\t es %c\n", carac);
    printf("El valor del int\t 'ent'\t\t es %d\n", ent);
    printf("El valor del double\t 'dob'\t\t es %f\n", dob);
    printf("El valor del char*\t 'puntero_carac' es %x\n", puntero_carac);
    printf("El valor del int*\t 'puntero_ent'\t es %x\n", puntero_ent);
    printf("El valor del double*\t 'puntero_dob'\t es %x\n\n", puntero_dob); 
    
    // Tamaños:
    printf("El tamaño del char\t 'carac'\t es %x bytes\n", sizeof(carac));
    printf("El tamaño del int\t 'ent'\t\t es %x bytes\n", sizeof(ent));
    printf("El tamaño del double\t 'dob'\t\t es %x bytes\n", sizeof(dob));
    printf("El tamaño del char*\t 'puntero_carac' es %x bytes\n", sizeof(puntero_carac));
    printf("El tamaño del int*\t 'puntero_ent'\t es %x bytes\n", sizeof(puntero_ent));
    printf("El tamaño del double*\t 'puntero_dob'\t es %x bytes\n", sizeof(puntero_dob));
    
    return 0;
}
    
    