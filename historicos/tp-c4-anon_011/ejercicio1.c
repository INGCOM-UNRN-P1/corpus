
#include <stdio.h>
#define CADENA_SIN_TERMINADOR -1
#define MAX 20

int largo_cadena(char cadena[], int capacidad) 
{
	/**
 * La funcion cuenta los caracteres de la cadena sin exceder la capacidad del arreglo indicada.
 *  @param cadena es la direccion de la cadena con la que se contaran los caracteres
 *  @pre cadena es un puntero no nulo
 *  @param capacidad la capacidad es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del arreglo
 *  @pre capacidad es un valor numerico entero positivo mayor a uno
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post caracteres es la cantidad de caracteres del arreglo.
 */
	int caracteres = 0;
	while(cadena[caracteres] != '\0' && caracteres <= capacidad)
	{
		caracteres++;
	}
	if (caracteres == capacidad)
	{
		caracteres = CADENA_SIN_TERMINADOR;
	}
	return caracteres;
}	

int integrar_cadena(char cadena1[], char cadena2[], int capacidad1, int capacidad2)
{   
	/**
 * La funcion integra la segunda cadena en la primer cadena
 *  @param cadena1 es la direccion de la primer cadena la cual se le va a integrar la 2da cadena
 *  @pre cadena1 es un puntero no nulo
 *  @param cadena2 es la direccion de la segunda cadela la cual será integrada a la primer cadena
 *  @pre cadena1 es un puntero nulo
 *  @param capacidad1 la capacidad1 es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del primer arreglo
 *  @pre capacidad es un valor numerico entero positivo mayor a uno
 *  @param capacidad2 la capacidad2 es un número distinto a el largo de la cadena en si 
                    y es el tamaño en memoria del segundo arreglo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres de la cadena integrada
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post largo_cadena(cadena1, MAX) retorna la cantidad de caracteres de la cadena integrada
 */
    char cadenatemporal[capacidad1];
    int posicion;
    int i;
    int j;

    j = 0;

    printf("Ingrese la posicion donde se va a insertar la cadena: ");
    scanf("%d", &posicion);

    for(i=posicion; i<=capacidad1; i++)
    {
        cadenatemporal[j] = cadena1[i];
        j++;
    }
    j = 0;

    for(i=posicion; i<=(capacidad2+posicion); i++)
    {
        cadena1[i] = cadena2[j];
        j++;
    }
    j = 0;

    for(i=(posicion+capacidad2); i <= ((capacidad2) + (capacidad1)); i++)
    {
        cadena1[i] = cadenatemporal[j];
        j++;
    }

    return largo_cadena(cadena1, MAX);
}

int copia_cadenas(char cadena1[], char cadena2[], int capacidad1)
{
	/**
 * La funcion copia el contenido de la primer cadena en la segunda cadena
 *  @param cadena1 es la direccion de la primer cadena la cual se le va a copiar su contenido a la cadena2, dejando un '\0' unicamente
 *  @pre cadena1 es un puntero no nulo
 *  @param cadena2 es la direccion de la segunda cadena la cual pasa a tener el contenido de la primer cadena
 *  @pre cadena2 es un puntero no nulo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres de la cadena copiada
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post largo_cadena(cadena2, MAX) retorna la cantidad de caracteres de la cadena copiada
 */
	int i;

	for(i=0; i<=capacidad1; i++)
	{
		cadena2[i] = cadena1[i];
		cadena1[i] = '\0';
	}

	return largo_cadena(cadena2, MAX);
}

int limpieza_cadena(char cadena[])
{
	/**
 * La funcion "limpia" los caracteres no alfanumericos de la cadena
 *  @param cadena es la direccion de la cadena a la cual se le van a limpiar todo caracter que no sea Alfanumérico
 *  @pre cadena es un puntero no nulo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres de la cadena sin simbolos
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post largo_cadena(cadena1, MAX) retorna la cantidad de caracteres de la cadena sin simbolos
 */

	int i;
	int j = 0;

	for (int i = 0; cadena[i] != '\0'; ++i) 
    {
		while (!(cadena[i] >= 'a' && cadena[i] <= 'z') && !(cadena[i] >= 'A' && cadena[i] <= 'Z') && !(cadena[i] == '\0')) 
		{	
			for (j = i; cadena[j] != '\0'; ++j) 
			{
    			cadena[j] = cadena[j + 1];
        	}
     		cadena[j] = '\0';
    	}
	}

	return largo_cadena(cadena, MAX);
}

