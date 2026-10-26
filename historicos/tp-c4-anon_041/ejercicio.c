

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define CADENA_SIN_TERMINADOR -1
#define NO_HAY_LUGAR_INSERTAR -2
#define SOLO_UN_ARGUMENTO -3
#define MAS_DE_DOS_ARGUMENTOS -4
#define NO_POSEE -5
#define ELECCION_INCORRECTA -6
#define SIZE 15

void muestra_argumentos(char *cadena[SIZE], int capacidad);
int largo_seguro(char cadena[], int capacidad);
int limpieza_cadenas(char cadena[], int capacidad);
int copia_cadenas(char origen[], char destino[], int capacidad);
int insercion_cadenas(char origen[], char destino[], int capacidad, int posicion);
int inversion_cadenas(char origen[], char destino[], int capacidad);
int comparacion_cadenas(char cadena[], char segunda_cadena[], int capacidad);
int caracteres_alfanumericos(char cadena[], int capacidad);
int simbolos(char cadena[], int capacidad);
char reemplazar_mayusculas(char cadena[], int capacidad);
int es_palindromo(char cadena[], int capacidad);

void muestra_argumentos(char *cadena[SIZE], int capacidad)
{
	int i;
	printf("\n");
	for (i = 0;i <= capacidad; i++)
	{
		printf("Cadena[%d] --> %s\n", i, cadena[i]);
	}
}

int largo_seguro(char cadena[], int capacidad)
{
	int i;
	int cantidad_caracteres = 0;
	
	for (i = 0;cadena[i] != '\0'; i++)
	{
		cantidad_caracteres++;
	}
	
	if (cantidad_caracteres >= capacidad)
	{
		cantidad_caracteres = CADENA_SIN_TERMINADOR;
	}
	
	return cantidad_caracteres;
}

int limpieza_cadenas(char cadena[], int capacidad)
{
	char cadena_limpia[SIZE];
	int largo_cadena;
	int largo;
	int i = 0;
	int j = 0;
	
	largo_cadena = largo_seguro(cadena, capacidad);
	
	for(i = 0;i < largo_cadena; i++)
	{
		if(cadena[i] > 47 && cadena[i] < 58)
		{
			cadena_limpia[j] = cadena[i];
			j++;
		}
		else if(cadena[i] > 64 && cadena[i] < 91)
		{
			cadena_limpia[j] = cadena[i];
			j++;
		}
		else if (cadena[i] > 96 && cadena[i] < 123)
		{
			cadena_limpia[j] = cadena[i];
			j++;
		}
	}
	
	largo = largo_seguro(cadena_limpia, capacidad);
	return largo;
}

int copia_cadenas(char origen[], char destino[], int capacidad)
{
	int i = 0;
	int largo;
	
	while(i < capacidad)
	{
		destino[i] = origen[i];
		i++;
	}
	
	largo = largo_seguro(destino, capacidad);
	
	return largo;
}

int insercion_cadenas(char origen[], char destino[], int capacidad, int posicion)
{
	char destino_final[SIZE];
	int largo_destino;
	int largo_origen;
	int largo;
	int j = 0;
	int i = 0;
	int continuacion = 0;
	
	largo_destino = largo_seguro(destino, capacidad);
	if(largo_destino < posicion)
	{
		return NO_HAY_LUGAR_INSERTAR;
	}
	
	largo_origen = largo_seguro(origen, capacidad);
	
	while(i < posicion)
	{
		destino_final[j] = destino[i];
		i++;
		j++;
		continuacion++;
	}
	
	i = 0;
	
	while(origen[i] != '\0')
	{
		destino_final[j] = origen[i];
		i++;
		j++;
	}
	
	while(i < posicion+largo_origen)
	{
		destino_final[j] = destino[continuacion];
		j++;
		continuacion++;
	}
	
	destino_final[j] = '\0';

	largo = largo_seguro(destino_final, capacidad);
	
	return largo;
}

int inversion_cadenas(char origen[], char destino[], int capacidad)
{
	int i;
	int j;
	int largo;
	int largo_origen;
	int largo_destino;
	char temporal;
	
	largo_origen = largo_seguro(origen, capacidad);
	largo_destino = largo_seguro(destino, capacidad);
	j = largo_destino-1;
	
	for(i = 0;i < largo_origen;i++)
	{
		temporal = origen[i];
		destino[j] = temporal;
		j--;
	}
	
	largo = largo_seguro(destino, capacidad);
	return largo;
}

