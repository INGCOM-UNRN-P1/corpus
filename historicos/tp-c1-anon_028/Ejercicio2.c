/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_028
Conversion de Temperaturas
Pre-condicion: Ingresar 2 valores para realizar la conversion.

Post-codicion: Se realizara la conversion de grados 
*************************/

#include <stdio.h>

float convertir_a_fahrenheit(float centigrados);
float convertir_a_centigrados(float fahrenheit);


int main()
{
    int opcion;
    float grados, conversion;
    
    printf("Opcion 1: Convertir grados Celsius a Fahrenheit\n");
    printf("Opcion 2: Convertir grados Fahrenheit a Celsius\n");
    scanf("%d", &opcion);
    
    printf("Digite la cantidad de grados: ");
    scanf("%f", &grados);
    
    if(opcion == 1)
    {
        conversion = convertir_a_fahrenheit(grados);
        printf("Su conversion es de: %.2f grados Fahrenheit\n", conversion);
    }
    else 
    {
        conversion = convertir_a_centigrados(grados);
        printf("Su conversion es de: %.2f grados Celsius\n", conversion);
    }
    
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
