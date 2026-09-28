#include <stdlib.h>
#include "lista.h"

int *crear_arreglo(int cantidad)
{
    return malloc(cantidad * sizeof(int));
}
