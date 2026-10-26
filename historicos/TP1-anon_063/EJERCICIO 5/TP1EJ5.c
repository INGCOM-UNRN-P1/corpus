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
    int cont=0;

    printf("INGRESE UN PRIMER NUMERO = ");
    scanf("%d",&numero_uno);
    printf("\nINGRESE UN SEGUNDO NUMERO = ");
    scanf("%d",&numero_dos);

    for(cont=numero_uno;cont<=numero_dos;cont++)
    {
        printf(" %d \n",cont);
    }
    return 0;
}
