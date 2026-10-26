

#include <stdio.h>
#include <stdlib.h>

int es_palindromo(char *cadena, int inicio, int fin);
int longitud_cadena(char *cadena);

int main() 
{
    char *cadena = "radar";
    int longitud = longitud_cadena(cadena);

    if (es_palindromo(cadena, 0, longitud - 1))
    {
        printf("La cadena '%s' es un palíndromo.\n", cadena);
    }
    else
    {
        printf("La cadena '%s' no es un palíndromo.\n", cadena);
    } 
    return 0;
}


int longitud_cadena(char *cadena) 
{
    int longitud = 0;
    while (cadena[longitud] != '\0') 
    {
        longitud++;
    }
    return longitud;
}


int es_palindromo(char *cadena, int inicio, int fin) 
{
    // Si los extremos de la subcadena ya se superan, la subcadena es un palíndromo
    if (inicio >= fin)
    {
        return 1;
    }
    // Si los extremos de la subcadena son diferentes, la subcadena no es un palíndromo
    if (cadena[inicio] != cadena[fin])
    {
        return 0;
    }
    // Continuar con la siguiente subcadena (eliminando los extremos)
    return es_palindromo(cadena, inicio + 1, fin - 1);
}

