/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
@anon_024 de GitHub
*************************/
#define longitud 12

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compara_fechas(char *primera, char *segunda);
 
int main(int argc, char *argv[])
{

char fecha1[longitud],fecha2[longitud];

int comparacion;

printf("\ningrese una fecha : \n el formato es ##/##/####:  ");

fgets(fecha1,longitud,stdin);

printf("\ningrese una segunda fecha : ");

fgets(fecha2,longitud,stdin);

comparacion = compara_fechas(fecha1,fecha2);

switch (comparacion)
{
	
	case 1:
		printf("\n La fecha %s es posterior a la fecha %s ",fecha1,fecha2);
		
	break;
	
	case 0:
		printf("\n La fecha %s a sido introducida 2 veces",fecha1);
		
	break;
	
	case -1:
		printf("\n La fecha %s es anterior a la fecha %s ",fecha1,fecha2);
		
	break;
}

return 0;
}

int compara_fechas(char *primera, char *segunda)
{
	
int resultado,year1,year2,month1,month2,day1,day2;

char anio1[5],anio2[5],mes1[3],mes2[3],dia1[3],dia2[3];	
	
resultado = 0;
	
primera += 6;

segunda +=6;

strncpy(anio1,primera,4);

strncpy(anio2,segunda,4);

primera -= 3;

segunda -= 3;

strncpy(mes1,primera,2);

strncpy(mes2,segunda,2);

primera -= 3;

segunda -= 3;

strncpy(dia1,primera,2);

strncpy(dia2,segunda,2);

year1 = atoi(anio1);

year2 = atoi(anio2);

month1 = atoi(mes1);

month2 = atoi(mes2);

day1 = atoi(dia1);

day2 = atoi(dia2);

if (year1 > year2)
{
	
	resultado = 1;
	
}
else if (year2 > year1)
{
	
	resultado = -1;
	
}
else 
{
	
	if (month1 > month2)
	{
		
		resultado = 1;
	
	}
	else if (month2 > month1)
	{
		
		resultado = -1;
	
	}
	else
	{
		
		if (day1 > day2)
		{
			
			resultado = 1;	
			
		}
		else if (day2 > day1)
		{
			
			resultado = -1;
		
		}
		
	}
	
}

return resultado;
}


