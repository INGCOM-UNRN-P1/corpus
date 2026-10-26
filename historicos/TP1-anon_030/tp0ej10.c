/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>

void dia_semana(int entrada);
 
int main(int argc, char *argv[])
{
    int entrada;
    printf("Ingrese un número entre 1 y 7:\t\n");
    scanf("%d", &entrada);
    dia_semana(entrada);
}

void dia_semana(int entrada)
{
    if(entrada <= 7 && entrada >= 1)
    {
    
        switch(entrada)
        {
            case 1:
                printf("%d - lunes", entrada);
                break;
            case 2:
                printf("%d - martes", entrada);
                break;
            case 3:
                printf("%d - miércoles", entrada);
                break;
            case 4:
                printf("%d - jueves", entrada);
                break;
            case 5:
                printf("%d - viernes", entrada);
                break;
            case 6:
                printf("%d - sábado", entrada);
                break;
            case 7:
                printf("%d - domingo", entrada);
                break;
        }
    }
    else
    {
        printf("El número tiene que estar entre 1 y 7!");
    }
}