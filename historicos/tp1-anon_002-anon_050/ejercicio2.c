

#include <stdio.h>
float centigrados_a_fahrenheit(float gradosf)
{
    return ((gradosf * 1.8) + 32);
}
float fahrenheit_a_centigrados(float gradosc)
{
    return ((gradosc - 32) * 0.55555555555555555);
}

int main()
{
    float temp = 0;
    float result;
    printf("Ingrese el primer número, el valor en grados centígrados para convertir a Fahrenheit: ");
    scanf("%f", &temp);

    if (temp < -273.15)
    {
        printf("Físicamente imposible.\n");
    }    
    result = centigrados_a_fahrenheit(temp);
    printf("El resultado es: %f\n", result);
    
    printf("Ingrese el segundo número, el valor en Fahrenheit para convertir a grados centígrados: ");
    scanf("%f", &temp);

    if (temp < -459.67)
    {
        printf("Físicamente imposible.\n");
    }
    result = fahrenheit_a_centigrados(temp);
    printf("El resultado es: %f\n", result);

    return 0;
}
