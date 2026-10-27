

#include <stdio.h>
#include <stdlib.h>

#define SEGMENTO 5
#define CADENA_FECHA 10

int extrae(char* destino, char* origen, int inicio, int largo);
int compara_fechas(char* primera, char* segunda);


int main()
{
	char primera[10];
	char segunda[10];
	int resultado;
	

	printf("Ingrese dos fechas en formato DD/MM/AAAA para ser comparadas\n--> ");
	scanf("%s", &primera);	
	
	printf("--> ");
	scanf("%s", &segunda);
	
	resultado = compara_fechas(primera, segunda);	
	printf("\nEl resultado de comparar ambas fechas es: %d", resultado);
}


int compara_fechas(char *primera, char *segunda)
{
	char subcadena[SEGMENTO];

	
	extrae(subcadena, primera, 6, 4);
	int año_primera = atoi(subcadena);
	printf("El AAAA1 es: %d \n", año_primera);
	
	
	extrae(subcadena, segunda, 6, 4);
	int año_segunda = atoi(subcadena);
	printf("El AAAA2 es: %d \n", año_segunda);
	

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
		printf("El MM1 es: %d \n", mes_primera);
		
		
		extrae(subcadena, segunda, 3, 2);
		int mes_segunda = atoi(subcadena);
		printf("El MM2 es: %d \n", mes_segunda);

		
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
			printf("El DD1 es: %d \n", dia_primera);
			
			
			extrae(subcadena, segunda, 0, 2);
			int dia_segunda = atoi(subcadena);
			printf("El DD2 es: %d \n", dia_segunda);


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
