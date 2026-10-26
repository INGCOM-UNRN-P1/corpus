



#include <stdio.h>

float centigrados_a_fahrenheit(float centigrados)
{
    return (centigrados*1.8) + 32;
}


float fahrenheit_a_centigrados(float fahrenheit)
{
    return (fahrenheit-32)/1.8;
}


int main()
{
   float fahrenheit = 0;
   float centigrados = 0;
   float resultado = 0;
   int opcion = 0;
   printf("Elija una opcion: 1 para convertir de F a C, 2 para convertir de C a F\n");
   scanf("%d",&opcion);
   if (opcion==1)
   {
        printf("Ingrese la temperatura en Fahrenheit: \n");
        scanf("%f",&fahrenheit);
        resultado = fahrenheit_a_centigrados(fahrenheit);
        printf("La temperatura convertida a Centigrados es: %.2f \n", resultado);
   } 
   else if (opcion == 2)
   {
        printf("Ingrese la temperatura en Centigrados: \n");
        scanf("%f",&centigrados);
        resultado = centigrados_a_fahrenheit(centigrados);
        printf("La temperatura convertida a Fahrenheit es: %.2f \n", resultado);
   }
   return 0;
}
