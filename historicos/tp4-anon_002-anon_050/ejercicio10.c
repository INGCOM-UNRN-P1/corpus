

#include <stdio.h>

/**
 * La función reemplaza las vocales de una cadena
 * @param cadena a reemplazar
 * @pre char válido
 * @param capacidad de la cadena
 * @pre int sin signo válido 
 * @param vocal char que reemplaza a las vocales de la cadena
 * @pre char válido
*/
void reemplazo(char* cadena, int capacidad, char vocal)
{
    for (int i = 0; i < capacidad && cadena[i] != '\0'; i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' ||
            cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U')
        {
            cadena[i] = vocal;
        }
    }
}

int main()
{
    char cadena[] = "Al fin termino";
    char vocal[1];
    int capacidad = sizeof(cadena);
    printf("Cadena original: %s\n", cadena);
    printf("Ingrese caracter de reemplazo de vocales:\n");
    scanf("%c", &vocal);
    reemplazo(cadena, capacidad, vocal);
    printf("Cadena reemplazada: %s\n", cadena);
    return 0;
}