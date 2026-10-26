/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_051 de GitHub
*************************/
#include <stdio.h>
#include <string.h>
#define PRIMERA 12
#define SEGUNDA 12
int compara_fechas(char *primera, char *segunda);
int main(int argc, char *argv[])
{
	char primera[PRIMERA];
	char segunda[SEGUNDA];
	int total;
	printf("Introduzca una fecha, usando digitos, y separadas por slash xx/xx/xxxx: ");
	scanf("%s", primera);
	printf("Introduzca otra fecha, usando digitos, y separadas por slash xx/xx/xxxx: ");
	scanf("%s", segunda);
	total = compara_fechas(primera, segunda);
	return total;
	
}
int compara_fechas(char *primera, char *segunda)
{
	int j;
	int contador = -1;
	int contador_year = 0;
	int contador_mes = 0;
	char slash = '/';
	if (strlen(primera) != strlen(segunda) || strlen(primera) != 10)
	{
		printf("Ingrese dos fechas con la misma longitud de digitos en formato xx/xx/xxxx");
		return 0;
	}
	if (primera[2] != slash || primera[5] != slash)
	{
		printf("Ingrese los slash correctamente");
		return 0;
	}
	for(j=0;j<=strlen(primera);j++)
	{
		if(primera[j] == segunda[j])
		{
			contador++;
		}
	}
	if (contador == strlen(primera))
	{
		printf("0");
		return 0;
	}
	for (j=6;j<10;j++)
	{
		if(primera[j] > segunda[j])
		{
			printf("1");
			break;
		}
		if(segunda[j] > primera[j])
		{
			printf("-1");
			break;
		}
		if(primera[j] == segunda[j])
		{
			contador_year++;
		}
	}
	if (contador_year == 4)
	{
		for(j=3;j<5;j++)
		{
			if(primera[j] > segunda[j])
		{
			printf("1");
			break;
		}
		if(segunda[j] > primera[j])
		{
			printf("-1");
			break;
		}
		if(primera[j] == segunda[j])
		{
			contador_mes++;
		}
		}
	}
	if (contador_mes == 2)
	{
		for(j=0;j<3;j++)
		{
		if(primera[j] > segunda[j])
		{
			printf("1");
			break;
		}
		if(segunda[j] > primera[j])
		{
			printf("-1");
			break;
		}
		}	
	}
}