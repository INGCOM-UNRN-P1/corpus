/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@marsiocons
*************************/
#include <stdio.h>
#include <stdlib.h>

int compara_fechas(char *primera, char *segunda);
int recortar_transformar(char *cadena, int inicio, int final);

int main(int argc, char *argv[])
{
    char fecha_uno[] = "15/05/2000";
    char fecha_dos[] = "15/05/2000";
    int result;

    result = compara_fechas(fecha_uno, fecha_dos);
    printf("%d", result);
}

int compara_fechas(char *primera, char *segunda)
{
    int anio_pri;
    int mes_pri;
    int dia_pri;
    int anio_seg;
    int mes_seg;
    int dia_seg;
    int suma_primera;
    int suma_segunda;

    anio_pri = recortar_transformar(primera, 6, 9);
    mes_pri = recortar_transformar(primera, 3, 4);
    dia_pri = recortar_transformar(primera, 0,1);

    anio_seg = recortar_transformar(segunda, 6, 9);
    mes_seg = recortar_transformar(segunda, 3, 4);
    dia_seg = recortar_transformar(segunda, 0,1);

    suma_primera = anio_pri + mes_pri + dia_pri;
    suma_segunda = anio_seg + mes_seg + dia_seg;

    if(suma_primera > suma_segunda)
    {
        return 1;
    }
    else if(suma_primera < suma_segunda)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int recortar_transformar(char *cadena, int inicio, int final)
{
    int j = 0;
    int numero;
    char segmento[final-inicio+1];
    for(int i = inicio; i <= final; i++)
    {
        segmento[j] = cadena[i];
        j++;
    }
    segmento[j] = '\0';
    numero = atoi(segmento);
    return numero;
}
