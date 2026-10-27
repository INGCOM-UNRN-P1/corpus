
#include <stdio.h>
int mayor_o_menor(int numero);
int main(int argc, char *argv[])
{
    int numero;
    int resultado;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);
    resultado = mayor_o_menor(numero);
    return resultado;
}

int mayor_o_menor(int numero)
{
    while (numero < 100)
    {
        printf("ingrese numero mayor a 100: ");
        scanf("%d", &numero);
        if (numero > 100)
        {
            break;
        }
    }
    printf("El numero %d es mayor a 100", numero);
	return 0;
}


