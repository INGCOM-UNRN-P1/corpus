/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_066
*************************/
#include <stdio.h>
#define CARACTERES_MAXIMOS_CADENA 50
#define CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR 20
int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i=0;
    int largo=0;
    for (i=0;i<capacidad_cadena;i++){
        if(cadena[largo]!='\0')
        {
            largo=largo+1;
        }else{
            break;
        }
    }
	return largo;
}
char* busqueda(char *cadena, int largo, char *busqueda)
{
    char* puntero;
    int i;
    puntero=NULL;
    for(i=0;i<largo;i++){
        if(cadena[i]==busqueda[0])
        {
            puntero = &cadena[i];
            return puntero;
        }
    }
	return puntero;
}
int main(int argc, char *argv[])
{
    char cadena_solicitada[CARACTERES_MAXIMOS_CADENA];
    char caracter_a_buscar[1];
    int tamanio_caracteres_ingresados,tamanio_caracter_busqueda;
    char* resultado_busqueda;
    while(1)
    {
        printf("\nIngrese una cadena menor a %d caracteres: ",CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR);
        scanf("%s",&cadena_solicitada);
        tamanio_caracteres_ingresados=largo_cadena(cadena_solicitada,CARACTERES_MAXIMOS_CADENA);
        if(tamanio_caracteres_ingresados>CANTIDAD_CARACTERES_MAXIMOS_CADENA_A_SOLICITAR || tamanio_caracteres_ingresados<0)
        {
            printf("\nIntentelo nuevamente\n");
        }else{
            break;
        }
    
    }
    printf("\nIngrese un caracter a buscar: ");
    scanf("%s",&caracter_a_buscar);
    resultado_busqueda = busqueda(cadena_solicitada,tamanio_caracteres_ingresados,caracter_a_buscar);
    printf("\nLa direccion dada por cadena solicitada es %u\n", cadena_solicitada);
    printf("\nLa direccion dada por el puntero es %u\n", *&resultado_busqueda); 
	return 0;
}
