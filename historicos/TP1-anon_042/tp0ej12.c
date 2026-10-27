
#include <stdio.h>

int comparacion(int entero, int entero_b);
int main(int argc, char *argv[])
{
    int entero = 0;
    int entero_b = 0;
    int resultado;
    printf("Ingrese un numero entero: ");
    scanf("%d", &entero);
    printf("Ingrese otro numero entero: ");
    scanf("%d", &entero_b);
    resultado = comparacion(entero, entero_b);
    return resultado;
}
int comparacion(int entero, int entero_b)
{
    int menor = -1;
    int igual = 0;
    int mayor = 1;
    int return_num;
    if (entero < entero_b)
    {
        return_num = printf("%d", menor);
        return return_num;
    }
    if (entero == entero_b)
    {
        return_num = printf("%d", igual);
        return return_num;
    }
    if (entero > entero_b)
    {
        return_num = printf("%d", mayor);
        return return_num;
    }
}

