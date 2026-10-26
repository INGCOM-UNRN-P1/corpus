

#include <stdio.h>

int largo_seguro(char *cadena);

int main() {
    char cadena[] = "Hola soy Katy";

    int longitud = largo_seguro(cadena);

    printf("Longitud de la cadena: %d\n", longitud);

    return 0;
}


int largo_seguro(char *cadena) 
{
    int longitud;

    char *puntero = cadena; // Inicializar un puntero al principio de la cadena

    while (*puntero != '\0') 
    {
        puntero++; 
    }
    longitud = (puntero - cadena);
    return longitud; 
}
