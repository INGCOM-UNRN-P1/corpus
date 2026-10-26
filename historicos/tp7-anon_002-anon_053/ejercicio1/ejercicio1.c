

#include <stdlib.h>
#include <stdio.h> 

#include "funciones.c"




int* reserva_entero(int valor);
int libera_entero(int* ptr);

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        printf("Uso: %s <valor>\n", argv[0]);
        return 1;
    }

    
    int valor = 0;
    char *arg = argv[1];
    while (*arg != '\0') 
    {
        valor = valor * 10 + (*arg - '0');
        arg++;
    }

    int el_numero = 4;
    //Funciones en archivo "funciones.c"
    int* entero_ptr = reserva_entero(valor);
    int suma = suma_lenta(el_numero, *entero_ptr);
    int resta = resta_lenta(el_numero, *entero_ptr);
    int multiplicacion = multiplica_lenta(el_numero, *entero_ptr);
    int division = division_lenta(el_numero, *entero_ptr);

    if (entero_ptr != NULL) 
    {
        printf("Valor asignado: %d\n", *entero_ptr);

        // Realizar operaciones lentas
        printf("Suma lentamente %d: %d\n", el_numero, suma);
        printf("Resta lentamente %d: %d\n", el_numero, resta);
        printf("Multiplicación lenta %d: %d\n", el_numero, multiplicacion);
        if (*entero_ptr != 0) 
        {
            printf("División lenta por %d: %d\n",el_numero, division);
        }

        // Liberar memoria
        int resultado = libera_entero(entero_ptr);
        printf("Valor liberado: %d\n", resultado);
    } 
    else 
    {
        printf("Error: No se pudo asignar memoria para el entero.\n");
    }

    return 0;
}


int* reserva_entero(int valor) 
{
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) 
    {
        *ptr = valor;
    }
    return ptr;
}


int libera_entero(int* ptr) 
{
    if (ptr != NULL) {
        int valor = *ptr;
        free(ptr);
        return valor;
    } 
    else 
    {
        return 0;
    }
}
