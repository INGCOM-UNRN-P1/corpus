/*************************
Ingeniería en Computación - UNRN Andina
Programación 1
@anon_037
*************************/

#include <stdio.h>
#define MAX_CADENA 21
#define CADENA_CORTA -1
#define CADENA_LIMITE 30
#define MAX_CADENA_INSERCION 20
#define CADENA_A_COPIAR 40


int largo_cadena(char *cadena, int capacidad_cadena);
int insercion(char destino[], int capacidad_destino, char insertar[], int posicion);
int copiadora(char origen[], char destino[], int capacidad_destino);


int main()
{	
	printf("------------------------------------------------------------------------------------------------\n");
	printf("**Largo de cadena**\n\n");
	
	/*** Largo de cadenas ***/
	int largo_total_cadena;
	char cadena[CADENA_LIMITE];
	int capacidad_cadena = MAX_CADENA;
	
	while (1)
	{
	    printf("Ingrese una cadena menor a %d caracteres para saber su longitud -> ", capacidad_cadena);
	    scanf(" %s", &cadena);
	
	    largo_total_cadena = largo_cadena(cadena, capacidad_cadena);
	    printf("El largo de la cadena ingresada (contando el caracter NULL) es: %d \n\n", largo_total_cadena);
		
		if (largo_total_cadena == -1)
		{
			printf("Error.\n");
		}
		break;
	}
	
	printf("------------------------------------------------------------------------------------------------\n");
	printf("**Insercion de cadena**\n\n");
	
    /*** Inserción de cadenas ***/
	char destino[MAX_CADENA_INSERCION];
	char insertar[MAX_CADENA_INSERCION];
	int capacidad_destino = MAX_CADENA;
	int posicion;
	int len_cadena_ingresada1;
	int len_cadena_ingresada2;
	
	while (1)
	{
		printf("Se insertara una cadena en otra, la longitud de la nueva cadena no debe ser mayor a %d\n", capacidad_destino);
		printf("Ingrese una cadena destino -> ");
	    scanf(" %s", &destino);
		len_cadena_ingresada1 = largo_cadena(destino, MAX_CADENA_INSERCION);

		
		if(len_cadena_ingresada1 == -1)
        {
            printf("Error.\n");
			break;
        }
		
		printf("Ingrese una cadena origen -> ");
	    scanf(" %s", &insertar);
		
		if(len_cadena_ingresada2 == -1)
        {
            printf("Error.\n");
			break;
        }
		
		printf("Ingrese una posicion menor a %d en donde se insertara-> ", len_cadena_ingresada1);
	    scanf(" %d", &posicion);
		if(posicion >= len_cadena_ingresada1)
        {
            printf("Error.\n");
			break;
        }
		
	    largo_total_cadena = insercion(destino, capacidad_destino, insertar, posicion);
	    printf("El largo total de la nueva cadena es %d \n", largo_total_cadena);
		
		if(posicion >= len_cadena_ingresada1)
        {
            printf("Error.\n");
			break;
        }
		else
		{
			if (largo_total_cadena == -1)
			{
				printf("Error.\n");
				break;
			}
			else
			{
				printf("La nueva cadena insertada es %s \n", destino);
			}
		}
		
		break;
	}
	
	printf("------------------------------------------------------------------------------------------------\n");
	printf("**Copiadora de cadena**\n\n");
	
	/*** Copiadora de cadenas ***/
	char destin[19] = "-Destino de copia-";
	char origen[CADENA_A_COPIAR];
	
	printf("Ingrese una cadena no mayor a %d para ser copiada en %s ->", capacidad_destino, destin);
	scanf(" %s", &origen);
	
	largo_total_cadena = copiadora(origen, destin, capacidad_destino);
	printf("El largo total de la cadena copiada es %d \n", largo_total_cadena);
	
	if (largo_total_cadena == -1)
	{
		printf("Error.\n");
	}
	else
	{
		printf("La nueva cadena copiada es %s \n", destin);
	}
	
	printf("------------------------------------------------------------------------------------------------\n");
}


/*** Largo de cadenas ***/

int largo_cadena(char *cadena, int capacidad_cadena)
{
	int contador = 0;	
	while (cadena[contador] != '\0')
	{
		contador++;
	}
	
	contador++;
	
	if (contador <= capacidad_cadena)
	{
		return contador;
	}
	
	else
	{
		return CADENA_CORTA;
	}
}


/*** Inserción de cadenas ***/

int insercion(char destino[], int capacidad_destino, char insertar[], int posicion)
{
    int i = 0;
	int j = 0;
	int largo_destino;
	int largo_origen;
	int largo_total;
	int pos = posicion;
	
	largo_destino = largo_cadena(destino, MAX_CADENA_INSERCION);
	largo_origen = largo_cadena(insertar, MAX_CADENA_INSERCION);
	largo_total = largo_destino + largo_origen -1;
	
	char cadena_destino_auxiliar[largo_total];
    
	if (largo_total > capacidad_destino)
	{
	    return CADENA_CORTA;
	}
	
    for (i; i < largo_total; i++)
    {
	    if (i < posicion)
		{
		    cadena_destino_auxiliar[i] = destino[i];
		}
		
		else if (i >= pos && i < pos + largo_origen -1)
		{
		    cadena_destino_auxiliar[i] = insertar[j];
			j++;
		}
		
		else
		{
		    cadena_destino_auxiliar[i] = destino[pos];
            pos++;			
	    }
    }		
	
    for (i = 0; i < largo_total; i++)
    {
        destino[i] = cadena_destino_auxiliar[i];
    }
	return largo_total;
}


/*** Copiadora de cadenas ***/

int copiadora(char origen[], char destino[], int capacidad_destino)
{
	int i = 0;
	int largo_total;
	
	while(origen[i] != '\0')
	{
		destino[i] = origen[i];
		i++;
	}
	
	if (i <= capacidad_destino)
	{
		destino[i] = '\0';
	}
	else
	{
		return CADENA_CORTA;
	}
	
	largo_total = i+1;
	return largo_total;
}