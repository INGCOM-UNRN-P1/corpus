

#include <stdio.h>

#define MAX 32

char* busqueda(char *cadena, int largo, char *busqueda);
int largo_cadena(char *cadena, int capacidad_cadena);


int main(int argc, char *argv[])
{

    char cadena[] = "Texto mu muy simple porque si";
    char palabra[] = "muy";

    char *buscar = busqueda(cadena, largo_cadena(cadena, MAX), palabra);

    printf("\n\n\t\t%s\n\n", buscar);

}

char* busqueda(char *cadena, int largo, char *busqueda)
{

    int largo_busqueda = largo_cadena(busqueda, MAX);
    int coincidencias = 0;
    int i;
    int j = 0;
    char *retorno;

    for(i=0; i<largo; i++ )
    {
        if(cadena[i] == busqueda[j])
        {
            printf("if igualdad.\n");
            coincidencias = coincidencias + 1;
            j = j + 1;
        }
        else
        {
            printf("else.\n");
            coincidencias = 0;
            j = 0;
        }
        if (coincidencias == largo_busqueda)
        {
            printf("IF coincidencias.\n");
            retorno = cadena+(i-1);
            break;
        }
    }

    return retorno;

}

int largo_cadena(char *cadena, int capacidad_cadena)
{
    int retorno = -1;
    
    for(int i = 0;i<=capacidad_cadena;i++)
    {
        if(cadena[i]=='\0')
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}