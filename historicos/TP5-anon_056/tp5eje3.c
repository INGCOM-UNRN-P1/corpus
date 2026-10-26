 /*************************
	* Ingenieria en Computación - UNRN Andina
	* Programación 1
	* @anon_056
*************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100


int largo_cadena(char *cadena, int capacidad_cadena)
{
        int len;
        int i = 0;

        for (len = 0; len < capacidad_cadena; i++)
        {
            if (cadena[i] == '\n')
            {
                break;
            }
            else
            {
                len++;
            }
        }
        return len;
}

char* busqueda(char *cadena, int largo, char *busqueda)
{    
    int ocurrencia = 0;
    int indice = 0;
    int i = 0;

    while (cadena[indice] != '\0')
    {
        if (cadena[indice] == busqueda[0])
        {
            ocurrencia = 1;
            while (busqueda[i] != '\0')
            {
                if (cadena[i+indice] != busqueda[i])
                {
                    ocurrencia = 0;
                    break;
                }
                
                i++;
            }
            
        }

        if (ocurrencia == 1)
        {
            break;
        }
        else
        {
            indice++;
        }
        
    }
    if (ocurrencia == 1)
    {
        char caracter = cadena[indice];
        char *puntero = &caracter;
        return puntero;
    }
    else
    {
        return NULL;
    }
    

}


int main(int argc, char const *argv[])
{
    char string1[MAX_LEN];
    char string2[MAX_LEN];

    int len_string1;
    int len_string2;

    printf("Ingrese string: ");
    fgets(string1, MAX_LEN, stdin);
    printf("Ingrese cadena a buscar: ");
    fgets(string2, MAX_LEN, stdin);

    len_string1 = largo_cadena(string1, MAX_LEN);
    len_string2 = largo_cadena(string2, MAX_LEN);

    string1[len_string1] = '\0';
    string2[len_string2] = '\0';
    
    printf("\n%p\n", busqueda(string1, len_string1, string2));

    return 0;
}
