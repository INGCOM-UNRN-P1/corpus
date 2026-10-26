/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_067
*************************/
#include <stdio.h>
#include <stdlib.h>

int compara_fechas(char *primera, char *segunda);

int main(int argc, char *argv[])
{
    char fecha1, fecha2;

    printf("Ingrese una fecha dd/mm/aa: ");
    scanf("%c", &fecha1);
    printf("Ingrese una fecha dd/mm/aa: ");
    //fflush( stdin );
    scanf("%c", &fecha2);

    printf("resultado de compara fechas :%d", compara_fechas(&fecha1, &fecha2));
    return 1;
}

int compara_fechas(char *primera, char *segunda)
{
    for(int i = 6; i>=0; i= i-3)
    {
        if(primera[i] > segunda[i])
            return 1;
        else if(primera[i] < segunda[i])
            return -1;
        else
        {
            if(primera[i+1] > segunda[i+1])
                return 1;
            else if(primera[i+1] > segunda[i+1])
                return -1;
        }
    }
    return 0;
}
