

#include <stdio.h>

    #define LONG_CADENA 50
    #define TRUE 1
    #define FALSE 0

// ------------------------------ 
int longitud_cadena(char cadena[])
{
   int i = 0;
   
   while (cadena[i] != '\0' && i < LONG_CADENA)  	// busco el final de la cadena
   {
       i++;
   }
   return i;
}

// ------------------ BOOLEANA ------- 
int es_palindromo(char cadena[])
{
   int i = 0;
   int j = 0;
   int bandera = TRUE;

   j = longitud_cadena(cadena) - 1;

   while (i < j && bandera != 0)
   {
       if(cadena[i] != cadena[j])
       {
           bandera = FALSE;                     
       }
       i++;
       j--;
   }
   return bandera;
}


// ------------ MAIN -----------------
int main()
{
   char cadena[LONG_CADENA];
   int largo = 0;
 
   printf("Ingresa un arreglo, a ver si es palíndromo: \n\t");
   scanf("%s", &cadena[0]);

   if (es_palindromo(cadena))
     {
       printf("Si, has ingresado un palíndromo");
     }
   else
     {
       printf("este arreglo no es un palíndromo");
     }
 
   return 0;  
}
 