int inversor_cadena(char cadena[])
{
	/**
 * La funcion invierte el contenido de la cadena
 *  @param cadena es la direccion de la cadena la cual se le va a invertir los caracteres
 *  @pre cadena es un puntero no nulo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres de la cadena invertidad
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post largo_cadena(cadena1, MAX) retorna la cantidad de caracteres de la cadena invertida
 */
	int i = 0;
	int largo;
	char cadtempo;

	largo = largo_cadena(cadena, MAX);
	
	for(i=0; i < largo; i++)
	{
		cadtempo = cadena[i];
		cadena[i] = cadena[largo-1];
		cadena[largo-1] = cadtempo;
		largo--;
	}

	return largo_cadena(cadena, MAX);
}

int comparacion_cadenas(char cadena1[], char cadena2[])
{
	/**
 * La funcion compara 2 cadenas según su orden alfabetico.
 *  @param cadena1 es la direccion de la primer cadena a comparar
 *  @pre cadena1 es un puntero no nulo
 *  @param cadena2 es la direccion de la segunda cadena a comparar
 *  @pre cadena2 es un puntero no nulo
 *  @returns int en donde 1 representa que la primer cadena esta antes que la segunda
            0 representa que las cadenas tienen el mismo contenido
            y -1 representa que la primer cadena se encuentra despues que la segunda en orden alfabetico
 *  @post comparacion es la variable de tipo entero retornada
 */
	int i;
	int comparacion;
	
	i = 0;
	comparacion = 0;

	while(comparacion == 0)
	{
		if(cadena1[i] < cadena2[i])
		{
			comparacion = -1;
		} 
		else if(cadena1[i] > cadena2[i])
		{
			comparacion = 1;
		} 
	}

	return comparacion;
}

int contador_caracteres_alfanumericos(char cadena[])
{
	/**
 * La funcion cuenta los caracteres alfanumericos de la cadena
 *  @param cadena es la direccion de la cadena a contar
 *  @pre cadena es un puntero no nulo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres alfanumericos de la cadena
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post contador es una variable de tipo entero que incluye todos los valores positivos incluyendo el 0 en donde se 
 			representa la cantidad de caracteres alfanumericos
 */
	int i = 0;
	int contador = 0;
	int capacidad;

	capacidad = largo_cadena(cadena, MAX);

	for(i=0;i<capacidad;i++)
	{
		if((cadena[i] >= 'a' && cadena[i] <= 'z') || ((cadena[i]) >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= 0 && cadena[i] <= 9))
		{
			contador++;
		}
	}

	return contador;
}

int contador_caracteres_simbolos(char cadena[])
{
	/**
 * La funcion cuenta los caracteres no alfanumericos de la cadena
 *  @param cadena es la direccion de la cadena a contar
 *  @pre cadena es un puntero no nulo
 *  @returns int en donde los valores positivos incluyendo el cero representan la cantidad de caracteres no alfanumericos de la cadena
         y los valores negativos, las siguientes situaciones de error:
            CADENA_SIN_TERMINADOR cuando la cantidad de carateres sea por lo menos igual 
                                  a la capacidad indicada por el argumento
 *  @post contador es una variable de tipo entero que incluye todos los valores positivos incluyendo el 0 en donde se representa 
 			la cantidad de caracteres no alfanumericos
 */
	int i = 0;
	int contador = 0;
	int capacidad;

	capacidad = largo_cadena(cadena, MAX);

	for(i=0;i<capacidad;i++)
	{
		if(!(cadena[i] >= 'a' && cadena[i] <= 'z') && !(cadena[i] >= 'A' && cadena[i] <= 'Z') && !(cadena[i] >= 0 && cadena[i] <= 9))
		{
			contador++;
		}
	}

	return contador;
}

void mayusculas_a_minusculas(char cadena[])
{
	/**
 * La funcion modifica las letras en mayusculas a minusculas
 *  @param cadena es la direccion de la cadena a modificar
 *  @pre cadena es un puntero no nulo
 *  @returns void no retorna ningun valor
 *  @post la función no retorna ningun valor, solo modifica la cadena
 */
	int i = 0;
	int capacidad;

	capacidad = largo_cadena(cadena, MAX);
	
	for(i = 0; i < capacidad; i++)
	{
		if(cadena[i] >= 'A' && cadena[i] <= 'Z')
		{
			cadena[i] = cadena[i] + 32;
		}
	}
}

