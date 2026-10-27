

#include <stdio.h>

int main(int argc, char *argv[])
{
    int *intpuntero, entero = 20;
    double *doublepuntero, racional = 34.56;
    char cadena[9] = "El texto";
    char *punterocadena = cadena;
    intpuntero = &entero;
    doublepuntero = &racional;
    printf("char:\t %s \n", cadena);
    printf("int:\t %d \n", entero);
    printf("double:\t %.2f \n\n", racional);
    printf("la direccion del char es:\t ---0x%x---\n",&cadena);
    printf("la direccion del int es:\t ---0x%x---\n",&entero);
    printf("la direccion del double es:\t ---0x%x---\n",&racional);
    printf("la direccion del char* es:\t ---0x%x---\n",&punterocadena);
    printf("la direccion del int* es:\t ---0x%x---\n",&intpuntero);
    printf("la direccion del double* es:\t ---0x%x---\n",&doublepuntero);
    
    printf("\nel tamanio de char es:\t\t ---%d bytes---\n",sizeof(cadena));
    printf("el tamanio de int es:\t\t ---%d bytes---\n",sizeof(entero));
    printf("el tamanio de double es:\t ---%d bytes---\n",sizeof(racional));
    printf("el tamanio de char* es:\t\t ---%d bytes---\n",sizeof(punterocadena));
    printf("el tamanio de int* es:\t\t ---%d bytes---\n",sizeof(intpuntero));
    printf("el tamanio de double* es:\t ---%d bytes---\n",sizeof(doublepuntero));

    printf("\nel valor de char es:\t\t ---%s---\n", cadena);
    printf("el valor de int es:\t\t ---%d---\n", entero);
    printf("el valor de double es:\t\t ---%.2f---\n", racional);
    printf("el valor de char* es:\t\t ---%p---\n", punterocadena);
    printf("el valor de int* es:\t\t ---%p---\n", intpuntero);
    printf("el valor de double* es:\t\t ---%p---\n", doublepuntero);
    
    return 0;
}