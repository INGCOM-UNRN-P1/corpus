
#include <stdio.h>
float convertir_a_fahrenheit(float centigrados)
{
    
    centigrados = (centigrados * 9/5) + 32;
    return centigrados;
}
float convertir_a_centigrados(float fahrenheit)
{
    fahrenheit = (fahrenheit - 32) * 5/9;
    return fahrenheit;
}
int main()
{
    float centigrados;
    float fahrenheit;
    float guardarcent;
    float guardarfahr;
    printf("Ingrese un numero centigrado para transformar a fahr: \n");
	scanf("%f", &centigrados);
    
    printf("Ingrese un numero fahrenheint para transformar a centigrados: \n");
	scanf("%f", &fahrenheit);
    
    guardarfahr = convertir_a_centigrados(fahrenheit);
    guardarcent = convertir_a_fahrenheit(centigrados);
    printf("Conversion de centigrados a fahrenheint %1.3f \n", guardarcent);
    printf("Conversion de fahrenheit a centigrados %1.3f \n", guardarfahr);
    
    return 0;
}
