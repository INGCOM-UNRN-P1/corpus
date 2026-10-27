
#include <stdio.h>

#define CADENA_CORTA   -1
#define MAX             10
#define TRUE            1
#define FALSE           0

int largo_cadena(char *cadena, int capacidad_cadena);

int copiadora(char *origen, char *destino, int capacidad_destino);

int inversor(char* origen, char* destino, int capacidad_destino);

int es_palindromo(char *cadena, int largo);

int main(int argc, char *argv[])
{
    int largo;
    char cadena[] = "Espada";
    char cadena_dos[] = "Mundo";
    char copia[MAX];
    char copia_INV[MAX];
    int palindromo;

    largo = largo_cadena(cadena, MAX);
    printf("El largo de la cadena [ %s ] es: %i \n\n", cadena, largo);

    
    largo = copiadora(cadena, copia, 6);

    printf("\t %s \n\n", copia);
    printf("tamanio = \t %i \n\n", largo);

    largo = largo_cadena(cadena_dos, MAX);
    printf("Cadena original [ %s ] y su largo: [ %i ]\n\n", cadena_dos, largo);

    largo = inversor(cadena_dos, copia_INV, MAX);
    printf("Cadena invertida [ %s ] y su largo: [ %i ]\n\n", copia_INV, largo);

    palindromo = es_palindromo(cadena, largo_cadena(cadena, MAX));

    if(palindromo == 0)
    {
        printf("La cadena \t[ %s ] \t no es palindromo!\n\n", cadena);
    }
    else if(palindromo = 1)
    {
        printf("La cadena \t[ %s ] \t es palindromo!\n\n", cadena);
    }
    else
    {
        printf("ERROR. cadena \t [ %s ]\n\n", cadena_dos);
    }

   
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

int copiadora(char *origen, char *destino, int capacidad_destino)
{
    int retorno = -1;
    for(int i=0; i<= capacidad_destino; i++)
    {
        destino[i] = origen[i];
        if( i == capacidad_destino || origen[i] == '\0' )
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int inversor(char* origen, char* destino, int capacidad_destino)
{
    int largo = largo_cadena(origen, MAX);

    int j = 0;
    for(int i = largo-1; i>=0; i--)
    {
        if ( j == capacidad_destino ) { break; }
        destino[j] = origen[i];
        if ( i == 0 ) { destino[j+1] = '\0'; }
        j = j + 1;
    }
    return j;
}

int es_palindromo(char *cadena, int largo)
{

    char inv[largo];
    inversor(cadena, inv, largo);

    if (*cadena == *inv)
    {
        return TRUE;
    }
    return FALSE;
}