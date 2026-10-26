

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
#define TAMANO_CADENA 100
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

int es_palindromo(char *texto)
// Precondiciones: El valor de entrada debe ser una un array de caracteres
// Postcondiciones: Devolverá un 1 si el texto se lee igual en un sentido que en otro, de caso contrario,
//                  devolverá un 0 si el texto no es un palindromo
{
    int longitudTexto = strlen(texto);
    int contadorSimilitudes = 0;
    for (int i = 0; i < longitudTexto; i++)
    {
        if (tolower(texto[i]) == tolower(texto[longitudTexto - 1 - i]))
        {
            contadorSimilitudes = contadorSimilitudes + 1;
        }
    }
    if (contadorSimilitudes == longitudTexto)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int main()
{
    char texto[TAMANO_CADENA];
    printf(ANSI_COLOR_CYAN "\nEjercicio 8: Palíndromo" ANSI_COLOR_RESET "\n");
    printf("Mediante el ingreso de un texto, indicar si es un palíndromo\n\n");
    printf("Introduzca un texto: ");
    fflush(stdout);
    scanf("%s", &texto);
    if (es_palindromo(texto) == TRUE)
    {
        printf("'%s' es un palindromo? %s\n", texto, ANSI_COLOR_GREEN "Verdadero");
    }
    else
    {
        printf("'%s' es un palindromo? %s\n", texto, ANSI_COLOR_RED "Falso");
    }
    return 0;
}