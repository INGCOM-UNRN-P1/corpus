
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXIMO 10000000 


void generador_aleatorio(char *nombre_archivo, int cantidad, int minimo, int maximo);
void imprime_en_archivo(char *nombre_archivo, int numero);

int main(int argc, char *argv[])
{
    char *nombre_archivo = argv[1];//Guardo el nombre del archivo
    char *cantidad_numeros = argv[2];//Guarda la cantidad de numeros que va a tener el archivo
    char *valor_minimo = argv[3];//Guarda desde que numero puede generar
    char *valor_maximo = argv[4];//Guarda hasta que numero puede generar
    
    int cantidad = 0;
    int minimo = 0;
    int maximo = 0;
    


	
	if(argc < 4)
	{
		printf("Error! Falta de argumentos.");
	}
	else
	{
		//verifico que los punteros sean validos
		//menos el nombre del arhivo, por que si no existe, lo crea.
		if(cantidad_numeros == NULL)
		{
			perror("Error de puntero!");
		}
		else if(valor_minimo == NULL)
		{
			perror("Error de puntero!");
		}
		else if(valor_maximo == NULL)
		{
			perror("Error de puntero!");
		}
		else
		{
			//Guardo los numeros de los parametros como enteros.
			cantidad =  atoi(cantidad_numeros);
			minimo =  atoi(valor_minimo);
			maximo =  atoi(valor_maximo);
			
			if(cantidad > MAXIMO)
			{
				
				printf("Error! demasiados numeros");
				
			}
			else
			{
				//Llamo a la funcion que genera los numeros en el archivo.
				generador_aleatorio(nombre_archivo, cantidad, minimo, maximo);
			}
				
		}
	}
	
		
 
}  


/**
 * La funcion genera una cantidad de numeros aleatorios entre 2 numeros diferentes.
 *  @param nombre_archivo es un puntero que tiene el nombre del archivo
 *  @pre tiene que ser un puntero valido.
 *  @param cantidad Es la cantidad de numeros que se van a generar.
 *  @pre es un numero entero
 *  @param minimo es el numero minimo que se va a generar.
 *  @pre tiene que ser un numero entero
 *  @param maximo es el valor maximo que se puede generar
 *  @pre tiene que ser un numero entero distinto al minimo.
 *  @post se espera que se cargue un archivo con numeros enteros.
 */

void generador_aleatorio(char *nombre_archivo, int cantidad, int minimo, int maximo)
{
    FILE *archivo;
    long long int contador = 0;
    int numero_random;//Aca se guarda el numero random
    int rango = maximo - minimo;//Esto es por que hay que ponerle un rango al rand(), si no, tiraba cualquier numero
    
    
    srand(time(NULL));    // La inicialización, debiera ser llamado una sola vez.
    
    archivo = fopen(nombre_archivo, "w+");//Si no existe el archivo, lo crea
	
	if(archivo == NULL)
	{
		perror("fopen() FALLO");
	}
	else
	{
		while(contador < cantidad)//cantidad es la cantidad de numeros que se van a generar/imprimir
		{
		   numero_random = rand() % rango + minimo;   // Devuelve un numero aleatorio entre min y max
		   imprime_en_archivo(nombre_archivo, numero_random);//Llama a que se imprima el nuemero aleatorio en el archivo.
		   contador++;

		}
		
		fclose(archivo);//Cierro el archivo.

	}
    
    
}


/**
 * Esta funcion carga un numero en un archivo
 * @param nombre_archivo es un puntero que tiene el nombre del archivo
 * @pre: tiene que ser un puntero valido.
 * @param numero es el numero que se va a imprimir.
 * @pre: tiene que ser un numero entero.
 *@post: Se carga un archivo con numeros.
*/

void imprime_en_archivo(char *nombre_archivo, int numero)
{
    FILE *archivo;
    int contador = 0;
    
    archivo = fopen(nombre_archivo, "a+");//a+ para leerlo y escribirlo al final.
	if (archivo == NULL)
	{
		
		perror("fopen() FALLO");
		
	}
	else
	{

		fprintf(archivo, "%d",numero);//imprimo el valor en el archivo
		fprintf(archivo,"\n");//Imprimo un salto de linea en el archivo
		fclose(archivo);//Cierro el archivo
		
	}

    
}