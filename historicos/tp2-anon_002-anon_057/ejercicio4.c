

#include <stdio.h>




/**
 * Encuentra el mayor de tres números enteros.
 *
 * @param primero El primer número entero.
 * @param segundo El segundo número entero.
 * @param tercero El tercer número entero.
 * @return El número entero más grande entre los tres.
 *
 * @pre Los argumentos deben ser números enteros válidos.
 * @post El valor devuelto será uno de los tres números ingresado,
 *          más grande entre los tres.
 */
int mayor(int primero, int segundo, int tercero)
{
    int mayor = primero;
    if (mayor < segundo)
    {
        mayor = segundo;
    }
    if (mayor < tercero)
    {
        mayor = tercero;
    }
    return mayor;
}

int main()
{
    int uno;
    int dos;
    int tres;

    printf("Ingrese tres números enteros separados por espacios: ");
    scanf("%d %d %d", &uno, &dos, &tres);

    int resultado = mayor(uno, dos, tres);

    printf("El número mayor es: %d\n", resultado);

    return 0;
}
