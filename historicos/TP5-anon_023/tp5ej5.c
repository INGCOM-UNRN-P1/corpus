/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * @anon_023
 *************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LIMITE_CADENA 100
#define CADENA_CORTA -1
#define LIMITE_CADENA_ALCANZADO -2
#define CADENA_EXCEDIDA -3
#define CADENA_VACIA -4
#define LIMITE_SUB_CADENAS 20



int divide_cadena(char *cadena, int largo_cad, char arreglo_cadenas[][LIMITE_SUB_CADENAS+1], int cantidad_cadenas, int largo_subcadenas, int *posiciones)
{
    int cadena_actual=1;
    int letra_actual=0;
    int i,j;
    
    if (cantidad_cadenas <= 1)
    {
        for (i=0;i<largo_subcadenas+1;i++)
        {
            arreglo_cadenas[0][i]=cadena[i];
        }
        
        if (i==largo_subcadenas+2)
        {
            printf("\nERROR: Largo de subcadena maximo alcanzado.");
            return LIMITE_CADENA_ALCANZADO;
        }
    }
    else
    {
        //CADENA HASTA PRIMER SALTO DE LINEA:
        for (i=0;i<posiciones[0] && i<=largo_subcadenas+1;i++)
        {
            arreglo_cadenas[0][i]=cadena[i];
            letra_actual++;
        }
        arreglo_cadenas[0][letra_actual] = '\0';
        letra_actual=0;
        
        if (i==largo_subcadenas+2)
        {
            printf("\nERROR: Largo de subcadena maximo alcanzado.");
            return LIMITE_CADENA_ALCANZADO;
        }
        //SIGUIENTES CADENAS:
        for (i=0; i<cantidad_cadenas-1;i++)
        {
            for(j=posiciones[i]+1;j<posiciones[i+1] && j<=posiciones[i]+largo_subcadenas+1;j++)
            {
                arreglo_cadenas[cadena_actual][letra_actual] = cadena[j];
                letra_actual++;
            }
            
            arreglo_cadenas[cadena_actual][letra_actual] = '\0';
            cadena_actual++;
            letra_actual=0;
            
            if (j==posiciones[i]+largo_subcadenas+2)
            {
                printf("\nERROR: Largo de subcadena maximo alcanzado.");
                return LIMITE_CADENA_ALCANZADO;
            }
        }
    }

    
    return 0;
}

int busca_saltos(char *cadena, int largo_cad, int *posiciones)
{
    int saltos=0;
    for (int i=0; i<largo_cad;i++)
    {
        if (cadena[i]=='\n')
        {
            posiciones[saltos] = i;
            saltos++;
        }
    }
    return saltos;
}

int largo_cadena(char *cadena, int capacidad_cadena)
{
	int tamaño = 0;
	while (cadena[tamaño] != 0 )
	{
		tamaño++;
	}
	if (tamaño == 0)
	{
		return CADENA_VACIA;
	}
	else if (tamaño > capacidad_cadena)
	{
		return CADENA_EXCEDIDA;
	}
	return tamaño;
}

int main()
{
    int cantidad_saltos, prueba, lineas, largo;
    char cadena[LIMITE_CADENA]="";
    int posiciones[LIMITE_CADENA];
    
    printf("Ingrese la cantidad de lineas a ingresar: ");
    scanf("%d",&lineas);
    printf("Ingrese la cadena a dividir usando enter para realizar saltos de linea: \n");
    
    getchar();
    fflush(stdin); // limpio buffers
    
    fgets(cadena, LIMITE_CADENA, stdin);
    
    for(;lineas>1;lineas--)
    {
        fflush(stdin);
        largo = largo_cadena(cadena, LIMITE_CADENA);
        fgets(cadena+largo, LIMITE_CADENA-largo, stdin);
    }
    
    fflush(stdin);// limpio buffer
    
    cantidad_saltos = busca_saltos(cadena,LIMITE_CADENA,posiciones);
    
    char arreglo_cadenas[cantidad_saltos][LIMITE_SUB_CADENAS+1];
    
    prueba = divide_cadena(cadena,LIMITE_CADENA,arreglo_cadenas,cantidad_saltos,LIMITE_SUB_CADENAS,posiciones);
    
    if (prueba >= 0)
    {
        printf("\n---------------------------------------------------------\n");
        printf("\nCadena separada por lineas y almacenada en un array de cadenas: \n\n");
        for (int i = 0; i<cantidad_saltos; i++)
        {
            printf("%s\n",arreglo_cadenas[i]);
        }
        printf("\n---------------------------------------------------------\n");
    }
    
    return 0;
   
}
