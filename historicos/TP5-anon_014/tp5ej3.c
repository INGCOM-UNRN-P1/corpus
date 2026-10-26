/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_014 de GitHub
 *************************/
#include <stdio.h>
#include <string.h>
#define CADENA_MAX 50

int main(int argc, char *argv[]);
char* busqueda(char *cadena, int largo, char *busqueda);

char* busqueda(char *cadena, int largo, char *busqueda)
{
    for( ; *cadena; ++cadena)
    {
        char* puntero1 = busqueda;
        for( char* puntero2 = cadena; *puntero1==*puntero2 && *puntero1; ++puntero1, ++puntero2);
        if( *puntero1 == '\0' )
        {
            return cadena;
        }
    }
    return NULL;
}
 int main(int argc, char *argv[])
{
    char cadena[CADENA_MAX];
    char cadena1[CADENA_MAX];
    char *aparicion;
    char *esperado ;

    printf("Ingrese la primer cadena: ");
    gets(cadena);
    printf("Ingrese la segunda cadena: ");
    gets(cadena1);

    aparicion = busqueda(cadena,CADENA_MAX, cadena1);
    esperado = strstr(cadena,cadena1);
    printf("\t\tResultado Obtenido: %s\n"
           "\t\tResultado esperado: %s",aparicion,esperado);
    return 0;
 }
