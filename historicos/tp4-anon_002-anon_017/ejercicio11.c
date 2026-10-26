
#include <stdio.h>
#define MAXIMO 10
#define MAXIMO_DOBLE (MAXIMO * 2)
#define ERROR -1
#define ERROR_CARGA -2

int invertir(int arreglo[], int tamaño);
int cargar_arreglo(int capacidad, int arreglo[]);
void muestra_arreglo(int capacidad, int arreglo[]);


//pre: Se necesita un arreglo valido y un numero entero mayor a 1 para la capacidad
//post: Se imprime el arreglo invertido.
int main()
{
	int arreglo[MAXIMO];
	int capacidad = 0;
	
	printf("Ingrese la capacidad del arreglo:  ");
	scanf("%d",&capacidad);
	
	cargar_arreglo(capacidad, arreglo);
	invertir(arreglo, capacidad);
	muestra_arreglo(capacidad, arreglo);
	
	
}





int cargar_arreglo(int capacidad, int arreglo[])
{
    int contador = 0;
    
    if((capacidad > MAXIMO_DOBLE ) || (capacidad < 1))
    {
        return ERROR_CARGA;
    }
    else
    {
        while(contador < capacidad)
        {
        printf("Ingrese un numero para la posicion '%d': ",contador);
        scanf("%d",&arreglo[contador]);//Guardo el valor ingresado en la posicion de contador
        contador++;//Incremento la posicion en 1
        } 
    }   
}




void muestra_arreglo(int capacidad, int arreglo[])
{
    int posicion = 0;
    
    while(posicion < capacidad)
    {
        printf("El numero en la posicion '%d' es: %d\n",posicion,arreglo[posicion]);//Muestro el valor de la "posicion" en el arreglo
        posicion++;//Incremento la posicion en 1
    }
}





int invertir(int arreglo[], int tamaño)
{
	int arreglo_aux[MAXIMO];
	int contador = 0;
	int contador_inverso = tamaño - 1;
	int retorno = 0;

	
	if(tamaño < 1)
	{
	
		retorno = ERROR;	
			
	}
	{
		
		while(contador < tamaño) //Esto copia el arreglo desde la ultima  a la primera posicion en un arreglo auxiliar
		{
		arreglo_aux[contador_inverso] = arreglo[contador];//Esto no anda, rasca memoria.
		contador++;
		contador_inverso--;
		}
	
		for(contador = 0; contador < tamaño; contador++)//Esto copia el arrelgo invertido en el arreglo de "verdad"
		{
			arreglo[contador] = arreglo_aux[contador];
		}
	}
	
	
	return retorno;
	
	
}