int es_palindromo(char cadena[]) 
{
	/**
 * La funcion identifica si la cadena ingresada es palindromo.
 *  @param cadena es la direccion de la cadena a identificar
 *  @pre cadena es un puntero no nulo
 *  @returns int en donde 1 representa que la cadena no es palindromo
            0 representa que la cadena es palindromo
            y -1 representa que la cadena no tiene terminador
 *  @post se retorna alguno de los valores dichos previamente
 */

	int i;
	int k;
	int capacidad;
	int boolean;
	
	capacidad = largo_cadena(cadena, MAX);
	boolean = 0;

	
	if(capacidad != -1) 
	{
		for(i=0; i < capacidad; i++) 
		{
			if(cadena[i] >= 'A' && cadena[i] <= 'Z')
			{
				cadena[i] = cadena[i] + 32;
			}
			if(cadena[capacidad - 1] >= 'A' && cadena[capacidad - 1] <= 'Z')
			{
				cadena[capacidad - 1] = cadena[capacidad - 1] + 32;
			}

			if(cadena[i] != cadena[capacidad - 1]) 
			{
				boolean = 1;
				break;
			}
			capacidad--;
		}
	}
	if(capacidad == -1)
	{
		return -1;
	}
	else if(boolean == 0) 
	{
		return 0;
	}
	else
		return 1;
}


int main(int argc, char *argv[])
{
	
	char cadena1[MAX];
	char cadena2[MAX]; 
	int i = 1;
	int result;
	int j;
	int capacidad1;
	int capacidad2;
	int capacidadcadena1;
	int capacidadcadena2;

	
	j = 0;
	capacidadcadena1 = largo_cadena(argv[1], MAX);
	capacidadcadena2 = largo_cadena(argv[2], MAX);

	for(j=0; j<=capacidadcadena1; j++)
	{
		cadena1[j] = argv[1][j];
	}
	for(j=0; j<=capacidadcadena2; j++)
	{
		cadena2[j] = argv[2][j];
	}

	
	while(i < (argc))
	{
		result = largo_cadena(argv[i], MAX);
		if(result == -1)
		{
			printf("La cadena no cuenta con terminador");
		}
		else
			printf("el largo de la cadena %s es de %d\n", argv[i], result);
	
		i++;	
	}

	i = 1;
	printf("\n");

	
	capacidad1 = largo_cadena(argv[i], MAX);
	capacidad2 = largo_cadena(argv[i+1], MAX);

	if(capacidad1 == -1 || capacidad2 == -1)
	{
		printf("No se puede integrar una cadena a otra\n");
	}
	else
		capacidad1 = integrar_cadena(argv[i], argv[i+1], capacidad1, capacidad2);
		if(result == -1)
		{
			printf("la cadena %s no tiene terminador\n", argv[1]);	
		}
		else
			printf("la cadena %s tiene %d caracteres\n", argv[1], capacidad1);
	
	printf("\n");

	
	capacidad2 = copia_cadenas(argv[1], argv[2], capacidad1);
	if(capacidad2 == -1)
	{
		printf("la cadena %s no tiene terminador\n", argv[2]);	
	}
	else
		printf("la cadena %s tiene %d caracteres\n", argv[2], capacidad2);
	
	printf("\n");
	
	
	capacidad2 = limpieza_cadena(argv[2]);
	if(capacidad2 == -1)
	{
		printf("la cadena %s no tiene terminador\n", argv[2]);		
	}
	else
		printf("la cadena %s tiene %d caracteres\n", argv[2], capacidad2);
	
	printf("\n");
	
	
	capacidad2 = inversor_cadena(argv[2]);
	if(capacidad2 == -1)
	{
		printf("la cadena %s no tiene terminador\n", argv[2]);	
	}
	else
		printf("la cadena %s tiene %d caracteres\n", argv[2], capacidad2);
	
	printf("\n");
	
	
	printf("comparando %s con %s\n", cadena1, cadena2);
	result = comparacion_cadenas(cadena1, cadena2);
	if(result == -1)
	{
		printf("la primer cadena esta antes que la segunda\n");	
	}
	else if(result == 0)
	{
		printf("las cadenas son iguales\n");
	}
	else
		printf("la segunda cadena va antes que la primera");

	printf("\n");
	
	
	result = contador_caracteres_alfanumericos(cadena1);
	printf("cantidad de caracteres alfanumericos de %s: %d\n", cadena1, result);
	printf("\n");
	
	
	result = contador_caracteres_simbolos(cadena1);
	printf("cantidad de simbolos de %s: %d\n", cadena1, result);
	printf("\n");

	
	printf("%s\n", argv[2]);
	printf("pasando mayusculas a minusculas...\n");
	mayusculas_a_minusculas(argv[2]);
	printf("%s\n", argv[2]);
	printf("\n");

	
	printf("%s ", cadena1);
	result = es_palindromo(cadena1);
	if(result == -1)
	{
		printf("la cadena no tiene terminador\n");
	}
	else if(result == 0)
	{
		printf("la cadena es palindromo\n");
	}
	else
		printf("la cadena no es palindromo");

	return 0;
}