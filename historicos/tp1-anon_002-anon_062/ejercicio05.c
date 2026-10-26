



#include <stdio.h>

int suma_lenta(int numero, int otronumero)
// @param ´numero´ y ´otronumero´ son los dos sumando
// ´suma´ devuelve la suma a izquierda o derecha de los parámetros

{
    int i = 1;
    int suma = 0;
    int absoluto = 0;
    int unidad = 1;			// unnidad va a ser el incrementador o decrementador

    absoluto = otronumero;
    suma = numero; 

   if (otronumero < 0)			// si el seg numero es negat o 0
   {					// lo convierto a positivo para
      absoluto = (-1) * otronumero;	// que el contador vaya hacia adelante
      unidad = -1;
   }

   if (otronumero != 0)
   {
      for (i = 1; i < absoluto + 1; i++)
      {
         suma = suma + unidad;
      }
   }
    
   return suma;
}





// ------------------------------
int main()
{
    int numero = 0;
    int otronumero = 0;
    int resultado = 0;

    printf("Ingrese su primer numero :  \n");
    scanf("%d", &numero);
    printf("Ingrese el segundo numero : \n");
    scanf("%d", &otronumero);

    resultado = suma_lenta(numero, otronumero);
    printf("%d", resultado);
    return 0;
}

