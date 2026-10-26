

#include <stdio.h>

#define CADENA_SIN_TERMINADOR -1
#define MAXIMO 200

int largo_seguro(char cadena[], int capacidad);

int main(int argc, char *argv[])
{
	int i = 1;
	int largo = 0;
	char cadena[100];
	int capacidad = MAXIMO;
	
	for (;i<argc;argc++)
	{
		largo = largo_seguro(argv[i],MAXIMO);
		if(largo != -1)
		{			
			printf("La cadena tiene un largo de: %d; \n", largo);
			i++;
		}
		else
		{       
			printf("%d", CADENA_SIN_TERMINADOR);
		}
	}
}

/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es un puntero no nulo
 *  @param capacidad la capacidad es un número distinto al largo de la cadena en si y es el tamaño en memoria del arreglo
 *  @pre es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post cantidad de caracteres de cada cadena
 */
int largo_seguro(char cadena[], int capacidad)
{
	int caracteres = 0;
	
	while ((caracteres <= capacidad) && (cadena[caracteres] !='\0'))
	{
		caracteres++;
	}
	if (caracteres==0 )
	{
		caracteres = CADENA_SIN_TERMINADOR;
	}
	return caracteres;
}

//int insercion_cadena(