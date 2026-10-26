/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
santivosabes de GitHub
*************************/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int numero_uno=0;
    int numero_dos=0;

    printf("INGRESE NUMERO A= ");
    scanf("%d",&numero_uno);
    printf("\nINGRESE NUMERO B= ");
    scanf("%d",&numero_dos);
    printf("Resultados= \n ");
    printf("A*B = %d \n",numero_uno*numero_dos);
    printf("A+B = %d \n",numero_uno+numero_dos);
    printf("A-B =%d \n",numero_uno-numero_dos);
    printf("A/B =%d \n",numero_uno/numero_dos);
    printf("A%B =%d \n",numero_uno%numero_dos);

    return 0;
}
