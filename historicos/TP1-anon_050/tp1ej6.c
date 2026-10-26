/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_050
*************************/

#include <stdio.h>

int comparar_fechas(int lhs, int rhs)
{
    if (lhs < rhs)
        return -1;
    else if (rhs < lhs)
        return 1;
    else
        return 0;
}

int leer_fecha()
{
    int dia = 0;
    int mes = 0;
    int año = 0;
    if (scanf("%02d/%02d/%04d", &dia, &mes, &año) != 3)
    {
        printf("Fecha inválida.\n");
        exit(1);
    }
    // En decimal: AAAAMMDD
    return año * 10000 + mes * 100 + dia;
}

int main()
{
    printf("Ingrese una fecha: ");
    const int fecha_uno = leer_fecha();

    printf("Ingrese una fecha: ");
    const int fecha_dos = leer_fecha();

    printf("Resultado: %d\n", comparar_fechas(fecha_uno, fecha_dos));
    return 0;
}