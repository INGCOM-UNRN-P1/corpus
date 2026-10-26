

#include <stdio.h>
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

double convertir_a_fahrrenheit(double centigrados)
// Precondiciones: El valor de entrada tiene que ser de tipo double y puede tener una presición de hasta 2 decimales
// Postcondiciones: Devolverá un valor correspondiente a la conversion de centigrados a fahrrenheit
{
   return (centigrados * 9 / 5) + 32;
}

double convertir_a_centigrados(double fahrenheit)
// Precondiciones: El valor de entrada tiene que ser de tipo double y puede tener una presición de hasta 2 decimales
// Postcondiciones: Devolverá un valor correspondiente a la conversion de fahrrenheit a centigrados
{
   return (fahrenheit - 32) * 5 / 9;
}

int main()
{
   double centigrado;
   double fahrenheit;
   double centigradoToFahrrenheit;
   double fahrrenheitToCentigrado;
   printf(ANSI_COLOR_CYAN "\nEjercicio 2: Conversión de temperaturas" ANSI_COLOR_RESET "\n");
   printf("Mediante el ingreso de un número, indicar su conversión de temperatura\n\n");
   printf("Conversión de centigrados a fahrrenheit\n");
   printf("Introduzca una temperatura en °c: ");
   fflush(stdout);
   scanf("%lf", &centigrado);
   centigradoToFahrrenheit = convertir_a_fahrrenheit(centigrado);
   printf("%.2f°c -> %.2f°f\n", centigrado, centigradoToFahrrenheit);
   printf("\nConversión de fahrrenheit a centigrados\n");
   printf("Introduzca una temperatura en °f: ");
   fflush(stdout);
   scanf("%lf", &fahrenheit);
   fahrrenheitToCentigrado = convertir_a_centigrados(fahrenheit);
   printf("%.2f°f -> %.2f°c\n", fahrenheit, fahrrenheitToCentigrado);
   return 0;
}