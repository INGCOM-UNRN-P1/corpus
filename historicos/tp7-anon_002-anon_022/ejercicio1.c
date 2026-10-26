#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HASTA MEMORIA DINAMICA. (MALLOC, CALLOC, FREE)
int * reserva_entero(int valor)
{
    int * entero = (int*)malloc(sizeof(int));
    if (entero != NULL)
    {
        *entero = valor;
    }
    else 
    {
        return NULL;
    }
}

int libera_entero(int * valor)
{
    if (valor != NULL)
    {
        int resultado = * valor;
        free(valor);
        return resultado;
    }
    else 
    {
        return  0;
    }
    
}


int main(int argc, char * argv[])
{
    if (argc != 4)
    {
        printf("Falta numero1, operacion, y numero2.\n");
        return 1;
    }
    int num = atoi(argv[1]);
    char operacion = argv[2];
    int num2 = atoi(argv[3]);
    int * ptr_resultado;

    return 0;
}