int comparacion_cadenas(char cadena[], char segunda_cadena[], int capacidad)
{
	int i;
	char temporal_minuscula;
	char temporal_segunda_minuscula;
	int largo_cadena;
	int largo_segunda_cadena;
	largo_cadena = largo_seguro(cadena, capacidad);
	largo_segunda_cadena = largo_seguro(segunda_cadena, capacidad);
	
	for(i = 0;i < largo_cadena; i++)
	{
		if(cadena[i] > 96 && cadena[i] < 123)
		{
			temporal_minuscula = cadena[i];
			break;
		}
	}
	
	for(i = 0;i < largo_segunda_cadena; i++)
	{
		if(segunda_cadena[i] > 96 && segunda_cadena[i] < 123)
		{
			temporal_segunda_minuscula = segunda_cadena[i];
			break;
		}
	}
	
	if (temporal_minuscula < temporal_segunda_minuscula)
	{
		return -1;
	}
	else if (temporal_minuscula == temporal_segunda_minuscula)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	
}

int caracteres_alfanumericos(char cadena[], int capacidad)
{
	int i;
	int largo_cadena;
	int contador = 0;
	largo_cadena = largo_seguro(cadena, capacidad);
	
	for(i = 0;i < largo_cadena; i++)
	{
		if(cadena[i] > 47 && cadena[i] < 58)
		{
			contador++;
		}
		else if(cadena[i] > 64 && cadena[i] < 91)
		{
			contador++;
		}
		else if (cadena[i] > 96 && cadena[i] < 123)
		{
			contador++;
		}
	}
	
	return contador;
}

int simbolos(char cadena[], int capacidad)
{
	int contador;
	int largo_cadena;
	largo_cadena = largo_seguro(cadena, capacidad);
	
	contador = largo_cadena - caracteres_alfanumericos(cadena, capacidad);
	
	return contador;
}

char reemplazar_mayusculas(char cadena[], int capacidad)
{
	int i;
	
	for (i = 0;i < capacidad; i++)
	{
		if (cadena[i] > 64 && cadena[i] < 91)
		{
			cadena[i] = cadena[i] + 32;
		}
	}
	
	return cadena[SIZE];
}

int es_palindromo(char cadena[], int capacidad)
{
	int i;
	int palindromo;
	int largo_cadena; 
	largo_cadena = largo_seguro(cadena, capacidad);
	
	reemplazar_mayusculas(cadena, largo_cadena);
	
	for (i = 0 ;i < largo_cadena; i++)
	{
		if (cadena[i] == cadena[largo_cadena-1])
		{
			palindromo++;
		}
		else
		{
			return 0;
		}
		largo_cadena--;
	}
	
	largo_cadena = largo_seguro(cadena, capacidad);
	
	if(cadena[largo_cadena] != '\0')
	{
		return NO_POSEE;
	}
	
	return 1;
}

