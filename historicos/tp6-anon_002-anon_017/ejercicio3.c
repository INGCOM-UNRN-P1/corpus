
#include <stdio.h>
#include <stdlib.h>
#define MAXIMO 100

void generador_lineal(char *nombre_archivo, int cantidad, int punto_partida, int aumenta);
void imprime_en_archivo(char *nombre_archivo, int aumenta);

int main(int argc, char *argv[])
{
    char *nombre_archivo = argv[1];//Guardo el nombre del archivo
    char *cantidad_numeros = argv[2];//Guarda la cantidad de numeros que va a tener el archivo
    char *punto_partida = argv[3];//Desde que numero empieza
    char *aumento = argv[4];//Guarda el valor de cuanto es el aumento.
    
    int cantidad = 0;
    int partida = 0;
    int aumenta = 0;
    

	
	if(argc < 4)
	{
		printf("Error! falta de argumentos!");
	}
	else
	{
		//verifico que los punteros sean validos
		//menos el nombre del archivo, por que se no existe se crea.
		if(cantidad_numeros == NULL)
		{
			perror("Error de puntero!");
		}
		else if(punto_partida == NULL)
		{
			perror("Error de puntero!");
		}
		else if(aumento == NULL)
		{
			perror("Error de puntero!");
		}
		else
		{
			//Guardo los numeros de los parametros como enteros.
			cantidad =  atoi(cantidad_numeros);
			partida =  atoi(punto_partida);
			aumenta =  atoi(aumento);
			
			
			
			if(cantidad > MAXIMO)
			{
				printf("Error! demasiados numeros");
			}
			else
			{
				//Llamo a la funcion que genera los numeros en el archivo.
				generador_lineal(nombre_archivo, cantidad, partida, aumenta);
			}
		}
		
	}


	

    
}



void generador_lineal(char *nombre_archivo, int cantidad, int punto_partida, int aumenta)
{
    FILE *archivo;
    int contador = 0;
    int imprime = punto_partida;//Empieza a imprimir desde el punto de partida
    
    archivo = fopen(nombre_archivo, "w+");//W+ para leerlo y crearlo si no existe, tambien si existe lo sobreescribe.
	
	if(archivo == NULL)
	{
		perror("fopen() ERROR:");
	}
	else
	{
	    while(contador < cantidad)
		{
			imprime_en_archivo(nombre_archivo, imprime);//Llama a que imprima en el archivo.
			imprime = imprime + aumenta;//aumento el valor que se va a imprimir dependiendo de cuanto valga aumento.
			contador++;//Esto es para que llegue al tope de cuantos numeros se quieran imprimir.
		}
		
		fclose(archivo);//Cierro el archivo
	}
    

}




void imprime_en_archivo(char *nombre_archivo, int aumenta)
{
    FILE *archivo;
    int contador = 0;
    
    archivo = fopen(nombre_archivo, "a+");//a+ para leerlo y escribirlo al final.
	if(archivo == NULL)
	{
		perror("fopen() ERROR");
	}
	else
	{
		fprintf(archivo, "%d",aumenta);//imprimo el valor en el archivo
		fprintf(archivo,"\n");//Imprimo un salto de linea en el archivo
		fclose(archivo);//Cierro el archivo.
	}
   
}