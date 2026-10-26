/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_007 de GitHub
*************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int compara_fechas(char *primera, char *segunda);
int main(int argc, char *argv[])
{
	char primera_fecha[] = "00/00/0000" ;
	char segunda_fecha[] = "00/00/0000";
	int mostrar;
	while(1)
	{
		printf("Ingresa una fecha en formato DD/MM/AAAA: ");
		fflush(stdout);
		scanf("%s", &primera_fecha);
		if (primera_fecha[2] != '/' || primera_fecha[5] != '/')
		{
			printf("Por favor separe con diagonales '/' \n");
		}
		else
		{
			if (strlen(primera_fecha) != 10)
			{
				printf("Por favor escribe la fecha en formato DD/MM/AAAA \n");				
			}
			else
			{
				printf("Ingresa otra fecha en el mismo formato: ");
				fflush(stdout);
				scanf("%s", &segunda_fecha);
				if (segunda_fecha[2] != '/' || segunda_fecha[5] != '/')
				{
					printf("Por favor separe con diagonales '/' \n");
				}
				else
				{
					if (strlen(segunda_fecha) != 10)
					{
						printf("Por favor escribe la fecha en formato DD/MM/AAAA \n");
					}
					else
					{
					break;
					}				
				}
			}	
		}
	}
	mostrar = compara_fechas(primera_fecha, segunda_fecha);
	printf("%d", mostrar);
}
int compara_fechas(char * primera, char * segunda)
{		
	char primera_a[5], primera_m[3], primera_d[3];
	char segunda_a[5], segunda_m[3], segunda_d[3];	
	int primera_int_a, primera_int_m, primera_int_d;
	int segunda_int_a, segunda_int_m, segunda_int_d;
	memcpy(primera_a, &primera[6], 4);
	primera_a[4] = '\0';
	primera_int_a = atoi(primera_a);
	memcpy(segunda_a, &segunda[6], 4);
	segunda_a[4] = '\0';
	segunda_int_a = atoi(segunda_a);
	memcpy(primera_m, &primera[3], 2);
	primera_m[2] = '\0';
	primera_int_m = atoi(primera_m);
	memcpy(segunda_m, &segunda[3], 2);
	segunda_m[2] = '\0';
	segunda_int_m = atoi(segunda_m);
	memcpy(primera_d, &primera[0], 2);
	primera_d[2] = '\0';
	primera_int_d = atoi(primera_d);
	memcpy(segunda_d, &segunda[0], 2);
	segunda_d[2] = '\0';
	segunda_int_d = atoi(segunda_d);
	if (primera_a > segunda_a)
	{
		return 1;
	}
	else
	{
		if (primera_a < segunda_a)
		{
			return -1;
		}
		else
		{
			if(primera_a == segunda_a && primera_m > segunda_m)
			{
				return 1;
			}
			else
			{
				if(primera_a == segunda_a && primera_m < segunda_m)
				{
					return -1;
				}
				else
				{
					if(primera_a == segunda_a && primera_m == segunda_m && primera_d > segunda_d)
					{
						return 1;
					}
					else
					{
						if(primera_a == segunda_a && primera_m == segunda_m && primera_d == segunda_d)
						{
							return 0;
						}
						else
						{
							return -1;
						}
					}
				}
			}
		}
	}
}