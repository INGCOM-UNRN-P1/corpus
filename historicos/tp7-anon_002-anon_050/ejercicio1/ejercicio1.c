



#include <stdio.h>
#include <stdlib.h>

int* reserva_entero(int valor)
{
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL)
    {
        *ptr = valor;
    }
    return ptr;
}

void libera_entero(int* valor)
{
    if (valor != NULL)
    {
        free(valor);
    }
}

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        printf("Opciones: %s <valor1> <operador> <valor2>.\n", argv[0]);
        return 1;
    }

    int valor1 = atoi(argv[1]);
    int operador = argv[2][0];
    int valor2 = atoi(argv[3]);

    int* resultado = NULL;

    switch (operador)
    {
        case '+':
            resultado = reserva_entero(valor1 + valor2);
            break;
        case '-':
            resultado = reserva_entero(valor1 - valor2);
            break;
        case '*':
            resultado = reserva_entero(valor1 * valor2);
            break;
        case '/':
            if (valor2 != 0)
            {
                resultado = reserva_entero(valor1 / valor2);
            }
            else
            {
                printf("Se intento dividir por cero.\n");
            }
            break;
        default:
            printf("Operador invalido, por far use +, -, *, o /.\n");
    }

    if (resultado != NULL)
    {
        printf("%d\n", *resultado);
        libera_entero(resultado);
    }

    return 0;
}