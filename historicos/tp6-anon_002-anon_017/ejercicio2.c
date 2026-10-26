
#include <stdio.h>
#define DESORDENADO 0
#define ASCENDENTE 1
#define DESCENDENTE -1
#define ERROR_ARCHIVO -2
#define MAXIMO 100
#define CAPACIDAD_ARGUMENTO 3 //Esto es para verificar si se eligio asc o desc

int esta_ordenado(char *nombre_archivo);
void carga_archivo(char *nombre_archivo, int cantidad, int arreglo[], char *nombre_archivo_salida);
void menor_a_mayor(int capacidad, int arreglo[], char *nombre_archivo_salida);
void mayor_a_menor(int capacidad, int arreglo[], char *nombre_archivo_salida);
int verifica_parametro(char argumento_2[]);

int main(int argc, char *argv[])
{
    char *orden = argv[2];//En la posicion 2 esta en que orden se ordena
    char *nombre_archivo = argv[1]; //El nombre del archivo tiene que ser lo que valga el argumento en la posicion 1.
    char *nombre_archivo_salida = argv[3]; //posicion 3 en que archivo se guarda
    
    int arreglo[MAXIMO];//Este arreglo es el que se va a cargar en el archivo vacio
    FILE *archivo_capacidad;
    int retorno = 0;
    int cantidad = 0;
    int retorno_parametro =0;
    
	
	if(argc < 3)
	{
		printf("Error! Faltan argumentos!.");
	}
	else
	{
		//Verifico que los punteros sean validos
		if(orden == NULL)
		{
			perror("Error de puntero!");
		}
		else if(nombre_archivo == NULL)
		{
			perror("Error de puntero!");
		}
		else if(nombre_archivo_salida == NULL)
		{
			perror("Error de puntero!");
		}
		else
		{
			//Aca guardo la capacidad del archivo, que es el primer termino.
			archivo_capacidad = fopen(nombre_archivo,"r");
			if(archivo_capacidad == NULL)
			{
				perror("fopen() FALLO");
			}
			else
			{
				fscanf(archivo_capacidad, "%d", &cantidad);
				fclose(archivo_capacidad);
				//Cierro el archivo
			

				if(cantidad > MAXIMO)//Si tiene muchos numeros a imprimir, no puede.
				{
					printf("Demasiados numeros!");
					
				}
				else
				{
					carga_archivo(nombre_archivo, cantidad, arreglo, nombre_archivo_salida);
			  
					retorno = esta_ordenado(nombre_archivo);
					
							
					if(retorno == DESORDENADO)
					{
						
						//Llamar a que ordene
						retorno_parametro = verifica_parametro(orden);
						 
						if(retorno_parametro == ASCENDENTE)
						{
							menor_a_mayor(cantidad, arreglo, nombre_archivo_salida);
						}
						else if(retorno_parametro == DESCENDENTE)
						{
							mayor_a_menor(cantidad, arreglo, nombre_archivo_salida);
						}
						else
						{
							printf("Argumento no valido");
						}

						
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
			
		} 
	}
	

	
}




int verifica_parametro(char argumento_2[])
{
    int contador = 0;
    char cadena_compara_asc[] = "asc";
    char cadena_compara_des[] = "des";
    int contador_ascendente = 0;
    int contador_descendente = 0;
    int retorno = 0;
    
    while (contador < CAPACIDAD_ARGUMENTO)
    {
        if(argumento_2[contador] == cadena_compara_asc[contador])
        {
            contador_ascendente++;
        }
        else if(argumento_2[contador] == cadena_compara_des[contador])
        {
            contador_descendente++;
        }
        contador++;
    }
    
    if(contador_ascendente == 3)
    {
        retorno = ASCENDENTE;
    }
    else if (contador_descendente == 3)
    {
        retorno = DESCENDENTE;
    }
    
    
    return retorno;
   
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
   
    if(archivo == NULL)//Si da NULL, no lo puede abrir.
    {
        perror("fopen() ERROR");
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
    
    cantidad = cantidad - 1; //Tengo que restarle 1 por que el ultimo numero no se va a comparar con nada, entonces nunca va a dar la cantidad en si.
    
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



void carga_archivo(char *nombre_archivo, int cantidad, int arreglo[], char *nombre_archivo_salida)
{
    FILE *archivo;
    FILE *archivo_salida;
    int contador = 0;
    
    archivo = fopen(nombre_archivo,"r");//abro el archivo en modo lectura.
    archivo_salida = fopen(nombre_archivo_salida, "w+");//W+ para crearlo si no exisite o reemplazarlo si existe.
	
	if((archivo == NULL )|| (archivo_capacidad == NULL))
	{
		perror("fopen() FALLO");
	}
	else
	{
		fscanf(archivo,"%d",&cantidad);//Guardo la capacidad.
		fprintf(archivo_salida,"%d",cantidad);//Esto hace que el primer elemento sea la cantidad de numeros que va a tener el archivo.
		
		
		while(contador < cantidad )
		{
			
			fscanf(archivo,"%d",&arreglo[contador]);
			
			fprintf(archivo_salida,"\n");//imprimo un salto de linea en el archivo.
			fprintf(archivo_salida,"%d",arreglo[contador]);//Cargo el valor en el archivo.
			
			contador++;
		}
		
		fclose(archivo);//Cierro el archivo
		fclose(archivo_salida);
	}
  
    
}




//MENOR
void menor_a_mayor(int capacidad, int arreglo[], char *nombre_archivo_salida)
{ 
    FILE *archivo_salida;
    
    int contador = 0 ;//recorre el arreglo, empieza en 1 para no contar el primer termino
    int posicion_min = 0;//Aca voy a guardar la posicon del valor minimo
    int recorre= 0;//recorre el arreglo para comparar
    int valor_parcial = 0;//Aca guardo el valor que va a ser reemplazado, para despues devolverlo al arreglo.
    
    while(contador < capacidad)//recorre el arreglo
    {
        posicion_min = arreglo[contador];//Guardo el primer elemento como posicion minima
        
        for(recorre = contador + 1; recorre < capacidad; recorre++)//Esto va recorriendo el resto del arreglo sin contar la posicion actual del valor minimo
        {
            if(posicion_min > arreglo[recorre])//Si encuentra un valor menor a la posicion minima, los intercambia
            {
                posicion_min = arreglo[recorre];//Guardo el nuevo valor como posicion minima
                valor_parcial = arreglo[contador];//Guardo el valor por el que se va a intercambiar
                arreglo[contador] = posicion_min;//Guardo la posicion minima en donde se reemplaza
                arreglo[recorre] = valor_parcial;//Guardo el valor reemplazado en donde saco el minimo.
                
                
            }
        }       
    }
    
    
    //Esto copia el arreglo ordenado en el archivo.
    archivo_salida = fopen(nombre_archivo_salida, "w+");//Abro el archivo en modo lectura.
	
	if(archivo_salida == NULL)
	{
		perror("fopen() ERROR");
	}
	else
	{
	    fprintf(archivo_salida,"%d",capacidad);//Guardo la capacidad como primer termino
    
		//imprimo el arreglo ordenado en el archivo.
		for(contador = 0; contador < capacidad; contador++)
		{
			fprintf(archivo_salida, "\n");//Guardo un salto de linea para seguir copiando los valores debajo del numero anterior.
			fprintf(archivo_salida,"%d",arreglo[contador]);//imprimo el numero ordenado en el archivo.

		}
		
		fclose(archivo_salida);//Cierro el archivo
		
	}
	

}




void mayor_a_menor(int capacidad, int arreglo[], char *nombre_archivo_salida)
{
        
    FILE *archivo_salida;
    
    int contador = 0 ;//recorre el arreglo, empieza en 1 para no contar el primer termino 
    int posicion_max = 0;//Aca voy a guardar la posicon del valor maxmimo
    int recorre= 0;//recorre el arreglo para comparar
    int valor_parcial = 0;//Aca guardo el valor que va a ser reemplazado, para despues devolverlo al arreglo.
    
    while(contador < capacidad)//recorre el arreglo
    {
        posicion_max = arreglo[contador];//Guardo el primer elemento como posicion maxima
        
        for(recorre = contador + 1; recorre < capacidad; recorre++)//Esto va recorriendo el resto del arreglo sin contar la posicion actual del valor minimo
        {
            if(posicion_max > arreglo[recorre])//Si encuentra un valor mayor a la posicion maxima, los intercambia
            {
                posicion_max = arreglo[recorre];//Guardo el nuevo valor como posicion maxima
                valor_parcial = arreglo[contador];//Guardo el valor por el que se va a intercambiar
                arreglo[contador] = posicion_max;//Guardo la posicion maxima en donde se reemplaza
                arreglo[recorre] = valor_parcial;//Guardo el valor reemplazado en donde saco el maximo.
            }
        }  
        contador++;         
    }
    
    
    //Esto copia el arreglo ordenado en el archivo.
    archivo_salida = fopen(nombre_archivo_salida, "w+");//Abro el archivo en modo lectura y escritura con w+ para reemplazarlo.
	
	if(archivo_salida == NULL)
	{
		perror("fopen() ERROR");
	}
	else
	{
		fprintf(archivo_salida,"%d",capacidad);//Guardo la capacidad como primer termino
		
		//imprimo el arreglo ordenado en el archivo.
		for(contador = 0; contador < capacidad; contador++)
		{
			fprintf(archivo_salida, "\n");//Guardo un salto de linea para seguir copiando los valores debajo del numero anterior.
			fprintf(archivo_salida,"%d",arreglo[contador]);//imprimo el numero ordenado en el archivo.

		}
		
		fclose(archivo_salida);//Cierro el archivo
		
	}

    
}
