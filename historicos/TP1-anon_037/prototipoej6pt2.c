

#include <stdio.h>
#include <stdlib.h>

#define SEGMENTO 5
#define CADENA_FECHA 11

int validar_fecha(char* fecha, char* patron);
int extrae(char* destino, char* origen, int inicio, int largo);
int compara_fechas(char* primera, char* segunda);


int main()
{
	char primera[10];
	char segunda[10];
	char patron[10] = "DD/MM/AAAA";
	int resultado;
	int validacionuno;
	int validaciondos;
	
	
	printf("Ingrese dos fechas en formato DD/MM/AAAA para ser comparadas\n--> ");
	scanf("%s", &primera);	
	validacionuno = validar_fecha(primera, patron);
	printf("primer fecha: %d", validacionuno);
	
	printf("--> ");
	scanf("%s", &segunda);
	validaciondos = validar_fecha(segunda, patron);
	printf("segunda fecha: %d", validaciondos);
	
	if (validacionuno == 1 && validaciondos == 1)
	{
		resultado = compara_fechas(primera, segunda);	
		printf("\nEl resultado de comparar ambas fechas es: %d", resultado);
	}
	
	else
	{
		printf("Incorrecto.");
	}
}


int validar_fecha(char* fecha, char* patron)
{
	char subcadena[SEGMENTO];
	
	
	if (fecha[10] != patron[10])
	{
		return 0;
	}
	
	else if (fecha[10] == patron[10])
	{	
		printf("a\n");
		
		if (fecha[2] != patron[2])
		{
			return 0;
		}
		
		else if (fecha[2] == patron[2])
		{
			printf("e\n");
			if (fecha[5] != patron[5])
			{
				return 0;
			}
			
			else if (fecha[5] == patron[5])
			{
				printf("i\n");
				
				extrae(subcadena, fecha, 0, 2);

				int dia = atoi(subcadena);
				if (dia > 30)
				{
					return 0;
				}
				
				else if (dia <= 30)
				{
					printf("o\n");
					
					extrae(subcadena, fecha, 3, 2);

					int mes = atoi(subcadena);
					if (mes > 12)
					{
						return 0;
					}
				}
			}			
		}
	}
	printf("u\n");
	return 1;
}


int compara_fechas(char *primera, char *segunda)
{
	char subcadena[SEGMENTO];

	
	
	extrae(subcadena, primera, 6, 4);
	int año_primera = atoi(subcadena);
	
	
	extrae(subcadena, segunda, 6, 4);
	int año_segunda = atoi(subcadena);
	

	if (año_primera < año_segunda)
	{
		return -1;
	}
	
	else if (año_primera > año_segunda)
	{
		return 1;
	}
	
	else
	{
		
		extrae(subcadena, primera, 3, 2);
		int mes_primera = atoi(subcadena);
		
		
		extrae(subcadena, segunda, 3, 2);
		int mes_segunda = atoi(subcadena);

		
		if (mes_primera < mes_segunda)
		{
			return -1;
		}
		
		else if (mes_primera > mes_segunda)
		{
			return 1;
		}
		
		else
		{
			
			extrae(subcadena, primera, 0, 2);
			int dia_primera = atoi(subcadena);
			
			
			extrae(subcadena, segunda, 0, 2);
			int dia_segunda = atoi(subcadena);


			if (dia_primera < dia_segunda)
			{
				return -1;
			}
			
			else if (dia_primera > dia_segunda)
			{
				return 1;
			}
			
			else
			{
				return 0;
			}
		}
	}
	
}


int extrae(char* destino, char* origen, int inicio, int largo)
{
    int i = 0;
    for(int contador = inicio; contador < inicio+largo; contador++)
    {
        destino[i] = origen[contador];
        i++;
    }
    destino[i] = '\0';
    return i;
}