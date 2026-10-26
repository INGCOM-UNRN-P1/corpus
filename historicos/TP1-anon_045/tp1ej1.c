
#include <stdio.h>


int main(int argc, char *argv[])
{
   int dia;

   printf( "\n Ingrese un numero del 1 al 7: " );
   scanf( "%d", &dia );

   switch ( dia )
   {
      case 1 : printf( "\n   Lunes" );
               break;
      case 2 : printf( "\n   Martes" );
               break;
      case 3 : printf( "\n   Miercoles" );
               break;
      case 4 : printf( "\n   Jueves" );
               break;
      case 5 : printf( "\n   Viernes" );
               break;
      case 6 : printf( "\n   Sabado" );
               break;
      case 7 : printf( "\n   Domingo" );
               break;
   default : printf( "\n Incorrecto" );
   }

   return 0;
}