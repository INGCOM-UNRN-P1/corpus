/*************************
 * Ingenieria en Computación - UNRN Andina
 * Programación 1
 * anon_014 de GitHub
 *************************/
#include<stdio.h>

#define LIMITE_CADENA 32
#define CADENA_CORTA -1
#define LIMITE_CADENA_ALCANZADO -2
#define CADENA_EXCEDIDA -3
#define CADENA_VACIA -4
#define LIMITE_SUB_CADENAS 16

int largo_cadena(char *cadena, int capacidad_cadena)
{
    capacidad_cadena = 0;
    if (cadena[capacidad_cadena] != 0)
    {
        while (cadena[capacidad_cadena] != 0)
        {
            capacidad_cadena++;
        }
         return capacidad_cadena;

    }
    else
    {
        return CADENA_CORTA;
    }

}

int divide_cadena(char *cadena, int len_cad, char arreglo_cadenas[][LIMITE_SUB_CADENAS+1], int cantidad_cadenas, int len_subcadenas, int *posiciones)
{
    int cadena_actual=1;
    int letra_actual=0;
    int i,j;

    if (cantidad_cadenas <= 1)
    {
        for (i=0;i<len_subcadenas+1;i++)
        {
            arreglo_cadenas[0][i]=cadena[i];
        }

        if (i==len_subcadenas+2)
        {
            printf("\nERROR: Largo de subcadena maximo alcanzado.");
            return LIMITE_CADENA_ALCANZADO;
        }
    }
    else
    {
        for (i=0;i<posiciones[0] && i<=len_subcadenas+1;i++)
        {
            arreglo_cadenas[0][i]=cadena[i];
            letra_actual++;
        }
        arreglo_cadenas[0][letra_actual] = '\0';
        letra_actual=0;

        if (i==len_subcadenas+2)
        {
            printf("\nERROR: Largo de subcadena maximo alcanzado.");
            return LIMITE_CADENA_ALCANZADO;
        }

        for (i=0; i<cantidad_cadenas-1;i++)
        {
            for(j=posiciones[i]+1;j<posiciones[i+1] && j<=posiciones[i]+len_subcadenas+1;j++)
            {
                arreglo_cadenas[cadena_actual][letra_actual] = cadena[j];
                letra_actual++;
            }

            arreglo_cadenas[cadena_actual][letra_actual] = '\0';
            cadena_actual++;
            letra_actual=0;

            if (j==posiciones[i]+len_subcadenas+2)
            {
                printf("\nERROR: Largo de subcadena maximo alcanzado.");
                return LIMITE_CADENA_ALCANZADO;
            }
        }
    }


    return 0;
}

int busca_saltos(char *cadena, int len_cad, int *posiciones)
{
    int saltos=0;
    for (int i=0; i<len_cad;i++)
    {
        if (cadena[i]=='\n')
        {
            posiciones[saltos] = i;
            saltos++;
        }
    }
    return saltos;
}

int main()
{
    int cant_saltos, prueba, lineas, largo;
    char cadena[LIMITE_CADENA]="";
    int posiciones[LIMITE_CADENA];

    printf("Ingrese la cantidad de lineas que desea ingresar: ");

    scanf("%d",&lineas);

    printf("Ingrese la cadena que desea dividir ingresando la tecla ENTER como division de linea: \n");

    getchar();

    fflush(stdin);

    fgets(cadena, LIMITE_CADENA, stdin);

    for(;lineas>1;lineas--)
    {
        fflush(stdin);
        largo = largo_cadena(cadena, LIMITE_CADENA);
        fgets(cadena+largo, LIMITE_CADENA-largo, stdin);
    }
    fflush(stdin);

    cant_saltos = busca_saltos(cadena,LIMITE_CADENA,posiciones);

    char arreglo_cadenas[cant_saltos][LIMITE_SUB_CADENAS+1];

    prueba = divide_cadena(cadena,LIMITE_CADENA,arreglo_cadenas,cant_saltos,LIMITE_SUB_CADENAS,posiciones);

    if (prueba >= 0)
    {
        printf("\n------------------------------------------------------------\n");
        printf("\nCadena separada por lineas y almacenada en un arreglo de cadenas de la siguiente manera: \n\n");
        for (int i = 0; i<cant_saltos; i++)
        {
            printf("%s\n",arreglo_cadenas[i]);
        }
        printf("\n------------------------------------------------------------\n");
    }

    return 0;
}
