/*********************************************
Ingeniería en Computación - UNRN - Sede Andina
Programación 1
Nombre de usuaria en GitHub: anon_013
*********************************************/

//Trabajo práctico 1:
//Parte A:
//Ejercicio 2: El ajedrez y los granos de trigo

#include <stdio.h>
#include <math.h>
void main()
{
    double total_granos=0;
    for (int i=0; i<64; i++)
    {
        total_granos=total_granos+pow(2, i);
    }
    printf("Suponiendo que en 1 kg de trigo hay 20.000 granos, el rey le debio pagar al inventor del tablero de ajedrez:\n%0.0f kg.", total_granos/20000);
}
