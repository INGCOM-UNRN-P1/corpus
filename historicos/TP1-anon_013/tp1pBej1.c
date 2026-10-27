

//Trabajo práctico 1:
//Parte B:
//Ejercicio 1: Días de la semana

#include <stdio.h>
void main()
{
    int num;
    printf("Ingrese un numero comprendido entre el 1 y el 7.\n");
    scanf("%d", &num);
    switch (num)
    {
        case 1: printf("1 - Lunes\n"); break;
        case 2: printf("2 - Martes\n"); break;
        case 3: printf("3 - Miercoles\n"); break;
        case 4: printf("4 - Jueves\n"); break;
        case 5: printf("5 - Viernes\n"); break;
        case 6: printf("6 - Sabado\n"); break;
        case 7: printf("7 - Domingo\n"); break;
        default: printf("El numero ingresado esta fuera del rango.\n");
    }
}
