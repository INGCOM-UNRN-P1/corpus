/*************************
Ingenieria en Computación - UNRN Andina
Programación 1
anon_006 - Andrés Bocchigliere - elmaildeandresbochi@gmail.com
*************************/



#include <stdio.h>
#include <string.h>

#define LARGOCADENA 12

int ComparaFechas(char *primera, char *segunda);  

int main()
{
    char primeraFecha[LARGOCADENA];
    char segundaFecha[LARGOCADENA];
	int resultado;
	
    printf("\nIngrese una primer fecha para comparar con el siguiente formato DD/MM/ANIO ");
    scanf("%s", primeraFecha);
	
    printf("\nIngrese una segunda fecha para comparar con el siguiente formato DD/MM/ANIO ");
    scanf("%s", segundaFecha);
	
	printf("\n-1 = La primer fecha es anterior a la segunda");
	printf("\n0 = Las fechas son iguales");
	printf("\n1 = La primer fecha es posterior a la segunda");
	
	printf("\n");
	printf("El resultado de comparar las fechas es: ");
	
    resultado = ComparaFechas(primeraFecha, segundaFecha);
	
	
}

int ComparaFechas(char *primera, char *segunda)
{
    int contador = -1;
    int contadorAnio = 0;
    int contadorMes = 0;
    char barra = '/';
	int i;
	
    if (strlen(primera) != strlen(segunda) || strlen(primera) != 10)
    {
		printf("\n");
        printf("\nEl formato inresado no es el correcto! EJ: DD/MM/ANIO");
        return 0;
    }
    if (primera[2] != barra || primera[5] != barra || segunda[2] != barra || segunda[5] != barra)
    {
		printf("\n");
        printf("\nIngrese las barras separadoras de fechas correctamente. EJ: DD/MM/ANIO");
        return 0;
    }
	
    for(i=0; i<=strlen(primera); i++)
    {
        if(primera[i] == segunda[i])
        {
            contador++;
        }
    }
    if (contador == strlen(primera))
    {
        printf("\n0");
        return 0; 
    }
	
    for (i=6; i<10; i++) 
    {
        if(primera[i] > segunda[i])
        {
            printf("\n1");
            break;
        }
        if(segunda[i] > primera[i])
        {
            printf("\n-1");
            break;
        }
        if(primera[i] == segunda[i])
        {
            contadorAnio++;
        }
    }
	
    if (contadorAnio == 4) 
    {
        for(i=3; i<5; i++)
        {
            if(primera[i] > segunda[i])
        {
            printf("\n1");
            break;
        }
        if(segunda[i] > primera[i])
        {
            printf("\n-1");
            break;
        }
        if(primera[i] == segunda[i])
        {
            contadorMes++;
        }
        }
    }
	
    if (contadorMes == 2) 
    {
        for(i=0; i<3; i++)
        {
			if(primera[i] > segunda[i])
			{
				printf("\n1");
				break;
			}
			if(segunda[i] > primera[i])
			{
				printf("\n-1");
				break;
			}
        }    
    }
}