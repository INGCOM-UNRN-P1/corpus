/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_048
*************************/

#include <stdio.h>
#define LARGO 20

int compara_fechas(char *fecha1, char *fecha2);
int devolver_dia(char *cadena);
int devolver_mes(char *cadena);
int devolver_anio(char *cadena);


int main(int argc, char *argv[])
{	
	char fecha1[LARGO], fecha2[LARGO], resultado;
	
	printf("Digite dia/mes/anio con este formato incluyendo las '/': ");
	fgets(fecha1, LARGO, stdin);
	
	printf("Digite dia/mes/anio con este formato incluyendo las '/': ");
	fgets(fecha2, LARGO, stdin);
	
	resultado = compara_fechas(fecha1, fecha2);
	printf("%d", resultado);
	
	return 0;
}


int compara_fechas(char *fecha1, char *fecha2)
{
	int dia_fecha1  =  0,
	    dia_fecha2  =  0,
		mes_fecha1  =  0,
		mes_fecha2  =  0,
		anio_fecha1 =  0,
		anio_fecha2 =  0;
		
		dia_fecha1  =  devolver_dia(fecha1);
	    dia_fecha2  =  devolver_dia(fecha2);
		mes_fecha1  =  devolver_mes(fecha1);
		mes_fecha2  =  devolver_mes(fecha2);
		anio_fecha1 =  devolver_anio(fecha1);
		anio_fecha2 =  devolver_anio(fecha2);

	if(anio_fecha1 < anio_fecha2)
    {
    return -1;
    }
    else if(anio_fecha1 > anio_fecha2)
    {
    return 1;
    }
    else if(mes_fecha1 < mes_fecha2)
    {
    return -1;
    }
    else if(mes_fecha1 > mes_fecha2)
    {
    return 1;
    }
    else if(dia_fecha1 < dia_fecha2)
    {
    return -1;
    }
    else if(dia_fecha1 < dia_fecha2)
    {
    return 1;
    }
    else 
    {
    return 0;
    } 
}

    
int devolver_dia(char *cadena)
{	
	int i, dia;
	dia = 0;
	    
	for(i = 0; i <= LARGO; i ++)
	{	    
		if(i == 0)
		{
			switch(cadena[i])
			{
				case '0':
					dia = dia + 0;
					break;
				case '1':
					dia = dia + 10;
					break;
				case '2':
					dia = dia + 20;
					break;
				case '3':
					dia = dia + 30;
					break;
				default:
					printf("Formato Incorrecto");
	    	}
	    }
		if(i == 1)
		{
			switch(cadena[i])
			{
				case '0':
					dia = dia + 0;
					break;
				case '1':
					dia = dia + 1;
					break;
				case '2':
					dia = dia + 2;
					break;
				case '3':
					dia = dia + 3;
					break;
				case '4':
					dia = dia + 4;
					break;
				case '5':
					dia = dia + 5;
					break;
				case '6':
					dia = dia + 6;
					break;
				case '7':
					dia = dia + 7;
					break;
				case '8':
					dia = dia + 8;
					break;
				case '9':
					dia = dia + 9;
					break;
				default:
					printf("Formato Incorrecto");				
			}
		}
		else	
		{
			continue;
		}
	return dia;
	}
}
int devolver_mes(char *cadena)
{	
	int i, mes;
	mes = 0;
	
	for(i = 0; i <= LARGO; i ++)
	{	
		if(i == 3)
			{
				switch(cadena[i])
				{
					case '0':
						mes = mes + 0;
						break;
					case '1':
						mes = mes + 10;
						break;
					default:
					printf("Formato Incorrecto");	
				}
			}
			if(i == 4)
			{
				switch(cadena[i])
				{
					case '0':
						mes = mes + 0;
						break;
					case '1':
						mes = mes + 1;
						break;
					case '2':
						mes = mes + 2;
						break;
					case '3':
						mes = mes + 3;
						break;
					case '4':
						mes = mes + 4;
						break;
					case '5':
						mes = mes + 5;
						break;
					case '6':
						mes = mes + 6;
						break;
					case '7':
						mes = mes + 7;
						break;
					case '8':
						mes = mes + 8;
						break;
					case '9':
						mes = mes + 9;
						break;
					default:
					printf("Formato Incorrecto");
				}
			}
			else	
			{
				continue;
			}
	}
	return mes;
	
	
}
int devolver_anio(char *cadena)
{	
	int i, anio;
	anio = 0;
	
	for(i = 0; i <= LARGO; i ++)
	{	
		if(i == 6)
			{
				switch(cadena[i])
				{
					case '0':
						anio = anio + 0;
						break;
					case '1':
						anio = anio + 1000;
						break;
					case '2':
						anio = anio + 2000;
						break;
					case '3':
						anio = anio + 3000;
						break;
					case '4':
						anio = anio + 4000;
						break;
					case '5':
						anio = anio + 5000;
						break;
					case '6':
						anio = anio + 6000;
						break;
					case '7':
						anio = anio + 7000;
						break;
					case '8':
						anio = anio + 8000;
						break;
					case '9':
						anio = anio + 9000;
						break;
					default:
					printf("Formato Incorrecto");	
				}
			}
			if(i == 7)
			{
				switch(cadena[i])
				{
					case '0':
						anio = anio + 0;
						break;
					case '1':
						anio = anio + 100;
						break;
					case '2':
						anio = anio + 200;
						break;
					case '3':
						anio = anio + 300;
						break;
					case '4':
						anio = anio + 400;
						break;
					case '5':
						anio = anio + 500;
						break;
					case '6':
						anio = anio + 600;
						break;
					case '7':
						anio = anio + 700;
						break;
					case '8':
						anio = anio + 800;
						break;
					case '9':
						anio = anio + 900;
						break;
					default:
					printf("Formato Incorrecto");	
				}
			}
			if(i == 8)
			{
				switch(cadena[i])
				{
					case '0':
						anio = anio + 0;
						break;
					case '1':
						anio = anio + 10;
						break;
					case '2':
						anio = anio + 20;
						break;
					case '3':
						anio = anio + 30;
						break;
					case '4':
						anio = anio + 40;
						break;
					case '5':
						anio = anio + 50;
						break;
					case '6':
						anio = anio + 60;
						break;
					case '7':
						anio = anio + 70;
						break;
					case '8':
						anio = anio + 80;
						break;
					case '9':
						anio = anio + 90;
						break;
					default:
					printf("Formato Incorrecto");	
				}
			}
			if(i == 9)
			{
				switch(cadena[i])
				{
					case '0':
						anio = anio + 0;
						break;
					case '1':
						anio = anio + 1;
						break;
					case '2':
						anio = anio + 2;
						break;
					case '3':
						anio = anio + 3;
						break;
					case '4':
						anio = anio + 4;
						break;
					case '5':
						anio = anio + 5;
						break;
					case '6':
						anio = anio + 6;
						break;
					case '7':
						anio = anio + 7;
						break;
					case '8':
						anio = anio + 8;
						break;
					case '9':
						anio = anio + 9;
						break;
					default:
					printf("Formato Incorrecto");	
				}
			}
			else	
			{
				continue;
			}
	}
	return anio;
}
