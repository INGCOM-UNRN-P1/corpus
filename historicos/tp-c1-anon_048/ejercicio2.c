

#include <stdio.h>

float convertir_a_fahrenheit(float centigrados);
float convertir_a_centigrados(float fahrenheit);
float conversor();

int main()
{
    conversor();
    
    return 0;
}


float convertir_a_fahrenheit(float centigrados)
{
    float fahrenheit = 0;

    fahrenheit = centigrados * 1.8 + 32;
    return fahrenheit;
}  


float convertir_a_centigrados(float fahrenheit)
{
    float celsius = 0;

    celsius = (fahrenheit - 32) / 1.8;
    return celsius;
}


float conversor()
{
    int opcionSeleccionada = 0;
    float grados;
    float conversion;
    
    do
    {
        printf("Seleccione la opcion deseada\n");
        printf("Opcion 1: Convertir grados Celsius a Fahrenheit\n");
        printf("Opcion 2: Convertir grados Fahrenheit a Celsius\n");
        scanf("%d", &opcionSeleccionada);
        if(opcionSeleccionada < 1 || opcionSeleccionada > 2)
        {
            printf("Opcion invalida\n");
        }
    } while (opcionSeleccionada < 1 || opcionSeleccionada > 2);
    
    printf("Digite la cantidad de grados: ");
    scanf("%f", &grados);

    if(opcionSeleccionada == 1)
    {
        conversion = convertir_a_fahrenheit(grados);
        printf("Su conversion es de: %.2f grados Fahrenheit\n", conversion);
    }
    else 
    {
        conversion = convertir_a_centigrados(grados);
        printf("Su conversion es de: %.2f grados Celsius\n", conversion);
    }
    
    return conversion;
}

