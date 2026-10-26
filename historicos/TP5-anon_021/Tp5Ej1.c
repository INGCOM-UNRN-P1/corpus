/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_021@ 
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
    
int unnumero;

char unchar;

double unfloat;

int *unnumerop = &unnumero;

char *uncharp = &unchar;

double *unfloatp = &unfloat;

srand(time(NULL));

unnumero = rand()%100;

unfloat = rand()%100;

unchar = 35 + rand()%140;

        
printf("\nLa direccion del char    \t unchar es 0x% x\n", &unchar);

printf("La direccion del int     \t unnumero es 0x% x\n", &unnumero);

printf("La direccion del double  \t unfloat es 0x% x\n", &unfloat);

printf("La direccion del char*   \t uncharp es 0x% x\n", &uncharp);

printf("La direccion del int*    \t unnumerop es 0x% x\n", &unnumerop);

printf("La direccion del double* \t unfloatp es 0x% x\n", &unfloatp);

        
printf("\nEl valor del char    \t unchar es %c\n", unchar);

printf("El valor del int     \t unnumero es %d\n", unnumero);

printf("El valor del double  \t unfloat es %f\n", unfloat);

printf("El valor del char*   \t uncharp es %c\n", *uncharp);

printf("El valor del int*    \t unnumerop es %d\n", *unnumerop);

printf("El valor del double* \t unfloatp es %f\n", *unfloatp);

        
printf("\El tamaño del char    \t unchar es %d\n", sizeof(unchar));

printf("El tamaño del int     \t unnumero es %d\n", sizeof(unnumero));

printf("El tamaño del double  \t unfloat es %d\n", sizeof(unfloat));

printf("El tamaño del char*   \t uncharp es %d\n", sizeof(*uncharp));

printf("El tamaño del int*    \t unnumerop es %d\n", sizeof(*unnumerop));

printf("El tamaño del double* \t unfloatp es %d\n", sizeof(*unfloatp));

return 0;
}
