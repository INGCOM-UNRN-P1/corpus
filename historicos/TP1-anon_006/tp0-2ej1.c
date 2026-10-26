/****************************************************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*****************************************************************/



#include <stdio.h>
 
int main () 
{
    int numeroIngresado;
   
    printf("\n");
    printf("\nIngrese un numero entero comprendido entre el 1 y el 7: ");
    scanf("%d", &numeroIngresado);
    
    switch(numeroIngresado) 
    {        
        case 1 :
            printf("\nEl numero %d corresponde al dia Lunes.", numeroIngresado);
            break;
        case 2 :
            printf("\nEl numero %d corresponde al dia Martes.", numeroIngresado);
            break;
        case 3 :
            printf("\nEl numero %d corresponde al dia Miercoles.", numeroIngresado);
            break;
        case 4 :
            printf("\nEl numero %d corresponde al dia Jueves.", numeroIngresado);
            break;
        case 5 :
            printf("\nEl numero %d corresponde al dia Viernes.", numeroIngresado);
            break;
        case 6 :
            printf("\nEl numero %d corresponde al dia Sabado.", numeroIngresado);
            break;
        case 7 :
            printf("\nEl numero %d corresponde al dia Domingo.", numeroIngresado);
            break;    
        default :
            printf("\nEl numero %d no corresponde a un dia de la semana.", numeroIngresado);
   }
   printf("\nMuchas Gracias!");
   printf("\n");
}