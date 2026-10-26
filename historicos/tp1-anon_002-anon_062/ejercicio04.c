



#include <stdio.h>

int comparar(int numero_a, int numero_b)
// @param ´numero_a´ y ´numero_b´ son los valores que se comparan
// ´bandera´ es un flag que adopta los valores según el result de comparar
// se devuelve con la funcion
{
   int bandera = 0;

   if (numero_a < numero_b)
   {
      bandera = -1;
   }
   if (numero_b < numero_a)
   {
      bandera = 1;
   }

   return bandera;

// en caso que los valores ingresados sean iguales, flag = 0
// y nunca entró en los condicionales
}


// --------------------------------------

int main()
{
    int numero_a = 0;
    int numero_b = 0;
    int resultado = 0;

    printf("Ingrese su primer numero :  \n");
    scanf("%d",&numero_a);
    printf("Ingrese el segundo numero : \n");
    scanf("%d",&numero_b);

    resultado = comparar(numero_a, numero_b);
    printf("%d", resultado);
    return 0;
}
