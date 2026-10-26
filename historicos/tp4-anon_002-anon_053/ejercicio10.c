

#include <stdio.h>

#define ERROR -1

void reemplazarVocales(char *cadena, char caracterIndicado);

int main() 
{
    char cadena[] = "Hola mi nombre es Katherina";
    char caracterIndicado = '~';

    printf("Cadena original: %s\n", cadena);

    reemplazarVocales(cadena, caracterIndicado);

    printf("Cadena con las vocales reemplazadas: %s\n", cadena);

    return 0;
}


void reemplazarVocales(char *cadena, char caracterIndicado) 
{
    int error;
    if (cadena == NULL) 
    {
        error = ERROR; //caso de una cadena nula
    }

    while (*cadena != '\0') 
    {
        if (*cadena == 'a' || *cadena == 'e' || *cadena == 'i' || *cadena == 'o' || *cadena == 'u' ||
            *cadena == 'A' || *cadena == 'E' || *cadena == 'I' || *cadena == 'O' || *cadena == 'U') 
            {
                *cadena = caracterIndicado;
            }
        *cadena++; // Mover el puntero al siguiente carácter
    }
}
