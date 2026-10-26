

#include <stdio.h>
// Precondición: -273.15 < gradosf
// Postcondición: -459.67 < resultado
float convertir_a_fahrenheit(float gradosf)
{
    return ((gradosf * 1.8) + 32);
}
// Precondición: -459.67 < gradosc
// Postcondición: -273.15 < resultado
float convertir_a_centigrados(float gradosc)
{
    return ((gradosc - 32) * 0.55555555555555555);
}

int main()
{
    float temp = 0;
    printf("Ingrese el primer número, el valor en grados centígrados para convertir a Fahrenheit: ");
    scanf("%f", &temp);

    if (temp < -273.15)
    {
        printf("Físicamente imposible.\n");
    }    
    printf("El resultado es: %f\n", convertir_a_fahrenheit(temp));
    
    printf("Ingrese el segundo número, el valor en Fahrenheit para convertir a grados centígrados: ");
    scanf("%f", &temp);

    if (temp < -459.67)
    {
        printf("Físicamente imposible.\n");
    }

    printf("El resultado es: %f\n", convertir_a_centigrados(temp));

    return 0;
}
