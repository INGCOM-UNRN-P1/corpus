#include <stdio.h>
#define SIZE 100
#define FALSE -1


/**
 * Busca una subcadena en una cadena de caracteres.
 * @param cadena Cadena de caracteres en la que se buscara la subcadena.
 * @param capacidad_cadena Capacidad maxima de la cadena.
 * @param busqueda Subcadena que se busca en la cadena.
 * @param capacidad_busqueda Capacidad maxima de la subcadena de basqueda.
 * @return Un puntero al inicio de la subcadena encontrada o NULL si no se encuentra.
 * @pre cadena y busqueda son cadenas validas, capacidad_cadena y capacidad_busqueda son mayores que cero.
 * @post Se devuelve un puntero al inicio de la subcadena encontrada o NULL si no se encuentra.
 */
char* busqueda_cadena(char cadena[], int capacidad_cadena, char busqueda[], int capacidad_busqueda)
{
    int capacidad_total = capacidad_cadena-capacidad_busqueda;
    char * resultado;
    if (capacidad_busqueda > capacidad_cadena) {
        return NULL;
    }
    int i;
    int j;
    for (i = 0; i <= capacidad_total; i++)
    {
        for (j = 0; j < capacidad_busqueda; j++)
        {
            if (cadena[i + j] != busqueda[j])
            {
                FALSE;
            }
        }
        if (j == capacidad_busqueda)
        {
            resultado = &cadena[i];
        }
    }
    
    resultado = NULL;
    return resultado;
}

int main() {
    char cadena[SIZE]; 
    char busqueda[SIZE]; 
    char* resultado;
    int capacidad_cadena = 0;
    int capacidad_busqueda = 0;
    printf("Ingrese una cadena: ");
    scanf("%s", cadena); 
    printf("Ingrese una cadena de busqueda: ");
    scanf("%s", busqueda); 
    while (cadena[capacidad_cadena] != '\0')
    {
        capacidad_cadena++;
    }
    while (busqueda[capacidad_busqueda] != '\0')
    {
        capacidad_busqueda++;
    }
    *resultado = busqueda_cadena(cadena, capacidad_cadena, busqueda, capacidad_busqueda);
    if (resultado != NULL)
    {
        printf("Se encontro la cadena '%s' en la posicion %ld.\n", busqueda, resultado - cadena);
    }
    else
    {
        printf("La cadena '%s' no se encontro en la cadena principal.\n", busqueda);
    }
    return 0;
}
