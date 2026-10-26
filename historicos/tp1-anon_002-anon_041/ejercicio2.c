

#include <stdio.h>



float centigrados_a_fahrenheit(float centigrados)
{
    return centigrados * 1.8 + 32;
}



float fahrenheit_a_centigrados(float fahrenheit)
{
    return (fahrenheit - 32) / 1.8;
}

int main()
{
    int tipo_conversion;
    float centigrados;
    float fahrenheit;
    float resultado;
    float numero_a_convertir;

    printf("1: Centigrados a Fahrenheit\n2: Fahrenheit a Centigrados\n: ");
    scanf("%d", &tipo_conversion);

    if (tipo_conversion == 1)
    {
        printf("Ingrese el numero entero o decimal a convertir: \n");
        scanf("%f", &numero_a_convertir);
        resultado = centigrados_a_fahrenheit(numero_a_convertir);
        printf("%f", resultado);
    }
    else if (tipo_conversion == 2)
    {
        printf("Ingrese el numero entero o decimal a convertir: \n");
        scanf("%f", &numero_a_convertir);
        resultado = fahrenheit_a_centigrados(numero_a_convertir);
        printf("%f", resultado);
    }
    else
    {
        printf("No se ingresaron valores correctos. \n");
    }

    return 0;
}