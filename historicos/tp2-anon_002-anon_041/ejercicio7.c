

#include <stdio.h>



int multiplicacion_lenta(int numero, int multiplicador)
{
    int i;
    int resultado_multiplicacion = 0;

    for(i = 0;i < multiplicador; i++)
    {
        resultado_multiplicacion = resultado_multiplicacion + numero;
    }

    return resultado_multiplicacion;
}



int potencia_lenta(int numero, int potencia)
{
    int resultado_potencia = 1;
    int i;

    for(i = 0;i < potencia;i++)
    {
        resultado_potencia = multiplicacion_lenta(resultado_potencia, numero);
    }

    return resultado_potencia;
}


int main()
{
    int numero;
    int potencia;
    int resultado;

    printf("Ingrese un numero para calcular la potencia a travez de operaciones lentas:\n");
    printf("Ingrese el numero: ");
    scanf("%d", &numero);
    printf("Ingrese la potencia: ");
    scanf("%d", &potencia);

    resultado = potencia_lenta(numero, potencia);
    printf("El resultado es: %d", resultado);

    return 0;
}