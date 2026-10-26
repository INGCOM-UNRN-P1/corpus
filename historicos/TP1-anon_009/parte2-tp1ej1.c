/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
minombredeusuario de GitHub: anon_009
*************************/
#include <stdio.h>
 
int main(int argc, char *argv[])
{
    int num;// almacena el numero del usuario

    while(num < 1 || num > 7)//chequea que el numero del usuario este entre 1 y 7 inclusive
    {
        printf("Ingresar un numero entre 1 y 7: ");
        scanf("%d", &num);
    }

    switch (num)//dependiendo del numero ingresado por el usuario imprime el día correspondiente
    {
    case 1:
        printf("1 - lunes\n");
        break;
    case 2: 
        printf("2 - martes\n");
        break;
    case 3:
        printf("3 - miércoles\n");
        break;
    case 4:
        printf("4 - jueves\n");
        break;
    case 5: 
        printf("5 - viernes\n");
        break;
    case 6: 
        printf("6 - sabado\n");
        break;    
    case 7: 
        printf("7 - domingo\n");
        break;
    };

    return 0;
}