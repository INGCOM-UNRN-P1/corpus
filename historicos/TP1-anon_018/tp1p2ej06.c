/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_018
*************************/

#include <stdio.h>
#include <stdlib.h>

#define FECHA 9
#define SEGM 3

int compara_fechas(); 

int main(int argc, char *argv[])
{
	char fecha1[FECHA], fecha2[FECHA];
	int comparador;
	printf("El siguiente programa comparara dos fechas ingresadas\n");
	printf("ingrese dos fechas en el formato DD/MM/AA\n");
	printf("El programa respondera: \n -1 se la primera es anterior a la segunda");
	printf("\n  0 si sin iguales\n  1 si la primer fecha es posterior\n");
	printf("\nIngrese la primer fecha: ");
	scanf("%s", &fecha1);
	printf("\nIngrese la segunda fecha: ");
	scanf("%s", &fecha2);
	comparador = compara_fechas(fecha1, fecha2, comparador);
	printf("%d\n", comparador);
	return 0;
}
int compara_fechas(char fecha1[FECHA], char fecha2[FECHA], int comp)
{
	char dia1[SEGM], dia2[SEGM], mes1[SEGM];
	char mes2[SEGM], anio1[SEGM], anio2[SEGM];
	int dia1int, dia2int, mes1int;
	int mes2int, anio1int, anio2int;
	dia1[0] = fecha1[0];
	dia1[1] = fecha1[1];
	dia1int = atoi(dia1);
	mes1[0] = fecha1[3];
	mes1[1] = fecha1[4];
	mes1int = atoi(mes1);
	anio1[0] = fecha1[6];
	anio1[1] = fecha1[7];
	anio1int = atoi(anio1);
	dia2[0] = fecha2[0];
	dia2[1] = fecha2[1];
	dia2int = atoi(dia2);
	mes2[0] = fecha2[3];
	mes2[1] = fecha2[4];
	mes2int = atoi(mes2);
	anio2[0] = fecha2[6];
	anio2[1] = fecha2[7];
	anio2int = atoi(anio2);	
	if (anio1int < anio2int)
	{
		comp = -1;
		return comp;
	}
	if (anio1int > anio2int)
	{
		comp = 1;
		return comp;
	}
	else
	{
		if (mes1int < mes2int)
		{
		comp = -1;
		return comp;
		}
		if (mes1int > mes2int)
		{
		comp = 1;
		return comp;
		}
		else
		{
			if (dia1int < dia2int)
			{
				comp = -1;
				return comp;
			}
			if (dia1int > dia2int)
			{
				comp = 1;
				return comp;
			}
			comp = 0;
			return comp;
		}
	}		
}