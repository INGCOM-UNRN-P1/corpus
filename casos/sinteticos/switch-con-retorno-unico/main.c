/**
 * Caso sintético del corpus: switch con un único return (estilo 0x200Ch).
 * Cada rama asigna `resultado` y corta con break: no es una sobreescritura
 * sin lectura (antes 0x2011h marcaba todas las ramas).
 */
#include <stdio.h>

/**
 * Traduce un comando a su código de resultado.
 * @param comando número de comando.
 * @returns el código asociado o -1 si no existe.
 */
int procesar_comando(int comando)
{
    int resultado = 0;
    switch (comando)
    {
    case 1:
        resultado = 10;
        break;
    case 2:
        resultado = 20;
        break;
    case 3:
        resultado = 30;
        break;
    default:
        resultado = -1;
        break;
    }
    return resultado;
}

int main(void)
{
    printf("%d\n", procesar_comando(2));
    return 0;
}
