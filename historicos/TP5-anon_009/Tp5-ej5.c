
#include <stdio.h>
#include <string.h>
#define MAX_CARACTERES_LINEA 50
#define MAX_CARACTERES_TEXTO 500


int separador(int cantidad, char *input[]);

int main(int argc, char *argv[])
{

    separador(argc, &argv[1]);

}


int separador(int cantidad, char *input[])
{

    char texto[MAX_CARACTERES_TEXTO];
    char almacenador[MAX_CARACTERES_LINEA];
    int j = 0;
    int k = 0;

    if (cantidad < 2) //Si no se introduce un texto en la consola se pide que por favor se lo haga
    {
        printf("Por favor ingrese algun texto\n");
    }
    else if (strlen(*input) > MAX_CARACTERES_TEXTO) //Si la longitud del texto es mas larga de la permitida se pide uno nuevo
    {
        printf("Ingrese un texto que tenga menos de %d caracteres", MAX_CARACTERES_TEXTO);
    }
    else //Si todo esta correcto se copia el input del usuario a la varaible texto
    {
        strcpy(texto, *input);
    }
    
    
    almacenador[0] = '\0';//inicializo el almacenador vacio
    
    for (int i = 0; i < strlen(texto); i++)
    {
        if (texto[k] == '\0') //chequeo si mi texto ya esta en el final
        {
            almacenador[j] = '\0';
            printf("\n%s", almacenador);
            break;
        }
        else if ((texto[k] == '\\') && (texto[k + 1] == 'n')) //chequeo si esta en el final de una línea. La imprimo y vuelvo a inicializar el acumulador
        {
            almacenador[j] = '\0';
            printf("\n%s\n", almacenador);
            almacenador[0] = '\0';
            j = 0;
            k = k + 2;// salteo el \n
        }
        else //Armo la línea hasta llegar al \n
        {
            almacenador[j] = texto[k];
            j = j + 1;
            k = k + 1;
            
        }
        
    }


    return 0;
    

}