int main(int argc, char *argv[])
{
	char cadena[SIZE];
	int resultado_largo_seguro;
	int resultado_insercion_cadenas;
	int resultado_copia_cadenas;
	int resultado_limpieza_cadenas;
	int resultado_inversion_cadenas;
	int resultado_comparacion_cadenas;
	int resultado_alfanumericos;
	int resultado_simbolos;
	int resultado_palindromo;
	int eleccion;
	int posicion;
	int cual;
	int i;
	int j = 1;
	
	if(argc > 3)
	{
		return MAS_DE_DOS_ARGUMENTOS;
	}
	
	else if (argc > 2)
	{
		printf("\n-----¿Cual operación desea realizar?-----\n(ingrese un numero mayor a 10 para que termine el programa)\n0.Mostrar argumentos\n1.Largo de cadenas\n2.Insercion de cadenas\n3.Copia de cadenas\n4.Limpieza de cadenas\n5.Inversor de cadena\n6.Comparación de cadenas\n7.Contador de caracteres\n8.Contador de simbolos\n9.A minusculas y a mayusculas\n10.Palindromo\n");
		scanf("%d", &eleccion);
			
		if(eleccion == 0)
		{
			muestra_argumentos(argv, argc);
		}
	
		if (eleccion == 1)
		{
			for(i = 1;i < argc; i++)
			{
				printf("\nLargo seguro [%d]:\n", i);
				resultado_largo_seguro = largo_seguro(argv[i], SIZE);
				printf("%s - %d\n", argv[i], resultado_largo_seguro);
			}
		}
		
		if (eleccion == 2)
		{
			printf("\nIndique con 1(Si) o 0(No) si quiere insertar el primer argumento en el segundo:\n");
			scanf("%d", &cual);
			if(cual > 1)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual < 0)
			{
				return ELECCION_INCORRECTA;
			}
			
			printf("Indique la posicion en la que se va a insertar:\n");
			scanf("%d", &posicion);
			if(cual == 1)
			{
				resultado_insercion_cadenas = insercion_cadenas(argv[j], argv[j+1], SIZE, posicion);
			}
			else
			{
				resultado_insercion_cadenas = insercion_cadenas(argv[j+1], argv[j], SIZE, posicion);
			}
			printf("Largo de la inserción: %d\n", resultado_insercion_cadenas);
		}
	
		if (eleccion == 3)
		{
			printf("\nIndique con 1(Primero) o 0(Segundo) si quiere copiar el primer argumento o el segundo:\n");
			scanf("%d", &cual);
			if(cual > 1)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual < 0)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual == 1)
			{
				resultado_copia_cadenas = copia_cadenas(argv[j], cadena, SIZE);
			}
			else
			{
				resultado_copia_cadenas = copia_cadenas(argv[j+1], cadena, SIZE);
			}
			printf("Largo de la copia: %d\n", resultado_copia_cadenas);
		}
	
		if (eleccion == 4)
		{
			for(i = 1;i < argc; i++)
			{
				printf("\nLargo de la limpieza [%d]:\n", i);
				resultado_limpieza_cadenas = limpieza_cadenas(argv[i], SIZE);
				printf("%s - %d\n", argv[i], resultado_limpieza_cadenas);
			}
		}
		
		if (eleccion == 5)
		{
			printf("\nIndique con 1(Primero) o 0(Segundo) si quiere invertir el primer argumento o el segundo:\n");
			scanf("%d", &cual);
			if(cual > 1)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual < 0)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual == 1)
			{
				copia_cadenas(argv[j], cadena, SIZE);
				resultado_inversion_cadenas = inversion_cadenas(argv[j], cadena, SIZE);
			}
			else
			{
				copia_cadenas(argv[j+1], cadena, SIZE);
				resultado_inversion_cadenas = inversion_cadenas(argv[j+1], cadena, SIZE);
			}
			printf("Largo de la inversion: %d\n", resultado_inversion_cadenas);
		}
		
		if (eleccion == 6)
		{
			resultado_comparacion_cadenas = comparacion_cadenas(argv[j], argv[j+1], SIZE);
			printf("Comparacion: %d\n", resultado_comparacion_cadenas);
		}
		
		if (eleccion == 7)
		{
			printf("\nIndique con 1(Primero) o 0(Segundo) si quiere contar en el primer argumento o el segundo:\n");
			scanf("%d", &cual);
			if(cual > 1)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual < 0)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual == 1)
			{
				resultado_alfanumericos = caracteres_alfanumericos(argv[j], SIZE);

			}
			else
			{
				resultado_alfanumericos = caracteres_alfanumericos(argv[j+1], SIZE);
			}
			printf("\nCantidad de caracteres alfanumericos: %d\n", resultado_alfanumericos);
		}
		
		if (eleccion == 8)
		{
			printf("\nIndique con 1(Primero) o 0(Segundo) si quiere contar en el primer argumento o el segundo:\n");
			scanf("%d", &cual);
			if(cual > 1)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual < 0)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual == 1)
			{
				resultado_simbolos = simbolos(argv[j], SIZE);
			}
			else
			{
				resultado_simbolos = simbolos(argv[j], SIZE);
			}
			printf("Cantidad de simbolos: %d\n", resultado_simbolos);
		}
		
		if (eleccion == 9)
		{
			printf("\nIndique con 1(Primero) o 0(Segundo) si quiere pasar a minusculas el primer argumento o el segundo:\n");
			scanf("%d", &cual);
			if(cual > 1)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual < 0)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual == 1)
			{
				reemplazar_mayusculas(argv[j], SIZE);
			}
			else
			{
				reemplazar_mayusculas(argv[j+1], SIZE);
			}
		}
		
		if (eleccion == 10)
		{
			printf("\nIndique con 1(Primero) o 0(Segundo) si quiere saber el palindromo de el primer argumento o el segundo:\n");
			scanf("%d", &cual);
			if(cual > 1)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual < 0)
			{
				return ELECCION_INCORRECTA;
			}
			else if(cual == 1)
			{
				resultado_palindromo = es_palindromo(argv[j], SIZE);
			}
			else
			{
				resultado_palindromo = es_palindromo(argv[j+1], SIZE);
			}
			printf("\nPalindromo: %d\n", resultado_palindromo);
		}
	}
	
	else
	{
		return SOLO_UN_ARGUMENTO;
	}
	
	return 0;
}