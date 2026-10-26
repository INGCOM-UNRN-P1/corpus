
#include <stdio.h>
#include <string.h>
#define DESORDENADO 0
#define ASCENDENTE 1
#define DESCENDENTE -1
#define ERROR_ARCHIVO -2
#define MAXIMO 100

int esta_ordenado(char *nombre_archivo);

int main(int argc, char *argv[])
{
    char *nombre_archivo = argv[1]; //El nombre del archivo tiene que ser lo que valga el argumento en la posicion 1.
    int retorno = 0;
    int cantidad = 0;
    
	//Veo que el puntero no sea nulo
	if(nombre_archivo == NULL)
	{
		perror("Error de puntero!");
	}
	else
	{
		retorno = esta_ordenado(nombre_archivo);
            
		if(retorno == DESORDENADO)
		{
			printf("El arreglo esta desordenado.");
		}
		else if(retorno == ASCENDENTE)
		{
			printf("El arreglo esta ordenado ascendentemente.");
		}
		else if(retorno == DESCENDENTE)
		{
			printf("El arreglo esta ordenado descendentemente.");
		}
		else
		{
			printf("ERROR!");
		}
	}

 

}




int esta_ordenado(char *nombre_archivo)
{
    FILE *archivo;
    int retorno = 0;
    int arreglo[MAXIMO];
    int cantidad = 0;//Aca guardo la cantidad de numeros que tiene el arreglo.
    int numero = 0;
    int recorre = 0;
    int contador = 0;//Para recorrer el arreglo.
    int ascendente = 0;//Esto es para guardar la cantiadad de veces que esta ordenado cada termino de forma ascendente.
    int descendente = 0 ;//Esto es para guardar la cantiadad de veces que esta ordenado cada termino de forma descendente.

    
    
    
    archivo = fopen(nombre_archivo, "r");//Abro el archivo en modo lectura.
	
	if(archivo == NULL)
	{
		perror("fopen() FALLO");
		retorno = ERROR_ARCHIVO;
	}
	else
	{
			
		fscanf(archivo,"%d", &cantidad);//guardo el primer elemento como la cantidad
			
		while((recorre < cantidad) && (recorre != EOF))//Guardo los numeros del archivo en el arreglo
		{

			fscanf(archivo, "%d", &numero);//Guardo en el arreglo los numeros
			arreglo[recorre] = numero;
		
			recorre++;
		}


		while((contador < cantidad - 1) && (contador != EOF))//Es cantidad - 1 por que el contador + 1 se pasa de rosca si no y toma un 0
		{
			
			if(arreglo[contador] <= arreglo[contador + 1])//esto compara la posicion acutal con la siguiente.
			{
				ascendente++;//Sumo de que esta ordenado ascendentemente. Si al finalizar es igual a la cantidad de elementos, esta ordenado.
					
			}
			else if(arreglo[contador] >= arreglo[contador + 1])//hace lo mismo que el anterior pero de forma descendente.
			{
				descendente++;
			}

			contador++;
			
		}
		

	}

	cantidad = cantidad - 1; //Tengo que restarle 1 por que el ultimo numero no se va a comparar con nada, entonces nunca va a dar la cantidad.
		
	if(ascendente == cantidad )//Si coincide esta ordenado ascendentemente
	{
	retorno = ASCENDENTE;
	}
	else if(descendente == cantidad)//Si coincide esta ordenado descendentemente
	{
		retorno = DESCENDENTE;
	}
	else if(retorno != ERROR_ARCHIVO)//Si no dio error de apertura, no esta ordenado
	{
		retorno = DESORDENADO;
	}
		
	fclose(archivo);//Cierro el archivo.
   
    return retorno;
    
}
