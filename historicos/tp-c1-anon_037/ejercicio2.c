

#include <stdio.h>

int convertir_a_fahrenheit( int centigrados);


int convertir_a_centigrados(int fahrenheit);


int main()

{
    int tempcent;
    int tempfahr;

    printf("Ingrese una temperatura en grados centigrados: ");
    scanf("%d", &tempcent);
    tempfahr = convertir_a_fahrenheit(tempcent);

    printf("La temperatura en grados fahrenheit es: %d", tempfahr);
    

    printf("\n\nIngrese una temperatura en grados fahrenheit: ");
    scanf("%d", &tempfahr);
    tempcent = convertir_a_centigrados(tempfahr);

    printf("La temperatura en grados centigrados es: %d", tempcent);

    return 0;
}


int convertir_a_fahrenheit(int centigrados)
{
    int fahrenheit = centigrados*1.8;
    fahrenheit = fahrenheit + 32;

    return fahrenheit;
}

int convertir_a_centigrados(int fahrenheit)
{
    int centigrados = fahrenheit - 32;
    centigrados = centigrados / 1.8;

    return centigrados;
}