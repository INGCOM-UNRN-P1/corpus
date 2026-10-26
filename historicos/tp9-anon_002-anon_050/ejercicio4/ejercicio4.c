



#include <stdio.h>
#include <string.h>

/**
 * Determina si una cadena es palíndromo o no.
 *
 * @pre cadena != NULL
 * @param cadena La cadena que se desea verificar.
 * @param inicio El índice de inicio de la subcadena actual.
 * @param fin El índice final de la subcadena actual.
 * @return 1 si la cadena es palíndromo, 0 si no lo es.
 */
int palindromo(char *cadena, int inicio, int fin)
{
    int ret;
    if (inicio >= fin)
    {
        ret = 1;
    }
    else if (cadena[inicio] != cadena[fin])
    {
        ret = 0;
    }
    else 
    {
        ret = palindromo(cadena, inicio + 1, fin - 1);
    }
    return ret;
}

int main()
{
    char cadena[100];
    printf("Ingrese texto: ");
    scanf("%s", cadena);
    if(palindromo(cadena, 0, strlen(cadena) - 1))
    {
        printf("%s es palíndromo.\n", cadena);
    }
    else 
    {
        printf("%s no es palíndromo.\n", cadena);
    }
    return 0;
}