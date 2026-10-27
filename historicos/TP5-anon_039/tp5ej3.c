
#include <stdio.h>
#define BUSCAQUEDA_NO_ENCONTRADA NULL
#define CADENA_CORTA -1
#define MAX_CADENA 150

int largo_cadena(char *cadena, int capacidad_cadena);
char* busqueda(char *cadena, int largo, char *busqueda);

//Función Principal
int main(int argc, char *argv[])
{
    char cadena[MAX_CADENA] = "Hola Mundo, soy la variable";
    char *p_ocurrencia;
    char buscar[MAX_CADENA] = "Mundo";
    
    printf("\nBUSQUEDA\n");
    p_ocurrencia = busqueda(cadena, MAX_CADENA, buscar);
    printf("El puntero de la cadena es = %s\nLo que contiene es '%s'\n", p_ocurrencia, p_ocurrencia);
    
    return 0;
}

char* busqueda(char *cadena, int largo, char *busqueda)
{
    int i;
    int j;
    int largo_buscar = largo_cadena(busqueda, MAX_CADENA);
    
    for (i = 0; i <= largo; i++)
    {
        
        for (j= 0; j < largo_buscar; j++)
        {
            if (cadena[i+j] == busqueda[j])
            {
                if (j == largo_buscar-1)
                {
                    return &cadena[i];
                }
            }
            else
            {
                break;
            }
        }
    }
    return BUSCAQUEDA_NO_ENCONTRADA;
}
    
int largo_cadena(char *cadena, int capacidad_cadena)
{
    int i = 0;
    
    while (cadena[i] != '\0')
    {
        if (i <= capacidad_cadena)
        {
            i++;
        }
        else
        {
            return CADENA_CORTA;
        }
    }
    return i;
}